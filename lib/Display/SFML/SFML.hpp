/*
** EPITECH PROJECT, 2021
** SFML
** File description:
** SFML
*/

/**
 * \file SFML.hpp
 */

#ifndef SFML_HPP
#define SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "IDisplay.hpp"

namespace graph
{
    typedef struct sprite {
        sf::Texture texture;
        sf::Sprite sprite;
        sf::IntRect rect;
    } Sprite;
    class SFML : public arcade::IDisplay
    {
    public:
        SFML();
        ~SFML();
        void init(int width, int height, const std::string &name);
        void Menu(const std::string &libGraph, const std::string &libGame);
        void SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets);
        std::unique_ptr<arcade::Inputs> event();
        void destroyGame();
        void display();
        void clear();
    private:
        std::vector<sf::RectangleShape> mainMenuButtons();
        void TextCreate(const std::string &name, const int size, const int x, const int y, sf::Color color);
        const sf::RectangleShape createButton(const int x, const int y);
        void setPosition(Sprite sprite, std::tuple<int, int> position);
        void createWindow(int width, int height, const std::string &name);
        void SpriteCreate(const std::string &path, std::tuple<int, int> pos);
        void setPlaying();
        sf::RenderWindow _window;
        sf::Font _font;
        std::vector<Sprite> _sprite;
        sf::String _playerInput;
        sf::Text _playerText;
        sf::Music _music;
        bool _isPlaying;
    };
}

#endif
