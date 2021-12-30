/**
 * \file Assets.hpp
 */

#ifndef ASSETS_H
#define ASSETS_H

#include <string>
#include <iostream>
#include <tuple>

namespace arcade
{
    class Assets
    {
        public:
        enum Type
        {
            drawable,
            sound,
            text
        };
        Assets(std::string path, Type my_tag);
        Assets(Type my_tag);
        Assets() {};
        virtual ~Assets();
        std::string GetFilePath() const;
        Type getTag() const ;
        void setFilepath(const std::string &path);
        void newTag(const Type &my_tag);

        virtual void setPosition(const std::tuple<int, int> &i) {(void)i;};
        virtual std::tuple<int, int> getSize() const {return std::tuple<int ,int>{-1, -1};};
        virtual bool getCollision() const{return false;};
        virtual std::string getText() const {return "";};
        virtual std::tuple<int ,int> getPosition() const {return std::tuple<int ,int>{-1,-1};};
        virtual std::tuple<int, int> getDirection() const {return std::tuple<int ,int>{-1,-1};};
        virtual int getLife() const {return -1;};
        virtual std::tuple<int, int> getTextPosition() const{return std::tuple<int ,int>{-1,-1};};
        virtual int getScore() const {return -1;};
        virtual bool getLoop() const {return false;};
        protected:
        std::string _path;
        enum Type _stat;
    };
}
#endif
