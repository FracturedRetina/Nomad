#include "material.h"
#include "constants.h"

#ifndef CHUNK_H
#define CHUNK_H

struct Chunk {
	Chunk(int xRelToSpawn, int yRelToSpawn);
	Material terrain[chunkWidth][chunkHeight];
	int xpos;
	int ypos;
};
#endif