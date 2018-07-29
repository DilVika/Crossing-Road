#include "CANIMAL.h"

//pixel = char(219)
void CANIMAL::Move(int, int)
{
}

void CANIMAL::Tell()
{
}

void CDINAUSOR::Draw() {
	// đến điểm đầu, vẽ ra điểm đầu
	gotoxy(x1, y1);
	cout << char(220);
	// đến điểm t2 vẽ ra 2 điểm cho tiết kiệm code chạy
	gotoxy(x2, y2);
	cout << char(219) << char(219);
	// tương tự trên
	gotoxy(x5, y5);
	cout << char(219) << char(219);
}
void CDINAUSOR::Delete()
{// tương tự hàm Draw
	gotoxy(x1, y1);
	cout << " ";
	gotoxy(x2, y2);
	cout << "  ";
	gotoxy(x5, y5);
	cout << "  ";
}
void CDINAUSOR::Move(int x)
{//x lả số bước đi, vị trí mới từng điểm +x
	Sleep(30);
	this->Delete();
	this->UpdatePos(x);
	//Sleep(50);
	this->Draw();

	//Hàm đếm giờ ( viết hàm riêng chạy thread riêng ) Tạm dùng sleep để test .
	Sleep(SLOW);
}

void CBIRD::Draw() {
	// đến điểm đầu, vẽ ra điểm đầu
	gotoxy(x1, y1);
	cout << char(220);
	// đến điểm t2 vẽ ra 2 điểm cho tiết kiệm code chạy
	gotoxy(x2, y2);
	cout << char(219) << char(219);
	// tương tự trên
	gotoxy(x5, y5);
	cout << char(219) << char(219);
}
void CBIRD::Delete()
{// tương tự hàm Draw
	gotoxy(x1, y1);
	cout << " ";
	gotoxy(x2, y2);
	cout << "  ";
	gotoxy(x5, y5);
	cout << "  ";
}
void CBIRD::Move(int x)
{//x lả số bước đi, vị trí mới từng điểm +x
	Sleep(30);
	this->Delete();
	this->UpdatePos(x);
	//Sleep(50);
	this->Draw();

	//Hàm đếm giờ ( viết hàm riêng chạy thread riêng ) Tạm dùng sleep để test .
	Sleep(SLOW);

	/*int i = 0, j = 0;
	while (true) {
	//WIDTH là tọa độ biên
	i++;


	this->Delete(i % WIDTH, y);
	this->Delete((i + LEVEL) % WIDTH, y);
	this->Delete((i + 2 * LEVEL) % WIDTH, y);
	this->Delete((i + 3 * LEVEL) % WIDTH, y);
	this->Delete((i + 4 * LEVEL) % WIDTH, y);
	this->Delete((i + 5 * LEVEL) % WIDTH, y);
	this->Delete((i + 6 * LEVEL) % WIDTH, y);
	//system("cls");
	//this->Draw(0.1, 10);
	this->Draw(i % WIDTH, y);
	this->Draw((i + LEVEL) % WIDTH, y);
	this->Draw((i + 2 * LEVEL) % WIDTH, y);
	this->Draw((i + 3 * LEVEL) % WIDTH, y);
	this->Draw((i + 4 * LEVEL) % WIDTH, y);
	this->Draw((i + 5 * LEVEL) % WIDTH, y);
	this->Draw((i + 6 * LEVEL) % WIDTH, y);

	Sleep(SLOW);
	}*/
}