/**
 * \file Collidable.hpp
 */

#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "Drawable.hpp"
#include <string>

namespace arcade 
{
    class Collidable : public Drawable
    {
        public:
        Collidable(bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path);
        ~Collidable();
        virtual bool getCollision() const override;
        void setCollide(const bool &col);

        protected:
        bool _collide;
    };
}
#endif