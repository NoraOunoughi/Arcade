/**
 * \file Dynamic.cpp
 */

#include "Dynamic.hpp"
#include <string>
#include <tuple>

arcade::Dynamic::Dynamic(std::tuple<int, int> dir, bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path) : Collidable(coll, name, pos, size, path), _direction(dir){}

arcade::Dynamic::~Dynamic(){}

std::tuple<int, int> arcade::Dynamic::getDirection() const
{
    return _direction;
}

void arcade::Dynamic::setDirection(const std::tuple<int, int> &new_dir)
{
    _direction = new_dir;
} 