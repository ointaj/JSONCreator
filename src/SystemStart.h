#include "RAIIPattern.h"
#include "DataStream.h"
#include "JSON.h"

constexpr const auto testValeu = 120;

class SystemStart
{
  private:
    DataAccess<DataStream> dataStream;
    JSON::Serialize jsonStream;
    
  public:
    SystemStart() = default;
    SystemStart(const SystemStart& copy) = delete;
    SystemStart(SystemStart&& move) = delete;

    SystemStart& operator=(const SystemStart& copy) = delete;
    SystemStart& operator=(SystemStart&& move) = delete;

  public:
    SystemStart(std::string&& _fileName)
        : dataStream(std::move(_fileName))
         {}
    
    void DoWork()
    {
      this->dataStream.GetFileData()->ReadFileContent();
    }
};
