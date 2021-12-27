#pragma once
#include <string>
#include <algorithm>
#include "OutputSupport.h"
#include "Separators.h"

namespace JSONContent
{
  class Content
  {
    private:
      JSONSeparotor::Separator sepator;
      std::string data{};

    public:
      Content(const Content& copy) = default;
      Content(Content&& move) = delete;
      Content& operator=(const Content& copy) = default; 
      Content& operator=(Content&& move) = delete;

    public:
      explicit Content() : sepator(data)
      {
        this->sepator.PutStartChar();
      }
      ~Content()
      {
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
}
