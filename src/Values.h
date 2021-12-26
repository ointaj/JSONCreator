#include <string>
#include "DataType.h"

class Valeus
{
  private:
    const std::string value;
    const DataType valueType;

  public:
    explicit Valeus(std::string const& v_value, DataType v_valueType)
        : value(v_value), valueType(v_valueType) {}
};