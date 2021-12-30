/**
 * \file Character.hpp
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Dynamic.hpp"
#include <string>

namespace arcade
{
    class Character : public Dynamic
    {
        public:
        enum Type
        {
            character
        };
        Character(int live, std::tuple<float, float> dir, bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path);
        ~Character();
        virtual int getLife() const override;
        void setHp(const int &new_hp);
        protected:
        int _hp;
    };
}
#endif
