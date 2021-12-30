/**
 * \file Sound.hpp
 */

#ifndef SOUND_H
#define SOUND_H

#include "Assets.hpp"

namespace arcade
{
    class Sound : public Assets
    {
        public:
        Sound(std::string path);
        ~Sound();

        enum sound_Status
        {
            play,
            pause,
            unset
        };
        void setLoop(const bool &new_loop);
        void setStatus(const enum sound_Status &new_status);
        sound_Status getStatus() const;
        virtual std::string getText() const override {return "";};
        virtual bool getLoop() const override;

        protected:
        sound_Status  _status;
        bool _loop;
    };
}
#endif