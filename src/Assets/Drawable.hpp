/**
 * \file Drawable.hpp
 */

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Assets.hpp"
#include <string>
#include <tuple>

namespace arcade
{
    class Drawable : public Assets
    {
        public:
        enum Draw_status
        {
            collidable,
            dynamic,
            character
        };
        Drawable(const std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, Draw_status type, const std::string path);
        Drawable(const std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, const std::string path);
        Drawable() {};
        ~Drawable();

        virtual std::tuple<int, int> getPosition() const override;
        virtual std::tuple<int, int> getSize() const override;
        virtual std::string getText() const override;
        
        virtual void setPosition(const std::tuple<int, int> &new_pos) override;
        void setSize(const std::tuple<int, int> &new_size);
        void setText(const std::string &new_text);
        
        protected:
        std::tuple<int, int> _position;
        std::tuple<int, int> _size;
        std::string _text;
        enum Draw_status _type_draw;
    };
}

#endif