#include "Content.h"
#include "RAIIPattern.h"
constexpr const auto testValeu = 120;

class SystemStart
{
  private:
    Content content;
    DataAccess<DataStream> dataStream;
    
  public:
    SystemStart(std::string&& _fileName)
        : content(testValeu),
          dataStream(std::move(_fileName))
      {}
    
    void DoWork()
    {
       this->dataStream.GetFileData()->ReadFileContent();
    }
};
