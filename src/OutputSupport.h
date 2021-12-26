#include <iostream>
#include <optional>
#include <utility>

class Output
{
 public:
    Output() = default;
    ~Output() = default;
    Output(const Output& copy) = delete;
    Output(Output&& move) = delete;
    Output& operator=(const Output& copy) = delete; 
    Output& operator=(Output&& move) = delete; 
    
 public:
    template<class ... Argv>
    static void Print(Argv&&... argc)
    {
        ((std::cout << std::forward<Argv>(argc)), ...);
    }
};
