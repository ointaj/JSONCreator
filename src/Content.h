#include <string>
#include <algorithm>
#include "OutputSupport.h"

class Content
{
  private:
    std::string data{};

  public:
    ~Content() = default;
    Content(const Content& copy) = default;
    Content(Content&& move) = delete;
    Content& operator=(const Content& copy) = default; 
    Content& operator=(Content&& move) = default;

  public:
    Content() = default;
    explicit Content(std::size_t const& size)
    {
        this->data.reserve(size);
    }

    void ReserveData(std::size_t const& size);

    void AppendDataChar(const char value);

    void AppendData(std::string const& value);

    void ClearData();

    void RemoveOneCharFromString(const char delimter);

    bool Empty();

    std::string GetDataValue() const;

    void ReplaceData(std::pair<std::string, std::string> const& data);
};