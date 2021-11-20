#include <algorithm>

namespace opt
{
   template<class T>
   class optional
   {
       public:
        using ObjType = T;
        ObjType obj;
        bool initObj = false;

       public:
        optional() : obj {}
        {
            this->initObj = false;
        }
        
        template<class ... Arg>
        optional(Arg&& ...args) : obj {std::forward<Arg>(args)...}
        {
            this->initObj = true;
        }

        optional& emplace(optional<T>&& value)
        {
            if (value.IsInitialized())
            {
                this->obj = std::move(value.obj);
                value.obj = {};
                this->initObj = true;
            }
            return *this;
        }

        optional& emplace(const optional<T>& value)
        {
            if (value.IsInitialized())
            {
                this->obj = value.obj;
                this->initObj = true;
            }
            return *this;
        }

        template<class ... Arg>
        optional& emplace(Arg&& ... args)
        {
            this->obj = {std::forward<Arg>(args)...};
            this->initObj = true;
            return *this;
        }

        optional& value_or(T&& move) const
        {
            if (!this->IsInitialized())
            {
                this->obj = std::move(move);
                this->initObj = true;
            } 
            return *this;
        }

        ObjType& operator*() const
        {
            return obj;
        }

        ObjType* operator->()
        {
            return &obj;
        }

        bool IsInitialized() const
        {
            return (initObj == true);
        }
    };
}

