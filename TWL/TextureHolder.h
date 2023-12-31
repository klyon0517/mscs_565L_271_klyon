#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class TextureHolder
{
private:
    // A map container from the STL,
    // that holds related pairs of String and Texture
    std::map<std::string, sf::Texture> m_Textures;

    // A pointer of the same type of class itself
    // the one and only instance
    static TextureHolder* m_s_Instance;

public:
    TextureHolder();
    static sf::Texture& GetTexture(std::string const& filename);
};
