/*
** EPITECH PROJECT, 2021
** core.cpp
** File description:
** Core function file
*/

/**
 * \file Core.cpp
 */

#include <vector>
#include <unistd.h>
#include "Core.hpp"
#include "Library.hpp"
#include "Inputs.hpp"
#include "Exception.hpp"

arcade::Core::~Core()
{
    if (this->_Graphiclib.isOpen() == true)
        this->_Graphiclib.destroy(static_cast<void *>(this->_Display));
    if (this->_Gamelib.isOpen() == true)
        this->_Gamelib.destroy(static_cast<void *>(this->_Game));
}

int arcade::Core::gameLoop(int &GameChosen, int &GraphicChosen, const std::vector<std::string> graph, const std::vector<std::string> game)
{
    try {
        loadLib("lib/arcade_" + game[GameChosen] + ".so", Type::GAME);
        while (true) {
            std::unique_ptr<arcade::Inputs> event = _Display->event();
            if (event->getInput() == arcade::Inputs::input::CLOSE)
                return 1;
            if (event->getInput() == arcade::Inputs::input::Q || event->getInput() == arcade::Inputs::input::CLOSE)
                break;
            if (event->getInput() == arcade::Inputs::input::G) {
                GameChosen = gameButton(GameChosen);
                restartGame("lib/arcade_" + game[GameChosen] + ".so");
            }
            if (event->getInput() == arcade::Inputs::input::V)
                GraphicChosen = graphicButton(GraphicChosen);
            if (graph[GraphicChosen] != this->_Graphiclib.getName()) {
                loadLib("lib/arcade_" + graph[GraphicChosen] + ".so", Type::DISPLAY);
                this->_Display->init(750, 600, "Arcade");
            }
            if (event->getInput() == arcade::Inputs::input::R)
                restartGame("lib/arcade_" + game[GameChosen] + ".so");
            this->_Game->getInput(event);
            this->_Display->SpriteDisplay(this->_Game->getasset());
        }
        this->_Gamelib.destroy(static_cast<void *>(this->_Game));
    }
    catch (...) {
        throw;
    }
    return 0;
}

void arcade::Core::Menu(int GameChosen, int &GraphicChosen, const std::vector<std::string> &graph, const std::vector<std::string> &game)
{
    try {
        while (true) {
            std::unique_ptr<arcade::Inputs> event = _Display->event();
            if (event->getInput() == arcade::Inputs::input::ENTER)
                if (gameLoop(GameChosen, GraphicChosen, graph, game) == 1) 
                    break;
            if (event->getInput() == arcade::Inputs::input::CLOSE || event->getInput() == arcade::Inputs::input::Q)
                break;
            if (event->getInput() == arcade::Inputs::input::G)
                GameChosen = gameButton(GameChosen);
            if (event->getInput() == arcade::Inputs::input::V)
                GraphicChosen = graphicButton(GraphicChosen);
            if (graph[GraphicChosen] != this->_Graphiclib.getName()) {
                loadLib(("lib/arcade_" + graph[GraphicChosen] + ".so"), Type::DISPLAY);
                this->_Display->init(750, 600, "Arcade");
            }
            this->_Display->Menu(graph[GraphicChosen], game[GameChosen]);
        }
    }
    catch (...) {
        throw;
    }
}

void arcade::Core::restartGame(const std::string &game)
{
    this->_Display->destroyGame();
    this->_Gamelib.destroy(static_cast<void *>(this->_Game));
    loadLib((game), Type::GAME);
}

void arcade::Core::init()
{
    this->_Display->init(750, 600, "Arcade");
    std::vector<std::string> graph = {"sfml", "sdl2"};
    std::vector<std::string> game = {"pacman", "nibbler"};
    int GraphicChosen = checkGraphic(graph);
    Menu(0, GraphicChosen, graph, game);
}

int arcade::Core::graphicButton(int mychoice)
{
    mychoice += 1;
    if (mychoice > 1)
        mychoice = 0;
    return mychoice;
}

int arcade::Core::gameButton(int mychoice)
{
    mychoice += 1;
    if (mychoice > 1)
        mychoice = 0;
    return mychoice;
}

int arcade::Core::checkGraphic(std::vector<std::string> graph)
{
    for (long unsigned it = 0; it < graph.size(); it++)
        if (graph[it] == this->_Graphiclib.getName())
            return it;
    throw Exception ("Library graph not found");
}

void arcade::Core::loadLib(std::string name, Type type)
{
    try {
        if (type == Type::DISPLAY) {
            if (this->_Graphiclib.isOpen() == true) {
                this->_Graphiclib.destroy(static_cast<void *>(this->_Display));
                this->_Graphiclib.close();
            }
            this->_Graphiclib.checkLib(name);
            this->_Display = static_cast<IDisplay *>(this->_Graphiclib.getLib());
        }
        if (type == Type::GAME) {
            if (this->_Gamelib.isOpen() == true) {
                this->_Gamelib.destroy(static_cast<void *>(this->_Display));
                this->_Graphiclib.close();
            }
            this->_Gamelib.checkLib(name);
            this->_Game = static_cast<IGame *>(this->_Gamelib.getLib());
        }
    }
    catch(...) {
        throw;
    }
}