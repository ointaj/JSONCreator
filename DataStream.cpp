#include "DataStream.h"
#include "OutputSupport.h"

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

void DataStream::ReadFileContent()
{
    if (!this->IsFileNameOk())
    {
        return;
    }
    if (this->IsFileOpen())
    {
        while(getline(this->file, this->fileContent))
        {
            Output::Print(this->fileContent, "\n");
        }
    }
}

std::string DataStream::GetFileContent() const
{
    return this->fileContent;
}
