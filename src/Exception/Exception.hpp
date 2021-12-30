/*
** EPITECH PROJECT, 2021
** Exception.hpp
** File description:
** Exception header file
*/

/**
 * \file Exception.hpp
 */

#include <exception>
#include <string>

namespace arcade 
{
    class Exception : public std::exception
    {
        public:
            Exception(const std::string &messenger="") throw();
            ~Exception() = default;
            /*! @brief Return the error message
            */
            const std::string &what() throw();
        private:
            std::string _msg;
    };
};