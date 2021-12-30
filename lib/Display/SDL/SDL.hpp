/*
65;5604;1c** EPITECH PROJECT, 2021
** SDL
** File description:
** SDL
*/

/**
 * \file SDL.hpp
 */
#ifndef SDL_HPP
#define SDL_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "IDisplay.hpp"

namespace graph
{
    class SDL : public arcade::IDisplay
    {
    public:
        SDL() = default;
        ~SDL();
        /*! @brief initialize all resources needed for the game
        */
        void init(int width, int height, const std::string &name);
        /*! @brief displays the main menu
            @param libGraph graph library used
            @param libGame game library used
        */
        void Menu(const std::string &libGraph, const std::string &libGame);
        /*! @brief display all our sprites
            @param assets vector of all our assets to draw
        */
        void SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets);
        /*! @brief create a SDL texture to draw 
            @param path path to the source file of the sprite
            @param position position in which we draw our sprite
            @param size size of the sprite
        */
        SDL_Texture *SpriteCreate(const std::string &path, std::tuple<int, int> position, std::tuple<int, int> size);
        /*! @brief create a SDL texture to draw text
            @param path path to the font to use
            @param size size of the text
            @param x x position of the text
            @param y y position of the text
            @param color color of the text
        */
        SDL_Texture *TextCreate(const std::string &name, const int size, const int x, const int y, SDL_Color color);
        /*! @brief destroy a texture
            @param texture a texture to destroy
        */
        void destroyTexture(SDL_Texture *texture);
        /*! @brief handles all events happening in the window
        */
        std::unique_ptr<arcade::Inputs> event();
        /*! @brief destroy resources of the game
        */
        void destroyGame();
        /*! @brief display the window
        */
        void display();
        /*! @brief clear the window
        */
        void clear();
        SDL_Texture *ScoreCreate(int score);
    private:
        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
        SDL_Texture *_menu = nullptr;
        TTF_Font *_font = nullptr;
        std::vector<SDL_Texture *> _sprite;
        std::vector<SDL_Texture *> _text;
        Mix_Music *_music = nullptr;
    };
}

#endif
