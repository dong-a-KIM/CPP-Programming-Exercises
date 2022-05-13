#pragma once
#include "Canvas_Week8_2.h"
#define DIM 40

class Monster {
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem; // 현재 위치와 먹은 아이템 수
	int nEnergy;
	
	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int** map) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy += 5;
		}
		else if (map[y][x] == 0) {
			nEnergy -= 5;
			if (nEnergy < 0) {
				nEnergy = 0;
			}
		}
	}
public:
	static int nMonsters;
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {nMonsters--;}
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n" << nMonsters--; }

	int getEnergy() {
		return nEnergy;
	}

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }
	void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	
	int printcount() {
		if (nEnergy == 0) {
				printf("전체 몬스터의 수 :%d", nMonsters);
				printf("\n몬스터 하나가 굶어죽습니다");
				int checkStarvation();
			}
		return nMonsters;
	}

	void print() {cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy <<"\n" << printcount() << endl; }
};
int Monster::nMonsters = 4;

