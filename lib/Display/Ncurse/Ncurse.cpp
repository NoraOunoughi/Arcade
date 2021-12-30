/**
 * \file Ncurse.cpp
 */

#include <vector>
#include "Ncurse.hpp"

graph::Ncurse::~Ncurse()
{
    delwin(this->_window);
    endwin();
}

void graph::Ncurse::init(int width, int height, const std::string &name)
{
    static_cast<void>(name);
    initscr();
    this->_window = newwin(width, height, 0, 0);
}

void graph::Ncurse::SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets)
{
    static_cast<void>(assets);
}

void graph::Ncurse::Menu(const std::string &libGraph, const std::string &libGame)
{
    static_cast<void>(libGraph);
    static_cast<void>(libGame);
}

std::unique_ptr<arcade::Inputs> graph::Ncurse::event()
{
    int c = wgetch(this->_window);
		switch(c) {	
            case 'q': return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::CLOSE);
            case 'v': return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::V);
            default: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::NONE);
        }
    return std::make_unique<arcade::Inputs>(arcade::Inputs::type::NONE);
}

void graph::Ncurse::destroyGame()
{

}

void graph::Ncurse::display()
{
    refresh();
}

void graph::Ncurse::clear()
{

}

extern "C" arcade::IDisplay *entryPoint()
{
    return new graph::Ncurse;
};

extern "C" void destroy(arcade::IDisplay *display)
{
    delete display;
}