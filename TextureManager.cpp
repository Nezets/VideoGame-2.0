//
// Created by Michael Ivanov on 11/30/2019.
//

#include "TextureManager.h"

map<string, sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(string textureName) {
    string path = "images/";
    path += textureName;
    path += ".png";
    textures[textureName].loadFromFile(path);
}

sf::Texture &TextureManager::GetTexture(string textureName) {
    if(textures.find(textureName) == textures.end()){
        LoadTexture(textureName);
    }
    return textures[textureName];
}
