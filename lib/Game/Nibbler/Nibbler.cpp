/**
 * \file Nibbler.cpp
 */

#include <fstream>
#include "Nibbler.hpp"
#include "Drawable.hpp"
#include "Sound.hpp"

game::Nibbler::Nibbler()
{
    _assets.emplace_back(std::make_unique<arcade::Sound>("lib/Game/Nibbler/src/nibbler_music.ogg"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("map", std::tuple<int, int>{1, 4}, std::tuple<int, int>{750, 600}, "lib/Game/Nibbler/src/map.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("player", std::tuple<int, int>{360, 480}, std::tuple<int, int>{10, 10}, "lib/Game/Nibbler/src/player.png"));
    CreateMap();
}

void game::Nibbler::CreateMap()
{
    int buff = 0;
    std::tuple<int, int> coord {0, 0};
    std::string line;
    std::ifstream fl("lib/Game/Nibbler/src/map.txt");

    if (fl.is_open()) {
        for (; getline(fl, line); std::get<1>(coord) += 30) {
            _map.push_back(line);
            for (buff = 0, std::get<0>(coord) = 0; buff <= 25; buff++, std::get<0>(coord) += 30) {
                if (line[buff] == '#')
                    _assets.emplace_back(std::make_unique<arcade::Drawable>("wall", coord, std::tuple<int, int>{30, 30}, "lib/Game/Nibbler/src/wall.png"));
            }
        }
        _map[16][12] = 'G';
        _map[10][12] = 'P';
        _map[10][11] = 'I';
        _map[10][13] = 'C';
        _map[11][12] = 'B';
    } else {std::cout << "OOOOOOOOO";}
}

bool game::Nibbler::CheckCollision(arcade::Inputs::input input)
{
    int x = std::get<0>(getcharacter('G'));
    int y = std::get<1>(getcharacter('G'));

    if (input == arcade::Inputs::input::LEFT) {
        if (_map[x][y - 1] != '#')  {
            if (_map[x][y - 1] == '.') {
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{(y - 1) * 30, x * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x][y - 1] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::RIGHT) {
        if (_map[x][y + 1] != '#') {
            if (_map[x][y + 1] == '.') {
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{(y + 1) * 30, x * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x][y + 1] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::TOP) {
        if (_map[x - 1][y] != '#') {
            if (_map[x - 1][y] == '.') {
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{y * 30, (x - 1) * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x - 1][y] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::DOWN) {
        if (_map[x + 1][y] != '#') {
            if (_map[x + 1][y] == '.') {
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{y * 30, (x + 1) * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x + 1][y] = 'G';
            return false;
        } else return true;
    }
    return true;
}

void game::Nibbler::getInput(const std::unique_ptr<arcade::Inputs> &i)
{
    static arcade::Inputs::input direction = arcade::Inputs::input::NONE;
    for (long unsigned int y = 0; y < _assets.size(); y++)
        if (_assets[y]->getText() == "player") {
            std::tuple<int, int> new_pos = _assets[y]->getPosition();
            if (i->getInput() ==  arcade::Inputs::input::LEFT) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::LEFT) == false) {
                    direction = arcade::Inputs::input::LEFT;
                    std::get<0>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Nibbler/src/player.png");
                    return;
                }
            } if (i->getInput() ==  arcade::Inputs::input::RIGHT) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::RIGHT) == false) {
                    direction = arcade::Inputs::input::RIGHT;
                    std::get<0>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Nibbler/src/player.png");
                    return;
                }
            } if (i->getInput() ==  arcade::Inputs::input::TOP) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::TOP) == false) {
                    direction = arcade::Inputs::input::TOP;
                    std::get<1>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Nibbler/src/player.png");
                    return;
                }
            } if (i->getInput() ==  arcade::Inputs::input::DOWN)
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::DOWN) == false) {
                    direction = arcade::Inputs::input::DOWN;
                    std::get<1>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Nibbler/src/player.png");
                    return;
                }
            if (direction == arcade::Inputs::input::LEFT) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::LEFT) == false) {
                    std::get<0>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::RIGHT) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::RIGHT) == false) {
                    std::get<0>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::TOP) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::TOP) == false) {
                    std::get<1>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::DOWN) {
                if (game::Nibbler::CheckCollision(arcade::Inputs::input::DOWN) == false) {
                    std::get<1>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                }
            }
        }
}

std::tuple<int, int> game::Nibbler::getcharacter(char c)
{
    long unsigned int i = 0;
    int y = 0; 
    for (i = 0; i < _map.size(); i++){
        for (y = 0; y <= 25; y++)
            if (_map[i][y] == c)
                return std::tuple<int, int>{i, y};
    }
    return std::tuple<int, int> {84, 84};
}

std::vector<std::unique_ptr<arcade::Assets>> &game::Nibbler::getasset()
{
    return _assets;
}

extern "C" arcade::IGame *entryPoint()
{
    return new game::Nibbler;
};

extern "C" void destroy(arcade::IGame *game)
{
    delete game;
}