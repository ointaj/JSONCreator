#include "SystemStart.h"

int main(int argc, char **argv)
{
    Output::Print("Welcome ! \n");
    std::unique_ptr<SystemStart> system 
            = std::make_unique<SystemStart>(std::move(argv[1]));
    system->DoWork();
    return 0;
}