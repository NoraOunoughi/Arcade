#include "Menu.hpp"

std::vector<sf::RectangleShape> graph::Menu::createButtons()
{
    std::vector<sf::RectangleShape> buttons;
    std::vector<int> posButton = {120, 200, 320, 200, 520, 200, 120, 400, 320, 400, 520, 400};

    for (int it = 0; it < 12; it+=2)
        buttons.push_back(createButton(posButton[it], posButton[it + 1]));
    
    return buttons;
}

sf::RectangleShape graph::Menu::createButton(const int x, const int y)
{
    sf::RectangleShape button(sf::Vector2f(150, 50));
    button.setPosition(x, y);
    return button;
}