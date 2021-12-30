/**
 * \file Character.cpp
 */

#include "Character.hpp"
#include <string>

arcade::Character::Character(int live, std::tuple<float, float> dir, bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path) : Dynamic(dir, coll, name, pos, size, path), _hp(live) {}

arcade::Character::~Character() {}

int arcade::Character::getLife() const
{
    return _hp;
}

void arcade::Character::setHp(const int &new_hp)
{
    _hp = new_hp;
}