/*
** EPITECH PROJECT, 2021
** Core.hpp
** File description:
** Core header file
*/

/**
 * \file Core.hpp
 */

#ifndef CORE_HPP
#define CORE_HPP

#include "Library.hpp"

namespace arcade 
{
    class Core
    {
        public:
            enum class Type {DISPLAY, GAME};
            Core() = default;
            ~Core();
            /*! @brief Open and load library
                @param name Library's name
                @param Type Library's Type (graph or game)
            */
            void loadLib(std::string name, Type);

            /*! @brief Setup program before launch the main menu 
            */
            void init();
        private:
            int checkGraphic(std::vector<std::string> graph);
            int graphicButton(int mychoice);
            int gameButton(int mychoice);
            void restartGame(const std::string &game);
            void Menu(int GameChosen, int &GraphicChosen, const std::vector<std::string> &graph, const std::vector<std::string> &game);
            int gameLoop(int &GameChosen, int &GraphicChosen, const std::vector<std::string> graph, const std::vector<std::string> game);
            Library _Gamelib;
            Library _Graphiclib;
            IDisplay *_Display;
            IGame *_Game;
    };
};

#endif
