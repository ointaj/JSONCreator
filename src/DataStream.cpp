#include "DataStream.h"
#include "OutputSupport.h"
#include <algorithm>
#include "DataType.h"

void DataStream::OpenFile()
{
    this->file.open(this->fileName);
}

void DataStream::CloseFile()
{
    this->file.close();
}

bool DataStream::IsFileNameOk()
{
    if (this->fileName.empty())
    {
        Output::Print("File Name is Empty ! \n");
        return false;
    }   

    const auto findDel = this->fileName.rfind(".");
    if (findDel != std::string::npos)
    {
        constexpr const auto ext = ".txt";
        std::string_view fileExt(this->fileName.c_str() + findDel,
                                 this->fileName.size() - findDel);
        if (fileExt == ext)
        {
            return true;
        }
    }
    return false;
}

bool DataStream::IsFileOpen()
{
    if (this->file.is_open())
    {
        return true;
    }
    Output::Print("File can't be open ! \n");
    return false;
}

static auto ReserveValue(std::string const& value, const char countValue)
{
    uint16_t count{};
    auto countCharValue = [&]()
    {   
        for (auto const& charValue : value)
        {
            if (charValue == countValue)
            {
                count++;
            }
        }
    };
    countCharValue();
    return count;
}

void DataStream::ReadFileContent()
{
    if (!this->IsFileNameOk())
    {
        return;
    }

    constexpr const auto appendNewLine = "/";
    std::string content{};
    if (this->IsFileOpen())
    {
        while(getline(this->file, this->fileContent))
        {
            Output::Print(fileContent, "\n");
            content.append(fileContent).append(appendNewLine);
        }
        
        this->fileContent.clear();
        if (content.empty())
        {
            Output::Print("Empty file ! \n");   
            return;
        }
        const auto reserveVal = ::ReserveValue(content, *appendNewLine);
        this->fileCont.reserve(reserveVal);
        this->FillVectorContent(std::move(content), appendNewLine);
    }
}

static auto GetDataType(std::string const& value)
{
    constexpr const auto strType = "str";
    constexpr const auto timeType = "time";

    const auto findDel = value.rfind("-");
    if (findDel != std::string::npos)
    {
        std::string_view compareValue(value.c_str() + findDel + 1,
                                      (value.size() - 2) - findDel);
        if (compareValue.compare(strType) == 0)
        {
            return DataType::Str;
        }
        else if (compareValue.compare(timeType) == 0)
        {
            return DataType::Time;
        }
    }

    return DataType::Trivial;
}

void DataStream::FillVectorContent(std::string&& value, const char* const delimeter)
{   
    auto findDel = value.find(delimeter);
    std::size_t pos{};

    while (findDel != std::string::npos)
    {
        auto subValue = value.substr(pos, findDel - pos);
        auto dataType  = ::GetDataType(subValue);
        this->fileCont.emplace_back(subValue, dataType);
        pos = findDel + 1;
        findDel = value.find(delimeter, pos);
    }
}
