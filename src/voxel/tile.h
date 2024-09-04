#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "../utils/response.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Layer {
    string path;
    size_t sl;
    sf::uint8& pixels;
    bool inMemory = false;
    Layer(string p, size_t sl);
    ~Layer();
    
}

class Tile {
    
};
