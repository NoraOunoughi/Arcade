/**
 * \file Score.hpp
 */

#ifndef SCORE_H
#define SCORE_H

#include "Text.hpp"
#include <string>
#include <tuple>

namespace arcade
{
    class Score : public Text 
    {
        public:
            Score(int set_score, std::tuple<int, int> my_tag);
            ~Score();
            virtual int getScore() const;
            void setScore(const int &new_score);
        private:
            int _score;
    };
}
#endif