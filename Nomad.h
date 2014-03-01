#pragma once

class Nomad {
	private:
		int xpos;
		int ypos;
		int currentChunk;
	public:
		Nomad();
		Nomad(int xpos, int ypos);
		int getXpos();
		int getYpos();
		int getCurrentChunk();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
};