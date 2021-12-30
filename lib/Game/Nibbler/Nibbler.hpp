/**
 * \file Nibbler.hpp
 */

#ifndef NIBBLER_H
#define NIBBLER_H

#include <iostream>
#include <memory>
#include "IGame.hpp"

namespace game {
    class Nibbler : public arcade::IGame
    {
        public:
            Nibbler();
            ~Nibbler() = default;
            void getInput(const std::unique_ptr<arcade::Inputs> &i);
            std::vector<std::unique_ptr<arcade::Assets>> &getasset();
        private:
            void CreateMap();
            bool CheckCollision(arcade::Inputs::input input);
            std::tuple<int, int> getcharacter(char c);
            std::vector<std::unique_ptr<arcade::Assets>> _assets;
            std::vector<std::string> _map;
    };
};

#endif