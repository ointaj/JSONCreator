#include <fstream>
#include <string_view>
#include <vector>

class DataStream
{
  private:
    std::fstream file;
    std::string fileName;
    std::string fileContent;
    std::vector<std::string> fileCont;
    
  public:
    DataStream() = default;
    DataStream(const DataStream& copy) = default;
    DataStream(DataStream&& move) = default;
    DataStream& operator= (const DataStream&) = default;
    DataStream& operator= (DataStream&&) = default;

  public:
    DataStream(std::string&& _fileName)
         : fileName(std::move(_fileName))
      {}

    void OpenFile();

    void CloseFile();

    bool IsFileNameOk();

    bool IsFileOpen();

    void ReadFileContent();

    std::vector<std::string> GetFileContent() const;
};
