/*
** EPITECH PROJECT, 2021
** Menu
** File description:
** Menu
*/

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include <SFML/Graphics.hpp>
#include <vector>

namespace graph
{
    class Menu
    {
        public:
            Menu() = default;
            ~Menu() = default;
            std::vector<sf::RectangleShape> createButtons();
            sf::RectangleShape createButton(const int x, const int y);
    };
};

#endif