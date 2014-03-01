#pragma once
#include <vector>
#include "material.h"
#include "Chunk.h"
using namespace std;

class World {
	private:
		vector<Chunk> chunks;
	public:
		World();
		~World();
		bool newChunk(int, int);
//		bool chunkExists(int x, int y);
		//returns material for absolute coordinates
		Material get(int x, int y);
		//returns world coordinates for given chunk coordinates
		int* getAbsCoords(int chunkIndex, int x, int y);
		//returns chunk coordinates for absolute coordinates
		int* getChunkCoords(int x, int y);
//		//returns coordinates relative specific chunk for absolute coordinates
		Chunk getChunkByIndex(int index);
		int numOfChunks();
		int getChunkIndex(int x, int y);
		int chunkIndexAbove(int chunkIndex);
		int chunkIndexBelow(int chunkIndex);
		int chunkIndexLeft(int chunkIndex);
		int chunkIndexRight(int chunkIndex);
};