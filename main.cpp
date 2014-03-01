#include <tchar.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include "main.h"
#include "Nomad.h"
#include "Chunk.h"
#include "World.h"
#include "Artifact.h"
using namespace std;

World world = World();
//Material finiteWorld[gridSizeX][gridSizeY];
Nomad player;
bool showHud = true;

void printWorld();

void init() {
	int spawnX = 0;//rand() % viewportWidth;
	int spawnY = rand() % viewportHeight;
	
	//Place player
	while (world.getChunkByIndex(0).terrain[spawnX][spawnY] == WATER) {
		spawnX = rand() % viewportWidth;
		spawnY = rand() % viewportHeight;
	}
	player = Nomad(spawnX, spawnY);
	
	

	printWorld();
}

int _tmain(int argc, _TCHAR* argv[]) {
	bool quit = false;
	bool validIn = true;
	char input;
	init();

	//main loop
	while (!quit) {
		do {
			if (showHud) {
				cout << "> ";
			}
			cin >> input;
			switch (input) {
				case 'w':
					player.moveUp();
					validIn = true;
					break;
				case 's':
					player.moveDown();
					validIn = true;
					break;
				case 'a':
					player.moveLeft();
					validIn = true;
					break;
				case 'd':
					player.moveRight();
					validIn = true;
					break;
				default:
					cout << "Invalid input\n";
					validIn = false;
					break;
			}
		} while (!validIn);

		printWorld();
	}
	

	return 0;
}

void printWorld() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("cls");

	for (int y = viewportY; y < viewportY + viewportHeight; y++) {
		for (int x = viewportX; x < viewportX + viewportWidth;  x++) {
			if (player.getXpos() == x && player.getYpos() == y) {
				if (world.get(x, y) == WATER) {
					SetConsoleTextAttribute(hConsole, 63);
				} else {
					SetConsoleTextAttribute(hConsole, (16 * 6) + 15);
				}
				cout << ">" << (char) 277;
				//	 << (char) 244
			} else if (world.get(x, y) == SAND) {
				//Sets windows console text color
				SetConsoleTextAttribute(hConsole, 230);
				
				//Each switch statement corresponds to a character (Two characters are printed out for each square)
				switch (rand() % 6) {
					case 0: cout << (char) 176;
						break;
					case 1: cout << '*';
						break;
					case 2: cout << ' ';
						break;
					case 3: cout << '\"';
						break;
					case 4: cout << ',';
						break;
					case 5: cout << '\'';
						break;
				}
				switch (rand() % 6) {
					case 0: cout << (char) 176;
						break;
					case 1: cout << '*';
						break;
					case 2: cout << ' ';
						break;
					case 3: cout << '\"';
						break;
					case 4: cout << ',';
						break;
					case 5: cout << '\'';
						break;
				}
			} else if (world.get(x, y) == WATER) {
				SetConsoleTextAttribute(hConsole, 59);
				switch (rand() % 2) {
					case 0: cout << (char) 247 << (char) 247;
						break;
					case 1: cout << "~~";
						break;
				}
			//Non-generated
			} else if (world.get(x, y) == -1) {
				SetConsoleTextAttribute(hConsole, 10);
				switch (rand() % 2) {
					case 0: cout << '?';
						break;
					case 1: cout << 'X';
						break;
				}
				switch (rand() % 2) {
					case 0: cout << '?';
						break;
					case 1: cout << 'X';
						break;
				}
			//Other
			} else {
				SetConsoleTextAttribute(hConsole, 255);
				cout << "  ";
			}
		}
		cout << endl;
	}
	//reset console text color
	SetConsoleTextAttribute(hConsole, 7);

	//HUD
	if (showHud) {
		cout << "Number of Chunks: " << world.numOfChunks() << endl;
		cout << "Current Chunk: " << player.getCurrentChunk() << endl;
		cout << "Position: " << player.getXpos() << ", " << player.getYpos() << endl;
	}
	//if current position is generated, but not valid
	if (world.get(player.getXpos(), player.getYpos()) != SAND &&
			world.get(player.getXpos(), player.getYpos()) != WATER &&
			world.get(player.getXpos(), player.getYpos()) != -1) {
		cout << "Value: " << std::hex << world.get(player.getXpos(), player.getYpos()) << std::dec << endl;
	}
//	Artifact x("Swarm", "...");
//	x.print();
}