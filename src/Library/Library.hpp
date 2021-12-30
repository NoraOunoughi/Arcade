/*
** EPITECH PROJECT, 2021
** Library.hpp
** File description:
** Library header file
*/

/**
 * \file Library.hpp
 */

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include "IDisplay.hpp"
#include "IGame.hpp"

namespace arcade {
    class Library
    {
        public:
            Library();
            ~Library();
            /*! @brief Get library name
                @param library Library's path
            */
            void checkLib(std::string &library);

            /*! @brief Free library's pointer
                @param lib Library
            */
            void destroy(void *lib);

            /*! @brief Open and load library
            */
            void *&getLib();

            /*! @brief Return Library's name
            */
            const std::string &getName() const;

            /*! @brief Return open library (give by dlopen)
            */
            void *&getOpenLib();

            /*! @brief Return if the library is open
            */
            const bool &isOpen();

            /*! @brief Vlose the library
            */
            void close();
        private:
            void loadLib(const std::string &library);
            void *_runLib;
            void *_loadLib;
            std::string _name;
            bool _run;
    };
};
#endif
