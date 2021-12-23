#pragma once

#include <iostream>
#include <string>

// 4개의 string 타입을 가지는 멤버 정의
// FirstName, LastName, StudentID, Score
struct Record
{
	std::string FirstName;
	std::string LastName;
	std::string StudentID;
	std::string Score;
};

namespace samples
{
	Record ReadRecord(std::istream& stream, bool bPrompt);

	void WriteFileRecord(std::fstream& outputStream, const Record& record);

	void DisplayRecords(std::fstream& fileStream);

	void ManageRecordsExample();
}
