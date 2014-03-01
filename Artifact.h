#pragma once
#include "object.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Artifact : public Object {
	private:
		string name;
		string message;
		
		void init(string name, string message, int x, int y) {
			collectable = true;
			obstacle = false;
			xpos = x;
			ypos = y;
			this->name = name;
			this->message = message;
		}
	public:
		Artifact(string name, string message) {
			init(name, message, 0, 0);
		}
		Artifact(string name, string message, int x, int y) {
			init(name, message, x, y);
		}

		virtual void onContact() {}
		
		virtual void interact() {
			print();
		}
		
		virtual void print() {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 110);
			
			cout << " /-   -\\ " << endl;
			cout <<	" |  0  | " << endl;
			cout << "<       >" << endl;
			cout << " |     | " << endl;
			cout << " \\-   -/ " << endl;

			SetConsoleTextAttribute(hConsole, 7);
		}
};