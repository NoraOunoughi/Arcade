/*
** EPITECH PROJECT, 2021
** Inputs.hpp
** File description:
** Inputs header file
*/

/**
 * \file Inputs.hpp
 */

#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <string>

namespace arcade 
{
    class Inputs
    {
        public:
            enum class input { 
                CLOSE,
                RIGHT,
                LEFT,
                TOP,
                DOWN,
                ENTER,
                NONE,
                INPUT,
                Q,
                G,
                V,
                R
            };
            enum class type{
                KEYBOARD,
                MOUSE,
                NONE
            };
            Inputs(const arcade::Inputs::type &type, const arcade::Inputs::input &input = arcade::Inputs::input::NONE, const int xpos = -1, const int ypos = -1);
            ~Inputs() = default;
            /*! @brief Return input
            */
            const input &getInput();
            /*! @brief Return input's type
            */
            const type &getType();
            /*! @brief Return input's x position
            */
            const int &getXPos();
            /*! @brief Return input's y postition
            */
            const int &getYPos();
        private:
            type _type;
            input _input;
            const int _xPos;
            const int _yPos;


    };
};

#endif