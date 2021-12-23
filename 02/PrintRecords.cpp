#include <fstream>
#include <climits>
#include <iomanip>
#include "PrintRecords.h"

using namespace std;

namespace samples
{
	// @stream 으로부터 데이터를 읽어와 Record 구조체에 저장하고 반환.
	// @bPrompt 값에 따라 입력값을 화면에 출력.
	Record ReadRecord(istream& stream, bool bPrompt)
	{
		Record record;

		if (bPrompt)
		{
			cout << "First name: ";
		}
		stream >> record.FirstName;

		if (bPrompt)
		{
			cout << "Last name: ";
		}
		stream >> record.LastName;

		if (bPrompt)
		{
			cout << "Student ID: ";
		}
		stream >> record.StudentID;

		if (bPrompt)
		{
			cout << "Score:  ";
		}
		stream >> record.Score;

		return record;
	}

	// @fileStream으로 입력받은 데이터들을 line by line으로
	// 읽어와서 화면에 출력.
	void DisplayRecords(fstream& fileStream)
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

	// @record의 결과 값을 @outputStream 에 출력
	void WriteFileRecord(fstream& outputStream, const Record& record)
	{
		// @outputStream의 seek를 파일의 마지막으로 설정
		// 마지막에 append 하기 위함임
		outputStream.seekp(0, ios_base::end);

		// FirstName LastName StudentID Score '\n' 으로 저장.
		// endl을 사용하면 flush 까지 수행해줌.
		outputStream << record.FirstName << " "
			<< record.LastName << " "
			<< record.StudentID << " "
			<< record.Score << endl;

		// 확실하게 하기 위해 flush() 호출.
		outputStream.flush();
	}

	void ManageRecordsExample()
	{
		cout << "+------------------------------+" << endl;
		cout << "|    Manage Records Example    |" << endl;
		cout << "+------------------------------+" << endl;

		// fstream 하나 만들고 studentRecords.dat 파일을 오픈한다.
		// 이때 해당 스트림은 read/write가 가능하도록 플래그 설정
		fstream fileStream;
		fileStream.open("studentRecords.dat", ios_base::in | ios_base::out);

		// bExit 플래그가 true가 될 때까지 반복
		bool bExit = false;
		while (!bExit)
		{
			char command = ' ';

			cout << "a: add" << endl
				<< "d: display" << endl
				<< "x: exit" << endl;

			// a/d/x 명령어 입력받는다.
			// @command가 char 타입이기 때문에 문자 1개만 받아오게 되는데
			// 이때 ignore를 통해 뒤에 딸려오는 문자열을 모두 삭제한다.
			// 예) append, abort 등 이러한 문자열 모두 a로 입력받도록 설계
			cin >> command;
			cin.ignore(LLONG_MAX, '\n');

			switch (command)
			{
			case 'a':
			{
				// cin에서 입력받아 @fileStream에 저장
				Record record = ReadRecord(cin, true);
				WriteFileRecord(fileStream, record);
				break;
			}
			case 'd':
			{
				// @fileStream에 저장된 내용을 화면에 출력
				DisplayRecords(fileStream);
				break;
			}
			case 'x':
			{
				// 종료
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

		// @fileStream 종료.
		// close 하지 않더라도 fstream이 생성된 scope에서 나가면
		// 자동으로 close 해준다. (개체/클래스의 소멸자 호출)
		fileStream.close();
	}
}