#pragma once

#include "voxel_info/infomanager.h"
#include "../utils/automation.h"
#include "tile.h"
#include <functional>

using namespace std;

class Voxel {
    InfoManager im;
    Tile t;
    unordered_map<string, Automation<InfoManager>> info_automations;
    unordered_map<string, Automation<Tile>> tile_automations;
    public:
    Voxel();
    ~Voxel();
    InfoManager &getIM();
    InfoManager &getTile();
    bool trigger(string s); //trigger all automations matching the string on the map
    void setInfoAutomation(string trig, function<bool(InfoManager)> f);
    void setTileAutomation(string trig, function<bool(Tile)> f);
    bool removeInfoAutomation(string trig);
    bool removeTileAutomation(string trig);
};