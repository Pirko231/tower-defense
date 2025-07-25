#include "program.hpp"

int main()
{
    std::srand(std::time(0));
    Program program;
    while (program.running())
    {
        program.handleEvents();
        program.update();
        program.display();
    }
}