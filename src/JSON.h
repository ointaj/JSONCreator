#include "Content.h"
#include <memory>
#include "Values.h"

namespace JSON
{
    class Serialize
    {
      private:
        std::unique_ptr<JSONContent::Content> content = nullptr;
        std::vector<Valeus> dataFromFile{};

      public:
        Serialize(const Serialize&) = default;
        Serialize(Serialize&&) = default;
        Serialize& operator=(const Serialize&) = default;
        Serialize& operator=(Serialize&&) = default;

      public:
        explicit Serialize() : content (std::make_unique<JSONContent::Content>())
            {}

        void SetDataFromFile(std::vector<Valeus> && _dataFromFile)
        {
          this->dataFromFile = std::move(_dataFromFile);
        }

        ~Serialize()
        {
        }

        auto AddedValue(const char* const destination, std::string const& value)
        {
            this->content->AppendData("Oli");
        }
    };
};

