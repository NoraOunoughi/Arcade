#include "pucman.hpp"

game::Pacman::Pacman() 
{
    _assets.emplace_back(std::make_unique<arcade::Sound>("./lib/Game/Pacman/src/pacman_music.ogg"));
    _assets.emplace_back(std::make_unique<arcade::Score>(_score, std::tuple<int, int>{1, 1}));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("map", std::tuple<int, int>{1, 4}, std::tuple<int, int>{750, 600}, "lib/Game/Pacman/src/map.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("player", std::tuple<int, int>{360, 480}, std::tuple<int, int>{10, 10}, "lib/Game/Pacman/src/player.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("orange", std::tuple<int, int>{390, 270}, std::tuple<int, int>{10, 10}, "lib/Game/Pacman/src/orange.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("pink", std::tuple<int, int>{360, 270}, std::tuple<int, int>{10, 10}, "lib/Game/Pacman/src/pink.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("cyan", std::tuple<int, int>{330, 270}, std::tuple<int, int>{10, 10}, "lib/Game/Pacman/src/cyan.png"));
    _assets.emplace_back(std::make_unique<arcade::Drawable>("red", std::tuple<int, int>{360, 300}, std::tuple<int, int>{10, 10}, "lib/Game/Pacman/src/red.png"));
    CreateMap();
    _end = false;
}

game::Pacman::~Pacman() {}

void game::Pacman::CreateMap()
{
    int buff = 0;
    std::tuple<int, int> coord {0, 0};
    std::string line;
    std::ifstream fl("lib/Game/Pacman/src/map.txt");

    if (fl.is_open()) {
        for (; getline(fl, line); std::get<1>(coord) += 30) {
            _map.push_back(line);
            for (buff = 0, std::get<0>(coord) = 0; buff <= 25; buff++, std::get<0>(coord) += 30) {
                if (line[buff] == '#')
                    _assets.emplace_back(std::make_unique<arcade::Drawable>("wall", coord, std::tuple<int, int>{30, 30}, "lib/Game/Pacman/src/wall.png"));
                if (line[buff] == '.')
                    _assets.emplace_back(std::make_unique<arcade::Drawable>("gum", coord, std::tuple<int, int>{30, 30},"lib/Game/Pacman/src/pacgum.png"));  
            }
        }
        _map[16][12] = 'G';
        _map[9][12] = 'P';
        _map[9][11] = 'I';
        _map[9][13] = 'C';
        _map[10][12] = 'B';
    } else {std::cout << "OOOOOOOOO";}
}

std::tuple<int, int> game::Pacman::getcharacter(char c)
{
    long unsigned int i = 0;
    int y = 0; 
    for (i = 0; i < _map.size(); i++){
        for (y = 0; y <= 25; y++)
            if (_map[i][y] == c)
                return std::tuple<int, int>{i, y};
    }
    return std::tuple<int, int> {-1, -1};
}

void game::Pacman::EndGame()
{
    _assets.emplace_back(std::make_unique<arcade::Drawable>("end", std::tuple<int, int>{1, 4}, std::tuple<int, int>{750, 600}, "lib/Game/Pacman/src/end.jpg"));    
    _end = true;
}
bool game::Pacman::CheckCollision(arcade::Inputs::input input)
{
    int x = std::get<0>(getcharacter('G'));
    int y = std::get<1>(getcharacter('G'));
    if (x == -1 && y == -1) {
        EndGame();
        return true;
    }
    if (input == arcade::Inputs::input::LEFT) {
        if (x == 9 && y == 1) {
            _map[x][y] = ' ';
            _map[9][23] = 'G';
            for (long unsigned int y = 0; y < _assets.size(); y++)
                if (_assets[y]->getText() == "player") {
                    _assets[y]->setPosition(std::tuple<int, int>{690, 270});
                }
            return true;
        }
        if (_map[x][y - 1] != '#')  {
            if (_map[x][y - 1] == '.') {
                _score += 10;
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{(y - 1) * 30, x * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x][y - 1] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::RIGHT) {
        if (x == 9 && y == 23) {
            _map[x][y] = ' ';
            _map[9][1] = 'G';
            for (long unsigned int y = 0; y < _assets.size(); y++)
                if (_assets[y]->getText() == "player") {
                    _assets[y]->setPosition(std::tuple<int, int>{30, 270});
                }
            return true;
        }
        if (_map[x][y + 1] != '#') {
            if (_map[x][y + 1] == '.') {
                _score += 10;
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{(y + 1) * 30, x * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x][y + 1] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::TOP) {
        if (_map[x - 1][y] != '#') {
            if (_map[x - 1][y] == '.') {
                _score += 10;
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{y * 30, (x - 1) * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x - 1][y] = 'G';
            return false;
        } else return true;
    }
    if (input == arcade::Inputs::input::DOWN) {
        if (_map[x + 1][y] != '#') {
            if (_map[x + 1][y] == '.') {
                _score += 10;
                for (long unsigned int r = 0; r < _assets.size(); r++)
                if (_assets[r]->getPosition() == std::tuple<int, int>{y * 30, (x + 1) * 30})
                    _assets.erase(_assets.begin() + r);
            }
            _map[x][y] = ' ';
            _map[x + 1][y] = 'G';
            return false;
        } else return true;
    }
    return true;
}

bool game::Pacman::CheckCollisionEnemy(char c, long unsigned int t)
{
    int x = std::get<0>(getcharacter(c));
    int y = std::get<1>(getcharacter(c));
    if (x == -1 && y == -1) {
        EndGame();
        return true;
    }
    std::tuple<int, int> new_pos = _assets[t]->getPosition();
    int result = 1 + (rand() % 4);
    if (result == 1) {
        std::get<0>(new_pos) -= 30;
        if (_map[x][y - 1] != '#' && _map[x][y - 1] != 'I' && _map[x][y - 1] != 'B' && _map[x][y - 1] != 'C' && _map[x][y - 1] != 'P' && _map[x][y - 1] != 'G') {
            _map[x][y] = ' ';
            _map[x][y - 1] = c;
            _assets[t]->setPosition(new_pos);
            return false;
        } else return true;
    }
    if (result == 2) {
        std::get<0>(new_pos) += 30;
        if (_map[x][y + 1] != '#' && _map[x][y + 1] != 'I' && _map[x][y + 1] != 'B' && _map[x][y + 1] != 'C' && _map[x][y + 1] != 'P' && _map[x][y + 1] != 'G') {
            _map[x][y] = ' ';
            _map[x][y + 1] = c;
            _assets[t]->setPosition(new_pos);
            return false;
        } else return true;
    }
    if (result == 3) {
        std::get<1>(new_pos) -= 30;
        if (_map[x - 1][y] != '#' && _map[x - 1][y] != 'I' && _map[x - 1][y] != 'B' && _map[x - 1][y] != 'C' && _map[x - 1][y] != 'P'&& _map[x - 1][y] != 'G') {
            _map[x][y] = ' ';
            _map[x - 1][y] = c;
            _assets[t]->setPosition(new_pos);
            return false;
        } else return true;
    }
    if (result == 4) {
        std::get<1>(new_pos) += 30;
        if (_map[x + 1][y] != '#' && _map[x + 1][y] != 'I' && _map[x + 1][y] != 'B' && _map[x + 1][y] != 'C' && _map[x + 1][y] != 'P' && _map[x + 1][y] != 'G') {
            _map[x][y] = ' ';
            _map[x + 1][y] = c;
            _assets[t]->setPosition(new_pos);
            return false;
        } else return true;
    }
    return true;
}

void game::Pacman::moveEnemy()
{
    if (_end == true)
        return;
    for (long unsigned int y = 0; y < _assets.size(); y++) {
        if (_assets[y]->getText() == "cyan")
            CheckCollisionEnemy('I', y);
        if (_assets[y]->getText() == "red")
            CheckCollisionEnemy('B', y);
        if (_assets[y]->getText() == "orange")
            CheckCollisionEnemy('C', y);
        if (_assets[y]->getText() == "pink")
            CheckCollisionEnemy('P', y);
    }
}

void game::Pacman::getInput(const std::unique_ptr<arcade::Inputs> &i)
{
    static arcade::Inputs::input direction = arcade::Inputs::input::NONE;
    for (long unsigned int y = 0; y < _assets.size(); y++)
        if (_assets[y]->getText() == "player") {
            std::tuple<int, int> new_pos = _assets[y]->getPosition();
            if (i->getInput() ==  arcade::Inputs::input::LEFT) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::LEFT) == false) {
                    direction = arcade::Inputs::input::LEFT;
                    std::get<0>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Pacman/src/player_left.png");
                    return;
                } else return;
            } if (i->getInput() ==  arcade::Inputs::input::RIGHT) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::RIGHT) == false) {
                    direction = arcade::Inputs::input::RIGHT;
                    std::get<0>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Pacman/src/player.png");
                    return;
                } else return;
            } if (i->getInput() ==  arcade::Inputs::input::TOP) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::TOP) == false) {
                    direction = arcade::Inputs::input::TOP;
                    std::get<1>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Pacman/src/player_up.png");
                    return;
                } else return;
            }
            if (i->getInput() ==  arcade::Inputs::input::DOWN) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::DOWN) == false) {
                    direction = arcade::Inputs::input::DOWN;
                    std::get<1>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                    _assets[y]->setFilepath("lib/Game/Pacman/src/player_down.png");
                    return;
                } else return;
            }
            if (direction == arcade::Inputs::input::LEFT) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::LEFT) == false) {
                    std::get<0>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::RIGHT) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::RIGHT) == false) {
                    std::get<0>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::TOP) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::TOP) == false) {
                    std::get<1>(new_pos) -= 30;
                    _assets[y]->setPosition(new_pos);
                }
            } else if (direction == arcade::Inputs::input::DOWN) {
                if (game::Pacman::CheckCollision(arcade::Inputs::input::DOWN) == false) {
                    std::get<1>(new_pos) += 30;
                    _assets[y]->setPosition(new_pos);
                }
            }
        }
    moveEnemy();
}

std::vector<std::unique_ptr<arcade::Assets>> &game::Pacman::getasset() 
{
    return _assets;
}

void game::Pacman::setlist(std::string name, std::tuple<int, int> pos, std::tuple<int, int> size, std::string path)
{
    _assets.emplace_back(std::make_unique<arcade::Drawable>(name, pos, size, path));
}

extern "C" arcade::IGame *entryPoint()
{
    return new game::Pacman;
};

extern "C" void destroy(arcade::IGame *game)
{
    delete game;
}