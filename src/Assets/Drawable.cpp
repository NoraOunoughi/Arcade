/**
 * \file Drawable.cpp
 */

#include "Drawable.hpp"
#include <tuple>
#include <string>

#include <iostream>

arcade::Drawable::Drawable(const std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, Draw_status type, const std::string path) : Assets(path, drawable), _position(pos), _size(size), _text(name), _type_draw(type) {}

arcade::Drawable::Drawable(const std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, const std::string path) : Assets(path, drawable), _position(pos), _size(size), _text(name) {}
arcade::Drawable::~Drawable(){}

std::tuple<int, int> arcade::Drawable::getPosition() const 
{
    return _position;
}

std::tuple<int, int> arcade::Drawable::getSize() const
{
    return _size;
}

std::string arcade::Drawable::getText() const
{
    return _text;
}

void arcade::Drawable::setPosition(const std::tuple<int, int> &new_pos)
{
    _position = new_pos;
}

void arcade::Drawable::setSize(const std::tuple<int, int> &new_size)
{
    _size = new_size;
}

void arcade::Drawable::setText(const std::string &new_text)
{
    _text = new_text;
}