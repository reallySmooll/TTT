/** \file TTT_Utils.cpp
 * \brief Defines the "Utils" class.
 */

#include "include/TTT/TTT.hpp"

#include <sstream>
#include <chrono>
#include <thread>
#include <cmath>

namespace TTT
{
    sf::Clock clock;

    sf::Text fpsText;

    std::stringstream ss;

    bool isKeyPressed = false;

    int frameCount = 0;

    const float startTime = clock.getElapsedTime().asSeconds();

    /** \brief "showFPS" calculates and displays a nice FPS number when the "F3" key is pressed.
     *
     * \param window reference to the window of type "sf::RenderWindow".
     * \param font constant reference to the font of type "sf::Font".
     * \param fontSize unsigned integer representing the size of the font.
     * \param color sf::Color representing the color of the FPS font with a default value of "sf::Color::White".
     */
    void Utils::showFPS(sf::RenderWindow& window, const sf::Font& font, unsigned int fontSize, sf::Color color)
    {
        frameCount++;

        const float elapsedTime = clock.getElapsedTime().asSeconds();

        if (elapsedTime >= 0.1f)
        {
            const float fps = frameCount / (elapsedTime - startTime);

            ss.str("");
            ss << "FPS: " << std::floor(fps + 1);

            fpsText.setString(ss.str());

            frameCount = 0;

            clock.restart();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
        {
            if (!isKeyPressed)
            {
                Window::toggleFPS = !Window::toggleFPS;
                isKeyPressed = true;
            }
        }
        else
        {
            isKeyPressed = false;
        }

        if (Window::toggleFPS)
        {
            fpsText.setFont(font);
            fpsText.setFillColor(color);
            fpsText.setCharacterSize(fontSize);
            fpsText.setPosition(10, 10);

            window.draw(fpsText);
        }
    }

    /** \brief Function to create a font and load it. Shortens the amount of code that has to be written.
     *
     * \param filename a string representing the path to the font file.
     */
    sf::Font Utils::createFont(std::string filename)
    {
        Log::log(Log::UTILS, Log::INFO, "Creating font from file: \"" + filename + "\"...");

        sf::Font font;

        if (!font.loadFromFile(filename))
            Log::log(Log::SFML, Log::WARNING, "Failed to load font! It means that you've specified the wrong path to the font or it doesn't exist. Check that it actually exists and if it does, check the path.");
        else
            Log::log(Log::UTILS, Log::SUCCESS, "Font created successfully!");

        return font;
    }

    /** \brief Function to create and load a texture to a sprite. Shortens the amount of code that has to be written.
     *
     * Texture variable has to be created manually and passed as a paramter to the function because the sprites
     * act weird when the texture is created in the function.
     *
     * \param texture reference to the texture of type "sf::Texture".
     * \param filename a string representing the path to the texture file.
     */
    sf::Sprite Utils::createSprite(sf::Texture& texture, std::string filename)
    {
        Log::log(Log::UTILS, Log::INFO, "Creating sprite from texture file: \"" + filename + "\"...");

        sf::Sprite sprite;

        if (!texture.loadFromFile(filename))
            Log::log(Log::SFML, Log::WARNING, "Failed to load texture! It means that you've specified the wrong path to the texture or it doesn't exist. Check that it actually exists and if it does, check the path.");

        sprite.setTexture(texture);

        Log::log(Log::UTILS, Log::SUCCESS, "Sprite created successfully!");

        return sprite;
    }

    /** \brief Function makes the program "sleep" for a specified amount of time in seconds.
     *
     * \param timeInSeconds integer representing the time in seconds.
     */
    void Utils::sleepFor(int timeInSeconds)
    {
        Log::log(Log::UTILS, Log::INFO, "Sleeping for " + std::to_string(timeInSeconds) + "s...");

        std::chrono::seconds timespan(timeInSeconds);
        std::this_thread::sleep_for(timespan);
    }

    /** \brief Function creates text that can be displayed in the window.
     *
     * \param font constant reference to the font of type "sf::Font".
     * \param fontSize unsigned integer representing the size of the font.
     * \param position 2D vector representing the position on the x and y axis in the window.
     * \param textContents a string representing what text will be displayed in the window.
     */
    sf::Text Utils::createText(const sf::Font& font, unsigned int fontSize, sf::Vector2f position, std::string textContents)
    {
        Log::log(Log::UTILS, Log::INFO, "Creating text: \"" + textContents + "\"...");

        sf::Text text;

        text.setFont(font);
        text.setCharacterSize(fontSize);
        text.setPosition(position);
        text.setString(textContents);

        return text;
    }
}
