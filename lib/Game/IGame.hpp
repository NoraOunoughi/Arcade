/**
 * \file IGame.hpp
 */

#ifndef IGAME_H
#define IGAME_H

#include <memory>
#include "../../src/Assets/Assets.hpp"
#include "../../src/Inputs/Inputs.hpp"
#include <vector>

namespace arcade {
    class IGame
    {
        public:
            virtual ~IGame() = default;
            /*! @brief Return the list of assets created by the game
            */
            virtual std::vector<std::unique_ptr<arcade::Assets>> &getasset() = 0;
            /*! @brief Get the input sent by the library
                @param input class input 
            */
            virtual void getInput(const std::unique_ptr<arcade::Inputs> &input) = 0;
    };
        typedef IGame *entrypointGame_t();
        typedef void destroyGame_t(IGame *);
};

#endif
