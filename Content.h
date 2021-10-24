#include <string>
#include <algorithm>
#include "OutputSupport.h"


class Content
{
  private:
    std::string data;

  public:
    ~Content() = default;
    Content(const Content& copy) = default;
    Content(Content&& move) = delete;
    Content& operator=(const Content& copy) = delete; 
    Content& operator=(Content&& move) = delete;

  public:
    Content() = default;
    Content(const std::size_t& size)
    {
        this->data.reserve(size);
    }

    void ReserveData(const std::size_t& size);

    void AppendDataChar(const char value);

    void AppendData(const std::string &value);

    void ClearData();

    void RemoveOneCharFromString(const char delimter);

    bool Empty();

    std::string GetDataValue() const;
};