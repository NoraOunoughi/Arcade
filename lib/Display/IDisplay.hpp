/*
** EPITECH PROJECT, 2021
** IDisplay.hpp
** File description:
** IDisplay header file
*/

/**
 * \file IDisplay.hpp
 */

#ifndef IDisplay_HPP
#define IDisplay_HPP

#include <string>
#include <memory>
#include <vector>
#include "Inputs.hpp"
#include "Assets.hpp"

namespace arcade {
    class IDisplay
    {
        public:
            virtual ~IDisplay() = default;
            
            /*! @brief Create the window
                @param width window's width
                @param height window's height
                @param name window's name
            */
            virtual void init(int width, int height, const std::string &name) = 0;

            /*! @brief Display main menu's sprites
                @param libGraph list of graph library name
                @param libGame list of game library name
            */
            virtual void Menu(const std::string &libGraph, const std::string &libGame) = 0;

            /*! @brief Display game's sprites
                @param assets list of assets send by the game library
            */
            virtual void SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets) = 0;

            /*! @brief Events handling */
            virtual std::unique_ptr<arcade::Inputs> event() = 0;

            /*! @brief Destroy all components of actual game  */
            virtual void destroyGame() = 0;
            virtual void display() = 0;
            virtual void clear() = 0;
    };

    typedef IDisplay *entrypoint_t();
    typedef void destroy_t(IDisplay *);
};
#endif
