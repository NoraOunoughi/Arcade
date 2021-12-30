#include <iostream>
#include "Core.hpp"
#include "IDisplay.hpp"
#include "Exception.hpp"

/**
*  \mainpage Arcade EPITECH
   \section Documentation
    Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of player scores.
    To be able to deal with the elements of your gaming plate-form  at  run-time,  your  graphics  libraries  and  your  games implemented as dynamic 
    libraries, loaded at run-time. Each GUI available for the program is used as a shared library that will be loaded and used dynamically by the main program.\n\n
    Dynamic libraries:\n
    The program uses dynamic libraries at run-time. This means that the progam uses the dlopen, dlclose, dlsym an ddl error functions to handle your dynamic libraries
    These dynamic libraries can be seen as plug-ins providing various capabilities to your main program. In NO CASE graphics libraries influence the game logic. Game libraries don't contain any information about screen rendering or low-level events. Your libraries (games and graphics) binaries (*.so) are in the./lib/directory at the root of your repository.\n\n
    Usage:\n
    The program takes a startup argument the graphics library to use initially. It's possible to change the graphics library at run-time.\n\n
    Language:  C++
*/

int main(int ac, char **av)
{
    if (ac < 2)
        std::cerr << "Missing argument: graph library" << std::endl;
    else if (ac > 2)
        std::cerr << "Too many arguments" << std::endl;
    else {
        arcade::Core core;
        try {
            core.loadLib(av[1], arcade::Core::Type::DISPLAY);
            core.init();
        }
        catch (arcade::Exception &e) {
            std::cerr << e.what() << std::endl; 
            return 84; 
        }
        return 0;
    }
    return 84;
}
