#pragma once
#include "_Canvas2.h"
#define DIM 40

class Monster {
	string name, icon;	// ���� �̸��� ȭ�� ��¿� ������
	int x, y, nItem;		// ���� ��ġ�� ���� ������ ��
	int nEnergy;            // "������"�� �����ϴ� �Ӽ�(Ȯ��1)

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
			nEnergy += 8; // �������� ������ ������ 8����(Ȯ��3)
		}
		else if (map[y][x] == 0) {
			nEnergy -= 1;
			if (nEnergy < 0) {
				nEnergy = 0;
			}
		} // �������� ���� ���ϸ� �������� 1 ���ҵǰ� �������� �ּҰ��� 0���� ����(Ȯ��3)
	}
public:
	Monster(string n = "������", string i = "��", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}
	// ��� ���� ��ü�� �������� 100�� �ǵ��� �������� ��� �ʱ�ȭ ����Ʈ �̿��ؼ� �ʱ�ȭ(Ȯ��2)
	~Monster() { cout << "\t" << name << icon << " �������ϴ�~~~\n"; }

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
	// ������ ������ ������ ��µǵ��� print()�Լ� ����(Ȯ��4)
};