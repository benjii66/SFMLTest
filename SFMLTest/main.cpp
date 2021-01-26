#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "OH CA MARCHE");
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setFillColor(sf::Color::Green);

    rectangle.setPosition(sf::Vector2f(50.f, 120.f));

    sf::RectangleShape chara(sf::Vector2f(60.f, 50.f));
    chara.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rectangle);
        window.draw(chara);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            chara.move(1.0f, 0.f);


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            chara.move(-1.0f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            chara.move(0.f, 1.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            chara.move(0.f, -1.0f);

        if (chara.getPosition() == rectangle.getPosition())
        {
            chara.setFillColor(sf::Color::Red);
        }


        //affichage
        window.display();
    }

    return 0;
}