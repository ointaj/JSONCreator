#include "SystemStart.h"

int main(int argc, char **argv)
{
    Output::Print("Welcome ! \n");
    opt::optional<SystemStart> system(std::move(argv[1]));
    system->DoWork();
    return 0;
}