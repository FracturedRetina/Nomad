#include "Chunk.h"
#include <iostream>
#include <time.h>
using namespace std;

Chunk::Chunk(int xRelToSpawn, int yRelToSpawn) {
	//Sets random seed to current time
	srand(time(NULL));
	
	cout << "Generating chunk...\n";
	xpos = xRelToSpawn;
	ypos = yRelToSpawn;
	cout << "	Seeding terrain...";
	//seed terrain
	for (int y = 0; y < chunkHeight; y++) {
		for (int x = 0; x < chunkWidth; x++) {
			if (rand() % 64 == 0) {
				terrain[x][y] = WATER;
			} else {
				terrain[x][y] = SAND;
			}
		}
	}
	cout << "Done!\n";
	//formations
	//lakes
	cout << "	Generating formations...";
	for (int y = 0; y < chunkHeight; y++) {
		for (int x = 0; x < chunkWidth;  x++) {
			if (terrain[x][y] == WATER) {
				if (x > 0 && rand() % 4 == 0)
					terrain[x - 1][y] = WATER;
				if (x < chunkWidth - 1 && rand() % 4 == 0)
					terrain[x + 1][y] = WATER;
				if (y > 0 && rand() % 4 == 0)
					terrain[x][y - 1] = WATER;
				if (y < chunkHeight - 1 && rand() % 4 == 0)
					terrain[x][y + 1] = WATER;
			}
		}
	}
//	//Fill invalid spaces
//	for (int y = 0; y < chunkHeight; y++) {
//		for (int x = 0; x < chunkWidth;  x++) {
//			if (terrain[x][y] != SAND || terrain[x][y] != WATER) {
//				terrain[x][y] == SAND;
//			}
//		}
//	}
	cout << "Done!\n";
	cout << "Done!\n";
}