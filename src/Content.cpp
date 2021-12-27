#include "Content.h"

bool JSONContent::Content::Empty()
{
    if (this->data.empty())
    {
        return true;
    }
    return false;
}

void JSONContent::Content::ReserveData(const std::size_t& size)
{
    this->data.reserve(size);
}

void JSONContent::Content::AppendDataChar(const char value)
{
    this->data.push_back(value);
}

void JSONContent::Content::AppendData(std::string const& value)
{
    this->data.append(value);
}

void JSONContent::Content::ClearData()
{
    this->data.clear();
}

std::string JSONContent::Content::GetDataValue() const
{
    return this->data;
}

void JSONContent::Content::RemoveOneCharFromString(const char delimter)
{
    if (this->Empty())
    {
        return;
    }
    
    this->data.erase(std::remove(data.begin(), data.end(), delimter), data.end());
}

void JSONContent::Content::ReplaceData(std::pair<std::string, std::string> const& data)
{
    if (this->Empty())
    {
        return;
    }

    if (data.second.empty() || data.first.empty())
    {
        return;
    }
    
    const auto findReplaceData = this->data.find(data.first);

    if (findReplaceData == std::string::npos)
    {
        return;
    }

    this->data = this->data.replace(findReplaceData, data.first.size(),
                                    data.second);
}
