#include "include/TTT/TTT.hpp"

#include <filesystem>
#include <string>

namespace TTT
{
    // If this is true, the showFPS function will be enabled on startup.
    // If this is false, the showFPS function will require the F3 key to be pressed to start.
    bool Window::toggleFPS;

    /* "verbose" is undefined here because if it had been defined,
     * the user wouldn't be able to switch it to false if debug output is unwanted. */
    bool Window::verbose;

    // If false, will not create a default event loop.
    bool Window::shouldCreateDefaultEventLoop;

    Window::Window(int windowWidth, int windowHeight, const sf::String& windowTitle, uint32_t windowStyle, const sf::ContextSettings& windowContextSettings)
        : window(sf::VideoMode(windowWidth, windowHeight), windowTitle, windowStyle, windowContextSettings)
    {
        if (std::filesystem::exists("TTT.log"))
            std::filesystem::remove("TTT.log");

        Log::log(Log::WINDOW, Log::INFO, "Creating window...");

        Log::log(Log::WINDOW, Log::INFO, "Window width: " + std::to_string(windowWidth));
        Log::log(Log::WINDOW, Log::INFO, "Window height: " + std::to_string(windowHeight));
        Log::log(Log::WINDOW, Log::INFO, "Window title: " + windowTitle);

        if (shouldCreateDefaultEventLoop)
            defaultEventLoop();
    }

    Window::~Window() { Log::log(Log::WINDOW, Log::INFO, "Destroying window..."); }

    // Will create a default immutable event loop.
    void Window::defaultEventLoop()
    {
        Log::log(Log::WINDOW, Log::INFO, "Creating default event loop...");

        window.setFramerateLimit(60);

        sf::Font font = Utils::createFont("resources/fonts/04B_30__.TTF");

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(26);
        text.setString("If you're seeing this, it means that\nthe default event loop\nhas been initialized and\nis working without any errors.");
        text.setPosition((window.getSize().x / 2) - (text.getLocalBounds().width / 2), (window.getSize().y / 2) - (text.getLocalBounds().height / 2));

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case event.Closed:
                        window.close();
                        break;
                    case event.KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape)
                            window.close();
                        break;
                    default:
                        break;
                }
            }

            window.clear();

            window.draw(text);

            /* The "showFPS" function is included so the default event loop has a purpose. Of course it does have a purpose without the "showFPS"
             * function but there's always more it can do. */
            Utils::showFPS(window, font, 24);

            window.display();
        }
    }
}
