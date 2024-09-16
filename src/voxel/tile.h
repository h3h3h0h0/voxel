#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "../utils/response.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Layer {
    uint16_t priority;
    string path;
    sf::Image *im = NULL;
    bool inMemory = false;

    public:
    Layer(uint16_t pr, string pa);
    Layer(const Layer &src);
    Layer(Layer &&src);
    ~Layer();
    bool Load();
    bool Unload();
    Response<sf::Texture> makeTexture();
    bool updateTexture(sf::Texture &t);
    uint16_t getPriority;
    void setPriority(uint16_t p);
};

class Tile {
    vector<Layer> layers;

    public:
    Tile() = default;
    ~Tile() = default;
    Response<Layer&> getWithPriority(uint16_t p);
    Response<Layer&> getWithIdx(size_t i);
    //note: we will only allow priorities that do not overlap, otherwise adding will FAIL
    bool add(const Layer &src); //COPY CTOR!
    bool moveAdd(Layer &src); //MOVE CTOR!
    bool inplaceAdd(uint16_t pr, string pa);
    bool removePriority(uint16_t p);
    bool removeIdx(size_t i);
};
