#include "Content.h"
#include "RAIIPattern.h"
#include "optional.h"

constexpr const auto testValeu = 120;

class SystemStart
{
  private:
    Content content;
    DataAccess<DataStream> dataStream;
    
  public:
    SystemStart() = default;
  

    SystemStart(const SystemStart& copy) = default;
    SystemStart(SystemStart&& move) = default;

    SystemStart& operator=(const SystemStart& copy) = default;
    SystemStart& operator=(SystemStart&& move)
    {
      this->content = std::move(move.content);
      this->dataStream = std::move(move.dataStream);
      return *this;
    }

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
