/**
 * \file Sound.cpp
 */

#include "Sound.hpp"
#include <string>

arcade::Sound::Sound(std::string path) : Assets(path, sound) {}

arcade::Sound::~Sound(){}

void arcade::Sound::setLoop(const bool &new_loop)
{
    _loop = new_loop;
}

void arcade::Sound::setStatus(const enum sound_Status &new_status)
{
    _status = new_status;
}

bool arcade::Sound::getLoop() const 
{
    return _loop;
}

arcade::Sound::sound_Status arcade::Sound::getStatus() const
{
    return _status;
}
