#pragma once
#include <fstream>
#include <string_view>
#include <vector>
#include "Values.h"

class DataStream
{
  private:
    std::fstream file;
    std::string fileName;
    std::string fileContent;
    std::vector<Valeus> fileCont{};
    
  public:
    DataStream() = default;
    DataStream(const DataStream& copy) = default;
    DataStream(DataStream&& move) = default;
    DataStream& operator= (const DataStream&) = default;
    DataStream& operator= (DataStream&&) = default;

  public:
    explicit DataStream(std::string&& _fileName)
         : fileName(std::move(_fileName))
      {}

    void OpenFile();

    void CloseFile();

    bool IsFileNameOk();

    bool IsFileOpen();

    void ReadFileContent();

    void FillVectorContent(std::string&& value, const char* const delimeter);

    auto GetFileContent() const
    {
      return this->fileCont;
    }
};
