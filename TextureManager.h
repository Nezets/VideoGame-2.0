//
// Created by Michael Ivanov on 11/30/2019.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::map;
using std::string;

class TextureManager {
    static map<string, sf::Texture> textures;
    static void LoadTexture(string textureName);
public:
    static sf::Texture& GetTexture(string textureName);

};

