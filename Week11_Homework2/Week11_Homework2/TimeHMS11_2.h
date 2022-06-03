#pragma once
#include <time.h>
#include <iostream>
#include <string>
using namespace std;
#include "Point11_2.h"

class TimeHMS {
	int hour, min, sec;
public:
	TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

	void time_add(TimeHMS x, TimeHMS y) {
		if (0 <= (min, sec) <= 59) {
			hour = x.hour + y.hour;
			min = x.min + y.min;
			sec = x.sec + y.sec;
			if ((min, sec) >= 60) {
				min -= 60;
				sec -= 60;
			}
		}
	}

	void time_sub(TimeHMS x, TimeHMS y) {
		if (0 <= (min, sec) <= 59) {
			hour = x.hour - y.hour;
			min = x.min - y.min;
			sec = x.sec - y.sec;
		}
	}

	bool operator ==(TimeHMS x) { return hour == x.hour && min == x.min && sec == x.sec; }
	bool operator !=(TimeHMS x) { return hour != x.hour || min != x.min || sec != x.sec; }

	TimeHMS& operator++ () {
		hour += 1;
		return *this;
	}

	TimeHMS& operator-- () {
		hour -= 1;
		return *this;
	}

	TimeHMS operator++ (int) {
		sec += 1;
		return TimeHMS(sec - 1, 1);
	}

	TimeHMS operator-- (int) {
		sec -= 1;
		return TimeHMS(sec + 1, 1);
	}

	operator double() {
		return (double)t1;
	}

	operator int() {
		return (int)t1;
	}

	int& operator[](int id) {
		if (id == 0) return hour;
		else if (id == 1)return min;
		else if (id == 2)return sec;
		else exit(0);
	}
	int& operator()(int id) { return (*this)[id]; }

	TimeHMS operator * (TimeHMS& t1) {
		TimeHMS mul(t1.hour);
		TimeHMS mul(t1.min);
		TimeHMS mul(t1.sec);
		if (0 <= (min, sec) <= 59) {
			for (int i = 0; i < hour; i++) {
				for (int i = 0; i < min; i++) {
					for (int i = 0; i < min; i++) {
						mul[i] = 2 * t1[i];
						return mul;
						if ((min, sec >= 60)) {
							min -= 60;
							sec -= 60;
						}
					}
				}
			}
		}
	}

};
TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;