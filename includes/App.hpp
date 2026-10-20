#if !defined(__SFML_APP_HPP__)
#define __SFML_APP_HPP__
#include <SFML/Graphics.hpp>
#endif // __SFML_APP_HPP__


class App
{
private:
    sf::RenderWindow window;
public:
    App();
    ~App();
    void run();
};