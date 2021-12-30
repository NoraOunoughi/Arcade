/**
 * \file Collodable.cpp
 */

#include "Collidable.hpp"
#include <string>

arcade::Collidable::Collidable(bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path) : Drawable(name, pos, size, collidable, path), _collide(coll){}

arcade::Collidable::~Collidable(){}

bool arcade::Collidable::getCollision() const 
{
    return _collide;
}

void arcade::Collidable::setCollide(const bool &new_col)
{
    _collide = new_col;
}