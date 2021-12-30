/*
** EPITECH PROJECT, 2021
** SDL
** File description:
** SDL
*/

#include <vector>
#include "SDL.hpp"

graph::SDL::~SDL()
{
    SDL_DestroyWindow(this->_window);
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void graph::SDL::init(int width, int height, const std::string &name)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    (void) width;;
    (void) height;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL_InitVideo error: " << SDL_GetError() << std::endl;
    }
    this->_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (this->_window == NULL) {
        std::cerr << "SDL_CreateWindow error: ";
    }
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
    _music = Mix_LoadMUS("lib/Game/Pacman/src/pacman_music.ogg");
    Mix_VolumeMusic(50);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _font = TTF_OpenFont("lib/Display/SDL/font.ttf", 30);
}

SDL_Texture *graph::SDL::SpriteCreate(const std::string &filepath, std::tuple<int, int> position, std::tuple<int, int> size)
{
    SDL_Texture *img = nullptr;
    SDL_Rect rect;

    rect.x = std::get<0>(position);
    rect.y = std::get<1>(position);
    rect.w = std::get<0>(size);
    rect.h = std::get<1>(size);

    img = IMG_LoadTexture(_renderer, filepath.c_str());
    SDL_RenderCopy(_renderer, img, nullptr, &rect);
    return img;
}

SDL_Texture *graph::SDL::TextCreate(const std::string &name, const int size, const int x, const int y, SDL_Color color)
{
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(_font, name.c_str(), color);
    SDL_Texture *messenger = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_Rect messageRect;

    SDL_FreeSurface(surfaceMessage);
    messageRect.x = x;
    messageRect.y = y;
    messageRect.w = size * 8;
    messageRect.h = size * 2;
    SDL_RenderCopy(_renderer, messenger, nullptr, &messageRect);
    return messenger;
}

SDL_Texture *graph::SDL::ScoreCreate(int score)
{
    std::string strScore = "score :";
    strScore += std::to_string(score);
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(_font, strScore.c_str(), SDL_Color {255, 255, 255, 0});
    SDL_Texture *messenger = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
    SDL_Rect messageRect;

    SDL_FreeSurface(surfaceMessage);
    messageRect.x = 0;
    messageRect.y = 0;
    messageRect.w = 100;
    messageRect.h = 50;
    SDL_RenderCopy(_renderer, messenger, nullptr, &messageRect);
    return messenger;
}

void graph::SDL::SpriteDisplay(const std::vector<std::unique_ptr<arcade::Assets>> &assets)
{
    int end = assets.size();
    SDL_Texture *tmp = nullptr;

    clear();
    for (int it = 2; it < end; it += 1) {
        tmp = SpriteCreate(assets[it]->GetFilePath(), assets[it]->getPosition(), assets[it]->getSize());
        _sprite.push_back(tmp);
    }
    tmp = ScoreCreate(assets[1]->getScore());
    _sprite.push_back(tmp);
    display();
    for (auto it = _sprite.begin(); it != _sprite.end(); ++it)
        destroyTexture(*it);
}

void graph::SDL::destroyGame()
{
    
}

void graph::SDL::Menu(const std::string &libGraph, const std::string &libGame)
{
    clear();
    _menu = IMG_LoadTexture(_renderer, "./bg.png");
    SDL_RenderCopy(_renderer, _menu, nullptr, nullptr);
    _text.push_back(TextCreate(libGame, 20, 320, 210, (SDL_Color){255, 0, 0, 0}));
    _text.push_back(TextCreate(libGraph, 20, 350, 280, (SDL_Color){255, 0, 0, 0}));
    _text.push_back(TextCreate("Press g : change the game", 25, 215, 180, (SDL_Color){255, 255, 255, 0}));
    _text.push_back(TextCreate("Press v : change graph library", 25, 210, 240, (SDL_Color){255, 255, 255, 0}));
    _text.push_back(TextCreate("Enter your name :", 25, 210, 300, (SDL_Color){255, 255, 255, 0}));
    _text.push_back(TextCreate("Press enter to play", 25, 220, 400, (SDL_Color){255, 255, 255, 0}));
    display();
    for (auto it = _text.begin(); it != _text.end(); ++it)
        destroyTexture(*it);
}

std::unique_ptr<arcade::Inputs> graph::SDL::event()
{
    SDL_Event events;

    while (SDL_PollEvent(&events)) {
        if (events.type == SDL_QUIT) {
            Mix_PauseMusic();
            return std::make_unique<arcade::Inputs>(arcade::Inputs::type::MOUSE, arcade::Inputs::input::CLOSE);
        }
        if (events.type == SDL_KEYDOWN) {
            switch (events.key.keysym.sym) {
            case SDLK_v : return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::V);
            case SDLK_RETURN :
                destroyTexture(_menu);
                Mix_PlayMusic(_music, 10);
                return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::ENTER);
            case SDLK_LEFT: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::LEFT);
            case SDLK_RIGHT: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::RIGHT);
            case SDLK_UP: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::TOP);
            case SDLK_DOWN: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::DOWN);
            case SDLK_g: return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::G);
            case SDLK_r:
                Mix_PauseMusic();
                Mix_PlayMusic(_music, 10);
                return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::R);
            case SDLK_q:
                Mix_PauseMusic();
                return std::make_unique<arcade::Inputs>(arcade::Inputs::type::KEYBOARD, arcade::Inputs::input::Q);
            }
        }
        break;
    }
    return std::make_unique<arcade::Inputs>(arcade::Inputs::type::NONE);
}
       

void graph::SDL::display()
{
    SDL_RenderPresent(_renderer);
}

void graph::SDL::clear()
{
    SDL_RenderClear(_renderer);
}

void graph::SDL::destroyTexture(SDL_Texture *texture)
{
    SDL_DestroyTexture(texture);
}

extern "C" arcade::IDisplay *entryPoint()
{
    return new graph::SDL;
};

extern "C" void destroy(arcade::IDisplay *display)
{
    delete display;
}
