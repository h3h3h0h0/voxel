#pragma once

#include "./voxel/voxel.h"

using namespace std;

class Chunk {
    size_t sl; //a chunk is square, with the defined sidelength
    pair<int64_t, int64_t> bl; //bottom left voxel coordinates
    Voxel *content;
    bool populated = false;

    public:
    Chunk(pair<int64_t, int64_t> bl, size_t sl);
    ~Chunk();
    bool populateEmpty(); //populates the chunk with empty voxels and the set size
    bool populateFromFile(string f); //populates from a file
    bool depopulate(); //deallocate the voxel chunk
};