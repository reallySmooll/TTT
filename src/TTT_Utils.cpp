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

    // Function to calculate FPS.
    void Utils::showFPS(sf::RenderWindow& window, const sf::Font& font, unsigned int fontSize, sf::Color color)
    {
        frameCount++;

        const float elapsedTime = clock.getElapsedTime().asSeconds();

        if (elapsedTime >= 0.1f)
        {
            const float fps = frameCount / (elapsedTime - startTime);

            ss.str("");
            ss << "FPS: " << std::floor(fps);

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

    // Function to create a font and load it. Shortens the amount of code that has to be written.
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

    // Function to create and load a texture to a sprite. Shortens the amount of code that has to be written.
    // Texture variable has to be created manually and passed as a paramter to the function because the sprites
    // act weird when the texture is created in the function.
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

    void Utils::sleepFor(int timeInSeconds)
    {
        Log::log(Log::UTILS, Log::INFO, "Sleeping for " + std::to_string(timeInSeconds) + "s...");

        std::chrono::seconds timespan(timeInSeconds);
        std::this_thread::sleep_for(timespan);
    }

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
