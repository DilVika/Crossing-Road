#pragma once

#include"Header.h"
#include"CPEOPLE.h"
class CANIMAL {
public:
	CANIMAL() {};
	~CANIMAL() {};
	virtual void Move(int, int);
	virtual void Tell();
};

class CBIRD :public CANIMAL {
private:
	// tọa độ các điểm 
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x5, y5;
	int x6, y6;
public:
	CBIRD(int x, int y):CANIMAL() {
		// cái này tự vẽ ra rồi hình dung trước cái điểm sẽ vẽ ra
		x1 = x + 2;	y1 = y;
		x2 = x + 1;	y2 = y + 1;
		x3 = x + 2; y3 = y + 1;
		x5 = x; y5 = y + 2;
		x6 = x + 1; y6 = y + 2;
	}
	void UpdatePos(int x) {
		// cập nhật vị trí thêm x, nếu x của con vật > chiều dài console thì chia dư Witdh để quay lại đầu bên kia
		x1 = (x1 += x) % (WIDTH - 2);
		x2 = (x2 += x) % (WIDTH - 2);
		x3 = (x3 += x) % (WIDTH - 2);
		x5 = (x5 += x) % (WIDTH - 2);
		x6 = (x6 += x) % (WIDTH - 2);
		x1 += x1 > 3 ? 0 : 3;
		x2 += x1 > 3 ? 0 : 3;
		x3 += x1 > 3 ? 0 : 3;
		x5 += x1 > 3 ? 0 : 3;
		x6 += x1 > 3 ? 0 : 3;
	}
	void Draw();
	void Delete();
	void Move(int);
};

class CDINAUSOR :public CANIMAL {
private:
	// tọa độ các điểm 
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x5, y5;
	int x6, y6;
public:
	CDINAUSOR() {};
	CDINAUSOR(int x, int y) :CANIMAL() {
		// cái này tự vẽ ra rồi hình dung trước cái điểm sẽ vẽ ra
		x1 = x + 2;	y1 = y;
		x2 = x + 1;	y2 = y + 1;
		x3 = x + 2; y3 = y + 1;
		x5 = x; y5 = y + 2;
		x6 = x + 1; y6 = y + 2;
	}
	void UpdatePos(int x) {
		// cập nhật vị trí thêm x, nếu x của con vật > chiều dài console thì chia dư Witdh để quay lại đầu bên kia
		x1 = (x1 += x) % (WIDTH - 2);
		x2 = (x2 += x) % (WIDTH - 2);
		x3 = (x3 += x) % (WIDTH - 2);
		x5 = (x5 += x) % (WIDTH - 2);
		x6 = (x6 += x) % (WIDTH - 2);
		x1 += x1 > 3 ? 0 : 3;
		x2 += x1 > 3 ? 0 : 3;
		x3 += x1 > 3 ? 0 : 3;
		x5 += x1 > 3 ? 0 : 3;
		x6 += x1 > 3 ? 0 : 3;
	}
	void Draw();
	void Delete();
	void Move(int);
	bool CheckImp(CPEOPLE P){
		// hoặc set cái iMP CỦA PEOPLE THÀNH FALSE VÀ DỪNG CHƯƠNG TRÌNH
		int x=P.tellX(),y=P.tellY();
		if (this->x1 == x&&this->y1 == y) return true;
		if (this->x2 == x&&this->y2 == y) return true;
		if (this->x3 == x&&this->y3 == y) return true;
		if (this->x5 == x&&this->y5 == y) return true;
		if (this->x6 == x&&this->y6 == y) return true;
		return false;
	}
};