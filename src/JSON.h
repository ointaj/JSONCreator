#include "Content.h"
#include <memory>

namespace JSON
{
    class Serialize
    {
      private:
        Content* content = nullptr;

      public:
        Serialize() = default;
        Serialize(const Serialize&) = default;
        Serialize(Serialize&&) = default;
        Serialize& operator=(const Serialize&) = default;
        Serialize& operator=(Serialize&&) = default;

      public:
        explicit Serialize(Content* v_con) : content(v_con)
            {}

        auto AddedValue(const char* const destination, std::string const& value)
        {
        }
    };
};

