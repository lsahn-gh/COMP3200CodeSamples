#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <random>
#include <chrono>
#include <condition_variable>

#include "ProducerConsumerExample.h"

using namespace std;

namespace samples
{

static mutex sMutex;
static condition_variable sEvent;
constexpr size_t QUEUE_LIMIT = 1024;
static queue<int> sQueue;

random_device rd;  // H/W-based seed
mt19937 gen(rd()); // init Mersenne Twister engine
uniform_int_distribution<> sRandomRange(1, QUEUE_LIMIT);

void Producer()
{
    vector<int> vDev;

    while (true)
    {
        {
            unique_lock<mutex> lock(sMutex);
            if (sQueue.size() >= QUEUE_LIMIT)
            {
                // skip if queue reached to the limit
                continue;
            }
        }

        for (int i = 0; i < sRandomRange(gen); i++)
        {
            vDev.push_back(static_cast<int>(sRandomRange(gen)));
        }

        {
            unique_lock<mutex> lock(sMutex);
            for (int elem : vDev)
            {
                sQueue.push(elem);
            }

            sEvent.notify_one();
        }

        vDev.clear();
    }
}

void Consumer()
{
    vector<int> buffer;
    auto PrintBuffer = [&buffer] () {
        cout << "--------- buffer ----------" << endl;
        for (int elem : buffer) {
            cout << elem << " ";
        }
        cout << endl;
    };

    while (true)
    {
        {
            unique_lock<mutex> lock(sMutex);
            sEvent.wait(lock, []
                        { return !sQueue.empty(); });

            while (!sQueue.empty())
            {
                int value = sQueue.front();
                buffer.push_back(value);
                sQueue.pop();
            }
        }

        PrintBuffer();

        buffer.clear();
    }

}

void ProducerConsumerExample()
{
    thread producer(Producer);
    thread consumer(Consumer);

    producer.join();
    consumer.join();
}

} // samples