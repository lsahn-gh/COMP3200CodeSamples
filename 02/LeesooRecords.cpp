#include <fstream>
#include <climits>
#include "LeesooRecords.h"

using namespace std;

namespace lsr
{
    LsrRecord LsrReadRecord(istream& stream, bool bPrompt)
    {
        LsrRecord record;

        if (bPrompt)
        {
            cout << "FirstName: ";
        }
        stream >> record.FirstName;

        if (bPrompt)
        {
            cout << "LastName: ";
        }
        stream >> record.LastName;

        if (bPrompt)
        {
            cout << "StudentID: ";
        }
        stream >> record.StudentID;

        if (bPrompt)
        {
            cout << "Score: ";
        }
        stream >> record.Score;

        return record;
    }

    void LsrWriteFileRecord(std::fstream& outputStream, const LsrRecord& record)
    {
        outputStream.seekp(0, ios_base::end);

        outputStream << record.FirstName << " "
            << record.LastName << " "
            << record.StudentID << " "
            << record.Score << endl;
        
        outputStream.flush();
    }

    void LsrDisplayRecords(std::fstream& fileStream)
    {
        fileStream.seekg(0);

        string line;
        while (true)
        {
            getline(fileStream, line);
            if (fileStream.eof())
            {
                fileStream.clear();
                break;
            }
            cout << line << endl;
        }
    }

    void LsrManageRecordsExample()
    {
        cout << "+------------------------------+" << endl;
        cout << "|  Lsr Manage Records Example  |" << endl;
		cout << "+------------------------------+" << endl;

        fstream fileStream;
        fileStream.open("studentRecords.dat", ios_base::in | ios_base::out);

        bool bExit = false;
        while (!bExit)
        {
            char command = ' ';

            cout << "a: add" << endl
                << "d: display" << endl
                << "x: exit" << endl;
            
            cin >> command;
            cin.ignore(LLONG_MAX, '\n');

            switch (command)
            {
            case 'a':
            {
                LsrRecord record = LsrReadRecord(cin, true);
                LsrWriteFileRecord(fileStream, record);
                break;
            }
            case 'd':
            {
                LsrDisplayRecords(fileStream);
                break;
            }
            case 'x':
            {
                bExit = true;
                break;
            }
            default:
            {
                cout << "invalid input" << endl;
                break;
            }
            }
        }

        fileStream.close();
    }
}