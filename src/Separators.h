#pragma once
#include <string>

constexpr const auto StartSepartor = "{";
constexpr const auto EndSepartor = "}";

namespace JSONSeparotor
{
    class Separator
    {
        private:
            std::string& dataValue;
        public:
            explicit Separator(std::string& v_dataValue) : dataValue(v_dataValue) {}
            
            void PutStartChar()
            {
                this->dataValue.append(StartSepartor);
            }

            void PutEndChar()
            {
                this->dataValue.append(EndSepartor);
            }
    };
};