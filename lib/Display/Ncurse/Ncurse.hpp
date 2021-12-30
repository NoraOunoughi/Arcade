/*
** EPITECH PROJECT, 2021
** Ncurse
** File description:
** Ncurse
*/

/**
 * \file Ncurse.hpp
 */

#ifndef NCURSE_HPP
#define NCURSE_HPP

#include <ncurses.h>
#include "IDisplay.hpp"

namespace graph
{
    class Ncurse : public arcade::IDisplay
    {
    public:
        Ncurse() = default;
        ~Ncurse();
        void init(int width, int height, const std::string &name);
        void Menu(const std::string &libGraph, const std::string &libGame);
        void SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets);
        std::unique_ptr<arcade::Inputs> event();
        void destroyGame();
        void display();
        void clear();
    private:
        WINDOW * _window;
    };
}

#endif