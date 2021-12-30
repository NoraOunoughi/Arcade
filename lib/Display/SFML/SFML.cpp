/**
 * \file SFML.cpp
 */

#include <array>
#include <iostream>
#include "SFML.hpp"
#include "Assets.hpp"

graph::SFML::SFML() : _isPlaying(false)
{
    this->_font.loadFromFile("lib/Display/SFML/font.ttf");
    this->_playerText.setFont(this->_font);
    this->_playerText.setCharacterSize(20);
    this->_playerText.setFillColor(sf::Color::White);
    this->_playerText.setPosition(230, 320);
    this->_music.setLoop(true);
}

graph::SFML::~SFML()
{
    this->_window.close();
}

void graph::SFML::init(int width, int height, const std::string &name)
{
    createWindow(width, height, name);
}

std::unique_ptr<arcade::Inputs> graph::SFML::event()
{
    sf::Event event;

    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::MOUSE, arcade::Inputs::input::CLOSE);
    
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::RIGHT);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::LEFT);
         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::TOP);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::DOWN);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::ENTER);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::G);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V)
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::V);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
            this->_isPlaying = false;
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::R);
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
            this->_music.stop();
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::Q);
        }
        else if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && !_playerInput.isEmpty())
                _playerInput.erase(_playerInput.getSize() - 1, 1);
            else if (event.text.unicode < 128 && event.text.unicode != '\b')
            _playerInput += event.text.unicode;
            _playerText.setString(_playerInput);
        }
        break;
    }
    return std::make_unique<arcade::Inputs>(arcade::Inputs::type::NONE);
}

void graph::SFML::SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets)
{
    int end = assets.size();
    std::string score = std::to_string(assets[1]->getScore());

    if (this->_isPlaying == false) {
        this->_music.openFromFile(assets[0]->GetFilePath());
        this->_music.play();
        this->_isPlaying = true;
    }
    clear();
    for (int it = 2; it < end; it++)
        SpriteCreate(assets[it]->GetFilePath(), assets[it]->getPosition());
    TextCreate("Score: ", 20, 10, 10, sf::Color::White);
    TextCreate(score, 20, 90, 10, sf::Color::White);
    display();
}

void graph::SFML::Menu(const std::string &libGraph, const std::string &libGame)
{
    clear();
    SpriteCreate("./bg.png", std::tuple<int, int>(-25, 0));
    TextCreate(libGame, 22, 320, 210, sf::Color::Red);
    TextCreate(libGraph, 22, 350, 280, sf::Color::Red);
    TextCreate("Press g : change the game", 20, 215, 180, sf::Color::White);
    TextCreate("Press v : change graph library", 20, 210, 240, sf::Color::White);
    TextCreate("Enter your name :", 20, 210, 300, sf::Color::White);
    TextCreate("Press enter to play", 28, 220, 400, sf::Color::White);
    this->_window.draw(this->_playerText);
    display();
}

void graph::SFML::destroyGame()
{
    this->_isPlaying = false;
}

void graph::SFML::TextCreate(const std::string &name, const int size, const int x, const int y, sf::Color color)
{
    sf::Text text;

    text.setPosition(x, y);
    text.setFont(this->_font);
    text.setString(name);
    text.setCharacterSize(size);
    text.setFillColor(color);
    this->_window.draw(text);
}

const sf::RectangleShape graph::SFML::createButton(const int x, const int y)
{
    sf::RectangleShape button(sf::Vector2f(150, 50));
    button.setPosition(x, y);
    return button;
}

void graph::SFML::setPosition(Sprite sprite, std::tuple<int, int> position)
{
    sprite.sprite.setPosition(std::get<0>(position), std::get<1>(position));
}

void graph::SFML::createWindow(int width, int height, const std::string &name)
{
    _window.create(sf::VideoMode(width, height), name, sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(20);
}

void graph::SFML::SpriteCreate(const std::string &path, std::tuple<int, int> position)
{
    sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setPosition(std::get<0>(position), std::get<1>(position));
    this->_window.draw(sprite);
}

void graph::SFML::display()
{
    this->_window.display();
}

void graph::SFML::clear()
{
    this->_window.clear(sf::Color::Black);
}

extern "C" arcade::IDisplay *entryPoint()
{
    return new graph::SFML;
};

extern "C" void destroy(arcade::IDisplay *display)
{
    delete display;
}
