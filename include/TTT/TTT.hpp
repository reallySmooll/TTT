/** \file TTT.hpp
 * \brief This is the header file and where everything is declared.
 * \tableofcontents
 */

#ifndef TTT_HPP
#define TTT_HPP

#include <cstdint>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/** \brief The TTT namespace, which includes everything in the library. */
namespace TTT
{
    typedef std::string module; ///< Type definition for different modules.
    typedef std::string level;  ///< Type definition for different levels.
    typedef std::string color;  ///< Type definition for different colors.

    /** \brief The "Window" class initializes the window and everything else (like the default event loop).
     *
     * The class is initialized using a "Window" constructor that takes parameters similar to the parameters of the sf::RenderWindow class constructor.
     */
    class Window
    {
        public:
            Window(int windowWidth, int windowHeight, const sf::String& windowTitle="TTT", uint32_t windowStyle=sf::Style::Default, const sf::ContextSettings& windowContextSettings=sf::ContextSettings());
            ~Window();

            sf::RenderWindow window;                  ///< The "window" variable is initialized with the parameters of the "Window" constructor.

            static bool verbose;                      ///< The user can choose whether to show the debug output in the terminal as well as log to a file called "TTT.log" or just log to the file.
            static bool toggleFPS;                    ///< The user can choose whether to show the FPS at startup or require the "F3" key to be pressed to show it.
            static bool shouldCreateDefaultEventLoop; ///< The user can choose whether to create a default immutable event loop or not.
        private:
            void defaultEventLoop();                  ///< Creates the default immutable event loop.
    };

    /** \brief Utilities class for smaller and miscellaneous functions like the "showFPS" one. */
    class Utils
    {
        public:
            static void showFPS(sf::RenderWindow& window, const sf::Font& font, unsigned int fontSize, sf::Color color=sf::Color::White); 
            static sf::Font createFont(std::string filename);
            static sf::Sprite createSprite(sf::Texture& texture, std::string filename);
            static void sleepFor(int timeInSeconds);
            static sf::Text createText(const sf::Font& font, unsigned int fontSize, sf::Vector2f position, std::string textContents);
    };

    /** \brief Logger class not really meant to be used outside of the library. */
    class Log
    {
        public:
            static void log(module module, level level, std::string message);

            static const module TTT;     ///< Module used in the most critical of logs.

            static const module WINDOW;  ///< Module used in logging everything that has to do with the window.
            static const module UTILS;   ///< Module used in logging everything that has to do with the utilities class.
            static const module LOG;     ///< Module used in logging everything that has to do with the logger class.
            static const module SFML;    ///< Module used in logging everything that has to do with the SFML library.

            static const level SUCCESS;  ///< Success level indicates that an operation was successful.
            static const level INFO;     ///< Info level displays basic information.
            static const level WARNING;  ///< Warning level indicates that there's something wrong with the program but doesn't require immediate attention.
            static const level ERROR;    ///< Error level indicates that there's something wrong with the program requires attention.
            static const level CRITICAL; ///< Critical level indicates that there's something wrong with the program and requires immediate attention.

            static const color RESET;    ///< Reset color resets all of the colors to the terminal default.
            static const color RED;      ///< Red color paints output red. Used in critical errors.
            static const color GREEN;    ///< Green color paints output green. Used when something is successful.
            static const color WHITE;    ///< White color paints output white. Used when displaying basic information.
            static const color L_RED;    ///< Light red color paints output light red. Used in errors.
            static const color L_YELLOW; ///< Light yellow color paints output light yellow. used in warnings.
    };
}

#endif // TTT_HPP
