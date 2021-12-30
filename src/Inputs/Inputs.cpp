/*
** EPITECH PROJECT, 2021
** Inputs.cpp
** File description:
** Inputs functions
*/

/**
 * \file Inputs.cpp
 */

#include "Inputs.hpp"

arcade::Inputs::Inputs(const arcade::Inputs::type &type, const arcade::Inputs::input &input, const int xpos, const int ypos) : _type(type), _input(input), _xPos(xpos), _yPos(ypos)
{

}

const arcade::Inputs::input &arcade::Inputs::getInput()
{
    return this->_input;
}

const arcade::Inputs::type &arcade::Inputs::getType()
{
    return this->_type;
}

const int &arcade::Inputs::getXPos()
{
    return this->_xPos;
}

const int &arcade::Inputs::getYPos()
{
    return this->_yPos;
}