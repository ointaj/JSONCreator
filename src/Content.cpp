#include "Content.h"

bool Content::Empty()
{
    if(this->data.empty())
    {
        Output::Print("Data are empty ! \n");
        return true;
    }
    return false;
}

void Content::ReserveData(const std::size_t& size)
{
    this->data.reserve(size);
}

void Content::AppendDataChar(const char value)
{
    this->data.push_back(value);
}

void Content::AppendData(std::string const& value)
{
    this->data.append(value);
}

void Content::ClearData()
{
    this->data.clear();
}

std::string Content::GetDataValue() const
{
    return this->data;
}

void Content::RemoveOneCharFromString(const char delimter)
{
    if (this->Empty())
    {
        return;
    }
    
    this->data.erase(std::remove(data.begin(), data.end(), delimter), data.end());
}

void Content::ReplaceData(std::pair<std::string, std::string> const& data)
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
        Output::Print("Didnt find: ", data.first, "!\n");
        return;
    }

    this->data = this->data.replace(findReplaceData, data.first.size(),
                                    data.second);
}
