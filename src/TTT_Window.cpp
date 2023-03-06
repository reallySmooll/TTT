/** \file TTT_Window.cpp
 * \brief Defines the "Window" class.
 */

#include "include/TTT/TTT.hpp"

#include <filesystem>
#include <string>

namespace TTT
{
    /** If true, the FPS will be shown at startup.\n
     * If false, to show the FPS, the user will need to press the "F3" key.
     */
    bool Window::toggleFPS; 

    /** If true, displays debug output of the library as well as logs them to a file called "TTT.log".\n
     * If false, does not display debug output of the library but logs them to a file called "TTT.log".
     */
    bool Window::verbose; 

    /** If true, creates a default immutable event loop.\n
     * If false, does not create a default immutable event loop.
     */
    bool Window::shouldCreateDefaultEventLoop;

    /** \brief The "Window" constructor used to create the window using sf::RenderWindow.
     *
     * \param windowWidth integer representing the width of the created window.
     * \param windowHeight integer representing the height of the created window.
     * \param windowTitle constant reference to the title of the created window of type sf::String with a default value of "TTT".
     * \param windowStyle unsigned 32-bit integer representing the style of the created window with a default value of "sf::Style::Default".
     * \param windowContextSettings constant reference to the context settings of the created window of type sf::ContextSettings with a default value of "sf::ContextSettings()".
     */
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

    /** \brief The "Window" destructor does nothing except for logging that the window is being destroyed.
     *
     * The "Window" destructor does nothing because it is already done by SFML when using the "window.close()" function.
     */
    Window::~Window() { Log::log(Log::WINDOW, Log::INFO, "Destroying window..."); }

    /** Creates the default immutable event loop that can be turned on or off using a boolean called "shouldCreateDefaultEventLoop". */
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
