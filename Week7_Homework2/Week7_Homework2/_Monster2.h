#pragma once
#include "_Canvas2.h"
#define DIM 40

class Monster {
	string name, icon;	// 몬스터 이름과 화면 출력용 아이콘
	int x, y, nItem;		// 현재 위치와 먹은 아이템 수
	int nEnergy;            // "에너지"를 저장하는 속성(확장1)

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int map[DIM][DIM]) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy += 8; // 아이템을 먹으면 에너지 8증가(확장3)
		}
		else if (map[y][x] == 0) {
			nEnergy -= 1;
			if (nEnergy < 0) {
				nEnergy = 0;
			}
		} // 아이템을 먹지 못하면 에너지가 1 감소되고 에너지의 최소값은 0으로 설정(확장3)
	}
public:
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}
	// 모든 몬스터 객체의 에너지가 100이 되도록 생성자의 멤버 초기화 리스트 이용해서 초기화(확장2)
	~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~\n"; }

	void draw(Canvas &canvas) { canvas.draw(x, y, icon); }
	void move(int map[DIM][DIM], int maxx, int maxy) {
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
	void print() { cout << "\t" << name << icon << ":" << nItem << "E:" << nEnergy << endl;}
	// 현재의 에너지 레벨이 출력되도록 print()함수 수정(확장4)
};