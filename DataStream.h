#include <fstream>
#include <string_view>

class DataStream
{
  private:
    std::fstream file;
    std::string fileName;
    std::string fileContent;
    
  public:
    explicit DataStream(std::string&& _fileName)
        : fileName(std::move(_fileName))
    {}

  public:
    void OpenFile();

    void CloseFile();

    bool IsFileNameOk();

    bool IsFileOpen();

    void ReadFileContent();

    std::string GetFileContent() const;
};
