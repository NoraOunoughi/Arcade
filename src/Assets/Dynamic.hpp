/**
 * \file Dynamic.hpp
 */

#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "Collidable.hpp"
#include <string>
#include <tuple>

namespace arcade
{
    class Dynamic : public Collidable
    {
        public:
        Dynamic(std::tuple<int, int> dir, bool coll, std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path);
        ~Dynamic();

        virtual std::tuple<int, int> getDirection() const override;
        void setDirection(const std::tuple<int, int> &new_dir);
        protected:
        std::tuple<int, int> _direction;
    };
}
#endif