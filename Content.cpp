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

void Content::AppendData(const std::string& value)
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
