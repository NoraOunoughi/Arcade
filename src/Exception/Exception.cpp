/**
 * \file Exception.cpp
 */

#include "Exception.hpp"

arcade::Exception::Exception(const std::string &messenger) throw(): _msg(messenger) 
{

};

const std::string &arcade::Exception::what() throw() 
{
    return this->_msg;
};