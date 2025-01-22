#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);
    sf::Texture mushroomTexture;
    mushroomTexture.loadFromFile("Mushroom.png");
    sf::Sprite mushroom(mushroomTexture);
    sf::Vector2u size = mushroomTexture.getSize();
    mushroom.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
    sf::Vector2f increment(0.4f, 0.4f);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        if((mushroom.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0)){
            //Reverse direction on the X axis
            increment.x = -increment.x;
        }
        if((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0)){
            //Reverse the direction on the Y axis
            increment.y = -increment.y;
        }

        mushroom.setPosition(mushroom.getPosition() + increment);

        window.clear();
        window.draw(mushroom);
        window.display();
    }
}
