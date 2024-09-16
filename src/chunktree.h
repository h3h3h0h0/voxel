#pragma once

#include "chunk.h"
#include "./utils/response.h"

using namespace std;

enum loadstate { // how much of the particular node is loaded?
    NONE,
    PARTIAL,
    FULL
};

class ChunkTree {
    size_t sl; //side length in voxels
    pair<int64_t, int64_t> bl; //bottom left voxel coordinates

    bool isLeaf;
    loadstate state;

    ChunkTree *q00 = NULL;
    ChunkTree *q01 = NULL;
    ChunkTree *q10 = NULL;
    ChunkTree *q11 = NULL;

    Chunk *contents = NULL;

    public:
    ChunkTree(Chunk c); //create a leaf node
    ChunkTree(); //create an unloaded node
    bool load(pair<int64_t, int64_t> p1, pair<int64_t, int64_t> p2);
    //do later idk
};