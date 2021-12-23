#pragma once

#include <iostream>
#include <string>

struct LsrRecord
{
    std::string FirstName;
    std::string LastName;
    std::string StudentID;
    std::string Score;
};

namespace lsr
{
    LsrRecord LsrReadRecord(std::istream& stream, bool bPrompt);

    void LsrWriteFileRecord(std::fstream& outputStream, const LsrRecord& record);

    void LsrDisplayRecords(std::fstream& fileStream);

    void LsrManageRecordsExample();
}