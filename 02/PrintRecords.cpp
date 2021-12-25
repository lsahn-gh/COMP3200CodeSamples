#include <fstream>
#include <climits>
#include <iomanip>
#include "PrintRecords.h"

using namespace std;

namespace samples
{
	// @stream에서 데이터를 읽어와 Record 구조체에 저장하고 반환.
	// @bPrompt 값에 따라 도움말 출력.
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

	// @fileStream에 저장된 데이터를 line by line으로 읽어 화면에 출력.
	void DisplayRecords(fstream& fileStream)
	{
		// @fileStream의 offset을 0으로 초기화하여 읽을 준비.
		fileStream.seekg(0);

		string line;
		while (true)
		{
			// 아래의 조건이 만족할때까지 읽어서 'line' buffer에 저장
			// 1. eofbit 설정
			// 2. '\n' (delim) 만날때까지
			//    - 만나면 delim은 stream에서 버리고 line에 저장하지 않음
			// 3. failbit 설정
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
		// @outputStream offset을 마지막으로 설정하여 파일에 계속 추가하기
		// 위한 로직
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
			// '\n' 문자가 나타나면 해당 문자까지 또는 LLONG_MAX 만큼 discard
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
		// 자동으로 close 해준다. (instance의 destructor 호출, RAII 패턴)
		fileStream.close();
	}
}
