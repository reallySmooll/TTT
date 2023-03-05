#ifndef TTT_HPP
#define TTT_HPP

#include <cstdint>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

namespace TTT
{
    typedef std::string module;
    typedef std::string level;
    typedef std::string color;

    // Main class that initializes everything.
    class Window
    {
        public:
            Window(int windowWidth, int windowHeight, const sf::String& windowTitle="TTT", uint32_t windowStyle=sf::Style::Default, const sf::ContextSettings& windowContextSettings=sf::ContextSettings());
            ~Window();

            sf::RenderWindow window;

            static bool verbose;
            static bool toggleFPS;
            static bool shouldCreateDefaultEventLoop;
        private:
            void defaultEventLoop();
    };

    // Class for button creation 'cause SFML doesn't have one I guess (weird).
    class Button
    {
        public:
            Button();
            ~Button();
        private:
            sf::RectangleShape button;
    };

    // Utilities class for misc functions like the showFPS one.
    class Utils
    {
        public:
            static void showFPS(sf::RenderWindow& window, const sf::Font& font, unsigned int fontSize, sf::Color color=sf::Color::White); 
            static sf::Font createFont(std::string filename);
            static sf::Sprite createSprite(sf::Texture& texture, std::string filename);
            static void sleepFor(int timeInSeconds);
            static sf::Text createText(const sf::Font& font, unsigned int fontSize, sf::Vector2f position, std::string textContents);
    };

    // Logger class not really meant to be used outside of the library.
    class Log
    {
        public:
            static void log(module module, level level, std::string message);

            static const module TTT;

            static const module WINDOW;
            static const module UTILS;
            static const module LOG;
            static const module SFML;

            static const level SUCCESS;
            static const level INFO;
            static const level WARNING;
            static const level ERROR;
            static const level CRITICAL;

            static const color RESET;
            static const color RED;
            static const color GREEN;
            static const color WHITE;
            static const color L_RED;
            static const color L_YELLOW;
    };
}

#endif // TTT_HPP
