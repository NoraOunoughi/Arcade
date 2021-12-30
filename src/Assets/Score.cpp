/**
 * \file Score.cpp
 */

#include "Score.hpp"
#include <string>
#include <tuple>

arcade::Score::Score(int set_score, std::tuple<int, int> my_tag) : Text(my_tag, score), _score(set_score) {}

arcade::Score::~Score() {}

int arcade::Score::getScore() const 
{
    return _score;
}

void arcade::Score::setScore(const int &new_score)
{
    _score = new_score;
}