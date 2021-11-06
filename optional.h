#include <algorithm>

enum class FlagException
{
    Ok,
    NotInit
};

class OptionalExceipton
{
  public:
    FlagException exception = FlagException::Ok;
  public:
    OptionalExceipton() = default;
    OptionalExceipton(FlagException _exception) : exception (_exception)
        {}
};

namespace opt
{
    template <class Obj>
    class optional : public OptionalExceipton, public Obj
    {
        public:
            optional() : OptionalExceipton{}, Obj{}
                {}
            
            template<class ...Argv>
            optional(Argv&& ...argv) : OptionalExceipton{}, Obj {std::forward<Argv>(argv)...}
                {}
            
            optional(FlagException _flag) : OptionalExceipton(_flag), Obj{}
                {}
            
            auto emplace()
            {
                return opt::optional<Obj>();
            }

            auto IsInitialized()
            {
                return this->exception != FlagException::NotInit;
            }

        public:
            optional(const optional&) = default;
            optional(optional&&) = default;
            optional& operator= (const optional&) = default;
            optional& operator= (optional&&) = default;
    };
}

