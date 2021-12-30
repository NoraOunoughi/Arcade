/**
 * \file pucman.hpp
 */

#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include "Assets.hpp"
#include "Drawable.hpp"
#include "Score.hpp"
#include "Sound.hpp"
#include "Inputs.hpp"
#include "IGame.hpp"
#include <fstream>
#include <memory>


namespace game 
{    
    class Pacman : public arcade::IGame
    {
        public:
            /*! @brief setup the map from a .txt
            */
            void CreateMap();
            /*! @brief manage input of the game
                @param input class input
            */
            void getInput(const std::unique_ptr<arcade::Inputs> &input);
            /*! @brief check collision of the player 
                @param input class input enum to get input type
            */
            bool CheckCollision(arcade::Inputs::input input);
            /*! @brief lose conditions 
            */
            void EndGame();
            /*! @brief move the phantom
            */
            void moveEnemy();
            /*! @brief check collision of the phatom
                @param c character of the phantom within the map
                @param y iterator of the phantom place in the list _asset
            */
            bool CheckCollisionEnemy(char c, long unsigned int y);
            /*! @brief return the list of asset
            */
            std::vector<std::unique_ptr<arcade::Assets>> &getasset();
            /*! @brief return the position of a character in the map
                @param c character to be found in the map 
            */
            std::tuple<int, int> getcharacter(char c);
            /*! @brief add a new element in the list
                @param name name of the asset 
                @param pos position of the asset
                @param size size of the asset
                @param path filepath of the asset
            */
            void setlist(std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path);
            Pacman();
            ~Pacman();
        private:
            int _score;
            bool _end;
            std::vector<std::unique_ptr<arcade::Assets>> _assets;
            std::vector<std::string> _map;
    };
}
#endif
