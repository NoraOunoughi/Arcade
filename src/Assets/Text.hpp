/**
 * \file Text.hpp
 */

#ifndef TEXT_H
#define TEXT_H

#include <tuple>
#include "Assets.hpp"

namespace arcade
{
    class Text : public Assets
    {
    public:
        enum text_status
        {
            texte,
            score
        };
        Text(std::string path, std::tuple<int, int> pos);
        Text(std::tuple<int, int> pos, text_status stat);
        ~Text();

        virtual std::tuple<int, int> getTextPosition() const override;
        virtual std::string getText() const override {return _str;};
        
        void setPosition(const std::tuple<int, int> &new_pos);
        void setText(const std::string &str);
    protected:
        std::string _str;
        std::tuple<int, int> _textposition;
        enum text_status _text_type;
    };
}
#endif