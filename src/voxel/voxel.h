#pragma once

#include "voxel_info/infomanager.h"
#include "texture.h"

class Voxel {
    InfoManager im;
    Texture t;
    public:
    Voxel();
    ~Voxel();
    Response<InfoManager&> getIM();
    Response<Tile&> getTexture;
};