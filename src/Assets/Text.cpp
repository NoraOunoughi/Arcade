/**
 * \file Text.cpp
 */

#include "Text.hpp"
#include <string>
#include <tuple>

arcade::Text::Text(std::string that_text, std::tuple<int, int> pos) : Assets(text), _str(that_text), _textposition(pos) {}

arcade::Text::Text(std::tuple<int, int> pos, text_status stat) : Assets(text), _textposition(pos) , _text_type(stat) {}

arcade::Text::~Text(){}

std::tuple<int, int> arcade::Text::getTextPosition() const
{
    return _textposition;
}

void arcade::Text::setPosition(const std::tuple<int, int> &new_pos)
{
    _textposition = new_pos;
}

void arcade::Text::setText(const std::string &new_text)
{
    _str = new_text;
}