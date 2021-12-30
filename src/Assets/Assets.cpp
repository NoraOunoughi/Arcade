/**
 * \file Assets.cpp
 */

#include "Assets.hpp"

arcade::Assets::Assets(std::string path, Type my_tag) : _path(path), _stat(my_tag){}

arcade::Assets::Assets(Type my_tag) : _stat(my_tag) {}

arcade::Assets::~Assets(){}

std::string arcade::Assets::GetFilePath() const
{
    return _path;
}

arcade::Assets::Type arcade::Assets::getTag() const
{
    return _stat;
}

void arcade::Assets::setFilepath(const std::string &path)
{
    _path = path;
}

void arcade::Assets::newTag(const Type &my_tag)
{
    _stat = my_tag;
}
