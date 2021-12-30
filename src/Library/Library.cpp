/*
** EPITECH PROJECT, 2021
** Library.cpp
** File description:
** Library class functions
*/

/**
 * \file Library.cpp
 */

#include "Library.hpp"
#include <dlfcn.h>
#include <cstddef>
#include <string>
#include "Exception.hpp"

arcade::Library::Library() : _run(false)
{

}

arcade::Library::~Library()
{
    if (this->_run == true)
        dlclose(this->_runLib);
}

void arcade::Library::checkLib(std::string &library)
{
    size_t pos = 0;
    std::string buff = library;

    while ((pos = library.find('/')) != std::string::npos)
        library.erase(0, pos + 1);
    while ((pos = library.find('_')) != std::string::npos)
        library.erase(0, pos + 1);
    this->_name = library.substr(0, library.find('.'));
    try {
        loadLib(buff);
    }
    catch (...) {
        throw;
    }
}

void arcade::Library::loadLib(const std::string &library)
{
    entrypoint_t *entry;
    std::string path = "./";

    path += library;
    this->_runLib = dlopen(path.c_str(), RTLD_LAZY);
    if (!this->_runLib)
        throw Exception (dlerror());
    this->_run = true;
    entry = reinterpret_cast<entrypoint_t *>(dlsym(this->_runLib, "entryPoint"));
    if (!entry) {
        entrypointGame_t *entry = reinterpret_cast<entrypointGame_t *>(dlsym(this->_runLib, "entryPoint"));
        if (!entry)
            throw Exception (dlerror());
    }
    this->_loadLib = static_cast<void *>(entry());
}

void arcade::Library::close()
{
    if (this->_run == false)
        dlclose(this->_runLib);
}

void arcade::Library::destroy(void *lib)
{
    this->_run = false;
    destroyGame_t *destroyLib = reinterpret_cast<destroyGame_t *>(dlsym(this->_runLib, "destroy"));
    if (!destroyLib) {
        arcade::destroy_t *destroyLib = reinterpret_cast<destroy_t *>(dlsym(this->_runLib, "destroy"));
        destroyLib(reinterpret_cast<IDisplay *>(lib));
    }
    else destroyLib(reinterpret_cast<IGame *>(lib));
}

void *&arcade::Library::getLib()
{
    return this->_loadLib;
}

const std::string &arcade::Library::getName() const
{
    return this->_name;
}

void *&arcade::Library::getOpenLib()
{
    return this->_runLib;
}

const bool &arcade::Library::isOpen()
{
    return this->_run;
}