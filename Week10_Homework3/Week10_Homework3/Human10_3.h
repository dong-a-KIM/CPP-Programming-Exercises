#pragma once
#include "Monster10_3.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
enum Direction2 { a = 75, d = 77, w = 72, s = 80 };


class Human : public Monster {
public:
	Human(string n = "미래좌파", string i = "좌", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) {
			char ch = getDirKey();
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "미래우파", string i = "우", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " [Tuman   ]"; }
	int getchar() { return _getche() == 224 ? _getche() : 0; }
	void moveHuman(int** map, int maxx, int maxy) {
		if (getchar()) {
			char ch = getchar();
			switch (ch) {
			case a: x--; break;
			case d: x++; break;
			case w: y--; break;
			case s: y++; break;
			}
			clip(maxx, maxy);
			eat(map);
		}
	}
};