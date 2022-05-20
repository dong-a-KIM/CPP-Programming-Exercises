#pragma once
#include "Monster9_2.h"
#include "windows.h"

class Zombie : public Monster {
public:
	Zombie(string n = "ÇãÁ¢Á»ºñ", string i = "¡×", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "¹ìÆÄÀÌ¾î", string i = "¡Ú", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		
		
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "Ã³³à±Í½Å", string i = "¢¾", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
	bool	bHori;
public:
	Jiangshi(string n = "´ë·ú°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {
public:
	Smombi(string n = "½º¸öºñ", string i = "¡Û", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Smombi() { cout << "Smombi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--, y--;
		else if (dir == 1) x++, y++;
		else if (dir == 2) x--, y++;
		else x++, y--;
		clip(maxx, maxy);
		eat(map);
	}
};

class Siangshi : public Jiangshi {
	bool	bHori;
public:
	Siangshi(string n = "´ë·ú¼§½Ã", string i = "¡ã", int x = 0, int y = 0)
		: Jiangshi(n, i, x, y) {}
	~Siangshi() { cout << "Siangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) { 
			x += ((dir == 0) ? -jump : jump);
			Sleep(1000);
			if (!bHori) {
				y += ((dir == 0) ? -jump : jump);
			}
		}

		else if (bHori) { 
			y += ((dir == 0) ? -jump : jump);
			Sleep(1000);
			if (!bHori) {
				x += ((dir == 0) ? -jump : jump);
			}
		}
		clip(maxx, maxy);
		eat(map);
	}
};

class MyMonster : public Monster {
public:
	MyMonster(string n = "³ªÀÇ ¸ó½ºÅÍ", string i = "¢¼", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~MyMonster() { cout << "MyMonster"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		if (dir == 0) x--;
		else x++;
		clip(maxx, maxy);
		eat(map);
	}
};