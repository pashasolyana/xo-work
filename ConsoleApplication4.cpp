#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <time.h>

using namespace std;

string matrix[9] = { "1", "2","3", "4", "5","6", "7","8", "9" };
string matrix4[16] = { "1", "2","3", "4", "5","6", "7","8", "9", "10","11", "12", "13","14", "15","16" };
string matrix5[25] = { "1", "2","3", "4", "5","6", "7","8", "9", "10","11", "12", "13","14", "15","16","17","18","19","20", "21", "22", "23","24","25" };
string player = "x";
string playerx = "x";
string playero = "o";

string firstMove = "x";
string botWin;

string xWin = "1";
string oWin = "0";
int gameMode = 1;
int n = 0;
int a;
bool start = true;
bool botWork = true;
int FieldSize = 3;
int randomMove = 0;

string xColor = "92";
string oColor = "93";
string botMove;


struct PRNG
{
	unsigned seed = 0;
};
void initGenerator(PRNG& generator)
{
	// Получаем случайное зерно последовательности
	generator.seed = unsigned(std::time(nullptr));
}
unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
	// Проверяем корректность аргументов
	assert(minValue < maxValue);
	// Итеративно изменяем текущее число в генераторе
	generator.seed = (generator.seed * 73129 + 95121);

	// Приводим число к отрезку [minValue, maxValue]
	return (generator.seed % (maxValue + 1 - minValue)) + minValue;
}

void drawField() {
	system("cls");
	cout << matrix[0] << " " << matrix[1] << " " << matrix[2] << endl;
	cout << matrix[3] << " " << matrix[4] << " " << matrix[5] << endl;
	cout << matrix[6] << " " << matrix[7] << " " << matrix[8] << endl;
}
void drawField4() {
	system("cls");
	cout << matrix4[0] << " | " << matrix4[1] << " | " << matrix4[2] << " | " << matrix4[3] << endl;
	cout << matrix4[4] << " | " << matrix4[5] << " | " << matrix4[6] << " | " << matrix4[7] << endl;
	cout << matrix4[8] << " | " << matrix4[9] << "| " << matrix4[10] << "| " << matrix4[11] << endl;
	cout << matrix4[12] << "| " << matrix4[13] << "| " << matrix4[14] << "| " << matrix4[15] << endl;
}
void drawField5() {
	system("cls");
	cout << matrix5[0] << "  | " << matrix5[1] << "  | " << matrix5[2] << "  | " << matrix5[3] << "  | " << matrix5[4] << endl;
	cout << matrix5[5] << "  | " << matrix5[6] << "  | " << matrix5[7] << "  | " << matrix5[8] << "  | " << matrix5[9] << endl;
	cout << matrix5[10] << " | " << matrix5[11] << " | " << matrix5[12] << " | " << matrix5[13] << " | " << matrix5[14] << endl;
	cout << matrix5[15] << " | " << matrix5[16] << " | " << matrix5[17] << " | " << matrix5[18] << " | " << matrix5[19] << endl;
	cout << matrix5[20] << " | " << matrix5[21] << " | " << matrix5[22] << " | " << matrix5[23] << " | " << matrix5[24] << endl;

}

void input() {

	if (start == true) {
		if (player == playerx) {
			cout << "x press the number";
		}
		else if (player == playero) {
			cout << "o press the number";
		}
		cin >> a;

		if (a == 1) {
			if (matrix[0] == "1" and player == playerx) {
				matrix[0] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[0] == "1" and player == playero) {
				matrix[0] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 2) {
			if (matrix[1] == "2" and player == playerx) {
				matrix[1] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[1] == "2" and player == playero) {
				matrix[1] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 3) {
			if (matrix[2] == "3" and player == playerx) {
				matrix[2] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[2] == "3" and player == playero) {
				matrix[2] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 4) {
			if (matrix[3] == "4" and player == playerx) {
				matrix[3] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[3] == "4" and player == playero) {
				matrix[3] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 5) {
			if (matrix[4] == "5" and player == playerx) {
				matrix[4] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[4] == "5" and player == playero) {
				matrix[4] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 6) {
			if (matrix[5] == "6" and player == playerx) {
				matrix[5] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[5] == "6" and player == playero) {
				matrix[5] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 7) {
			if (matrix[6] == "7" and player == playerx) {
				matrix[6] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[6] == "7" and player == playero) {
				matrix[6] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 8) {
			if (matrix[7] == "8" and player == playerx) {
				matrix[7] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[7] == "8" and player == playero) {
				matrix[7] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else if (a == 9) {
			if (matrix[8] == "9" and player == playerx) {
				matrix[8] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix[8] == "9" and player == playero) {
				matrix[8] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input();
			}
		}
		else {
			cout << "Значение не корректно" << endl;
			input();
		}
		drawField();
	}

}
void input4x4() {

	if (start == true) {
		if (player == playerx) {
			cout << "x press the number";
		}
		else if (player == playero) {
			cout << "o press the number";
		}
		cin >> a;

		if (a == 1) {
			if (matrix4[0] == "1" and player == playerx) {
				matrix4[0] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[0] == "1" and player == playero) {
				matrix4[0] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 2) {
			if (matrix4[1] == "2" and player == playerx) {
				matrix4[1] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[1] == "2" and player == playero) {
				matrix4[1] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 3) {
			if (matrix4[2] == "3" and player == playerx) {
				matrix4[2] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[2] == "3" and player == playero) {
				matrix4[2] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 4) {
			if (matrix4[3] == "4" and player == playerx) {
				matrix4[3] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[3] == "4" and player == playero) {
				matrix4[3] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 5) {
			if (matrix4[4] == "5" and player == playerx) {
				matrix4[4] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[4] == "5" and player == playero) {
				matrix4[4] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 6) {
			if (matrix4[5] == "6" and player == playerx) {
				matrix4[5] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[5] == "6" and player == playero) {
				matrix4[5] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 7) {
			if (matrix4[6] == "7" and player == playerx) {
				matrix4[6] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[6] == "7" and player == playero) {
				matrix4[6] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 8) {
			if (matrix4[7] == "8" and player == playerx) {
				matrix4[7] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[7] == "8" and player == playero) {
				matrix4[7] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();;
			}
		}
		else if (a == 9) {
			if (matrix4[8] == "9" and player == playerx) {
				matrix4[8] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[8] == "9" and player == playero) {
				matrix4[8] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 10) {
			if (matrix4[9] == "10" and player == playerx) {
				matrix4[9] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[9] == "10" and player == playero) {
				matrix4[9] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 11) {
			if (matrix4[10] == "11" and player == playerx) {
				matrix4[10] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[10] == "11" and player == playero) {
				matrix4[10] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 12) {
			if (matrix4[11] == "12" and player == playerx) {
				matrix4[11] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[11] == "12" and player == playero) {
				matrix4[11] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 13) {
			if (matrix4[12] == "13" and player == playerx) {
				matrix4[12] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[12] == "13" and player == playero) {
				matrix4[12] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 14) {
			if (matrix4[13] == "14" and player == playerx) {
				matrix4[13] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[13] == "14" and player == playero) {
				matrix4[13] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 15) {
			if (matrix4[14] == "15" and player == playerx) {
				matrix4[14] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[14] == "15" and player == playero) {
				matrix4[14] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else if (a == 16) {
			if (matrix4[15] == "16" and player == playerx) {
				matrix4[15] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix4[15] == "16" and player == playero) {
				matrix4[15] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input4x4();
			}
		}
		else {
			cout << "Значение не корректно" << endl;
			input4x4();
		}
		drawField4();
	}

}
void input5x5() {
	if (start == true) {
		if (player == playerx) {
			cout << "x press the number";
		}
		else if (player == playero) {
			cout << "o press the number";
		}
		cin >> a;

		if (a == 1) {
			if (matrix5[0] == "1" and player == playerx) {
				matrix5[0] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[0] == "1" and player == playero) {
				matrix5[0] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 2) {
			if (matrix5[1] == "2" and player == playerx) {
				matrix5[1] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[1] == "2" and player == playero) {
				matrix5[1] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 3) {
			if (matrix5[2] == "3" and player == playerx) {
				matrix5[2] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[2] == "3" and player == playero) {
				matrix5[2] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 4) {
			if (matrix5[3] == "4" and player == playerx) {
				matrix5[3] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[3] == "4" and player == playero) {
				matrix5[3] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 5) {
			if (matrix5[4] == "5" and player == playerx) {
				matrix5[4] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[4] == "5" and player == playero) {
				matrix5[4] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 6) {
			if (matrix5[5] == "6" and player == playerx) {
				matrix5[5] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[5] == "6" and player == playero) {
				matrix5[5] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 7) {
			if (matrix5[6] == "7" and player == playerx) {
				matrix5[6] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[6] == "7" and player == playero) {
				matrix5[6] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 8) {
			if (matrix5[7] == "8" and player == playerx) {
				matrix5[7] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[7] == "8" and player == playero) {
				matrix5[7] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();;
			}
		}
		else if (a == 9) {
			if (matrix5[8] == "9" and player == playerx) {
				matrix5[8] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[8] == "9" and player == playero) {
				matrix5[8] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 10) {
			if (matrix5[9] == "10" and player == playerx) {
				matrix5[9] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[9] == "10" and player == playero) {
				matrix5[9] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 11) {
			if (matrix5[10] == "11" and player == playerx) {
				matrix5[10] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[10] == "11" and player == playero) {
				matrix5[10] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 12) {
			if (matrix5[11] == "12" and player == playerx) {
				matrix5[11] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[11] == "12" and player == playero) {
				matrix5[11] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 13) {
			if (matrix5[12] == "13" and player == playerx) {
				matrix5[12] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[12] == "13" and player == playero) {
				matrix5[12] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 14) {
			if (matrix5[13] == "14" and player == playerx) {
				matrix5[13] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[13] == "14" and player == playero) {
				matrix5[13] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 15) {
			if (matrix5[14] == "15" and player == playerx) {
				matrix5[14] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[14] == "15" and player == playero) {
				matrix5[14] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 16) {
			if (matrix5[15] == "16" and player == playerx) {
				matrix5[15] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[15] == "16" and player == playero) {
				matrix5[15] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 17) {
			if (matrix5[16] == "17" and player == playerx) {
				matrix5[16] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[16] == "17" and player == playero) {
				matrix5[16] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 18) {
			if (matrix5[17] == "18" and player == playerx) {
				matrix5[17] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[17] == "18" and player == playero) {
				matrix5[17] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 19) {
			if (matrix5[18] == "19" and player == playerx) {
				matrix5[18] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[18] == "19" and player == playero) {
				matrix5[18] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 20) {
			if (matrix5[19] == "20" and player == playerx) {
				matrix5[19] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[19] == "20" and player == playero) {
				matrix5[19] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 21) {
			if (matrix5[20] == "21" and player == playerx) {
				matrix5[20] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[20] == "21" and player == playero) {
				matrix5[20] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 22) {
			if (matrix5[21] == "22" and player == playerx) {
				matrix5[21] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[21] == "22" and player == playero) {
				matrix5[21] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 23) {
			if (matrix5[22] == "23" and player == playerx) {
				matrix5[22] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[22] == "23" and player == playero) {
				matrix5[22] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 24) {
			if (matrix5[23] == "24" and player == playerx) {
				matrix5[23] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[23] == "24" and player == playero) {
				matrix5[23] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else if (a == 25) {
			if (matrix5[24] == "25" and player == playerx) {
				matrix5[24] = "\x1b[" + xColor + "m" + playerx + "\x1b[0m";
			}
			else if (matrix5[24] == "25" and player == playero) {
				matrix5[24] = "\x1b[" + oColor + "m" + playero + "\x1b[0m";
			}
			else {
				cout << "Zanyato chel.." << endl;
				input5x5();
			}
		}
		else {
			cout << "Значение не корректно" << endl;
			input5x5();
		}
		drawField5();
	}
}

void botInput() {
	while (botWork == true) {
		PRNG generator;
		initGenerator(generator);
		randomMove = random(generator, 1, 9);
		if (randomMove == 1 && matrix[0] == "1" && botMove == "x") {
			matrix[0] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 1 && matrix[0] == "1" && botMove == "o") {
			matrix[0] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 2 && matrix[1] == "2" && botMove == "x") {
			matrix[1] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 2 && matrix[1] == "2" && botMove == "o") {
			matrix[1] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 3 && matrix[2] == "3" && botMove == "x") {
			matrix[2] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 3 && matrix[2] == "3" && botMove == "o") {
			matrix[2] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 4 && matrix[3] == "4" && botMove == "x") {
			matrix[3] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 4 && matrix[3] == "4" && botMove == "o") {
			matrix[3] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 5 && matrix[4] == "5" && botMove == "x") {
			matrix[4] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 5 && matrix[4] == "5" && botMove == "o") {
			matrix[4] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}

		else if (randomMove == 6 && matrix[5] == "6" && botMove == "x") {
			matrix[5] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 6 && matrix[5] == "6" && botMove == "o") {
			matrix[5] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}

		else if (randomMove == 7 && matrix[6] == "7" && botMove == "x") {
			matrix[6] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 7 && matrix[6] == "7" && botMove == "o") {
			matrix[6] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}

		else if (randomMove == 8 && matrix[7] == "8" && botMove == "x") {
			matrix[7] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 8 && matrix[7] == "8" && botMove == "o") {
			matrix[7] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}

		else if (randomMove == 9 && matrix[8] == "9" && botMove == "x") {
			matrix[8] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 9 && matrix[8] == "9" && botMove == "o") {
			matrix[8] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
	}
}
void botInput4x4() {
	while (botWork == true) {
		PRNG generator;
		initGenerator(generator);
		randomMove = random(generator, 1, 16);
		if (randomMove == 1 && matrix4[0] == "1" && botMove == "x") {
			matrix4[0] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 1 && matrix4[0] == "1" && botMove == "o") {
			matrix4[0] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 2 && matrix4[1] == "2" && botMove == "x") {
			matrix4[1] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 2 && matrix4[1] == "2" && botMove == "o") {
			matrix4[1] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 3 && matrix4[2] == "3" && botMove == "x") {
			matrix4[2] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 3 && matrix4[2] == "3" && botMove == "o") {
			matrix4[2] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 4 && matrix4[3] == "4" && botMove == "x") {
			matrix4[3] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 4 && matrix4[3] == "4" && botMove == "o") {
			matrix4[3] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 5 && matrix4[4] == "5" && botMove == "x") {
			matrix4[4] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 5 && matrix4[4] == "5" && botMove == "o") {
			matrix4[4] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 6 && matrix4[5] == "6" && botMove == "x") {
			matrix4[5] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 6 && matrix4[5] == "6" && botMove == "o") {
			matrix4[5] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 7 && matrix4[6] == "7" && botMove == "x") {
			matrix4[6] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 7 && matrix4[6] == "7" && botMove == "o") {
			matrix4[6] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 8 && matrix4[7] == "8" && botMove == "x") {
			matrix4[7] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 8 && matrix4[7] == "8" && botMove == "o") {
			matrix4[7] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 9 && matrix4[8] == "9" && botMove == "x") {
			matrix4[8] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 9 && matrix4[8] == "9" && botMove == "o") {
			matrix4[8] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 10 && matrix4[9] == "10" && botMove == "x") {
			matrix4[9] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 10 && matrix4[9] == "10" && botMove == "o") {
			matrix4[9] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 11 && matrix4[10] == "11" && botMove == "x") {
			matrix4[10] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 11 && matrix4[10] == "11" && botMove == "o") {
			matrix4[10] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 12 && matrix4[11] == "12" && botMove == "x") {
			matrix4[11] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 12 && matrix4[11] == "12" && botMove == "o") {
			matrix4[11] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 13 && matrix4[12] == "13" && botMove == "x") {
			matrix4[12] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 13 && matrix4[12] == "13" && botMove == "o") {
			matrix4[12] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 14 && matrix4[13] == "14" && botMove == "x") {
			matrix4[13] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 14 && matrix4[13] == "14" && botMove == "o") {
			matrix4[13] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 15 && matrix4[14] == "15" && botMove == "x") {
			matrix4[14] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 15 && matrix4[14] == "15" && botMove == "o") {
			matrix4[14] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 16 && matrix4[15] == "16" && botMove == "x") {
			matrix4[15] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 16 && matrix4[15] == "16" && botMove == "o") {
			matrix4[15] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
	}
	drawField4();
}
void botInput5x5() {
	while (botWork == true) {
		PRNG generator;
		initGenerator(generator);
		randomMove = random(generator, 1, 25);
		if (randomMove == 1 && matrix5[0] == "1" && botMove == "x") {
			matrix5[0] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 1 && matrix5[0] == "1" && botMove == "o") {
			matrix5[0] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 2 && matrix5[1] == "2" && botMove == "x") {
			matrix5[1] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 2 && matrix5[1] == "2" && botMove == "o") {
			matrix5[1] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 3 && matrix5[2] == "3" && botMove == "x") {
			matrix5[2] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 3 && matrix5[2] == "3" && botMove == "o") {
			matrix5[2] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 4 && matrix5[3] == "4" && botMove == "x") {
			matrix5[3] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 4 && matrix5[3] == "4" && botMove == "o") {
			matrix5[3] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 5 && matrix5[4] == "5" && botMove == "x") {
			matrix5[4] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 5 && matrix5[4] == "5" && botMove == "o") {
			matrix5[4] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 6 && matrix5[5] == "6" && botMove == "x") {
			matrix5[5] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 6 && matrix5[5] == "6" && botMove == "o") {
			matrix5[5] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 7 && matrix5[6] == "7" && botMove == "x") {
			matrix5[6] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 7 && matrix5[6] == "7" && botMove == "o") {
			matrix5[6] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 8 && matrix5[7] == "8" && botMove == "x") {
			matrix5[7] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;

		}
		else if (randomMove == 8 && matrix5[7] == "8" && botMove == "o") {
			matrix5[7] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 9 && matrix5[8] == "9" && botMove == "x") {
			matrix5[8] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 9 && matrix5[8] == "9" && botMove == "o") {
			matrix5[8] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 10 && matrix5[9] == "10" && botMove == "x") {
			matrix5[9] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 10 && matrix5[9] == "10" && botMove == "o") {
			matrix5[9] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 11 && matrix5[10] == "11" && botMove == "x") {
			matrix5[10] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 11 && matrix5[10] == "11" && botMove == "o") {
			matrix5[10] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 12 && matrix5[11] == "12" && botMove == "x") {
			matrix5[11] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 12 && matrix5[11] == "12" && botMove == "o") {
			matrix5[11] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 13 && matrix5[12] == "13" && botMove == "x") {
			matrix5[12] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 13 && matrix5[12] == "13" && botMove == "o") {
			matrix5[12] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 14 && matrix5[13] == "14" && botMove == "x") {
			matrix5[13] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 14 && matrix5[13] == "14" && botMove == "o") {
			matrix5[13] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 15 && matrix5[14] == "15" && botMove == "x") {
			matrix5[14] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 15 && matrix5[14] == "15" && botMove == "o") {
			matrix5[14] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 16 && matrix5[15] == "16" && botMove == "x") {
			matrix5[15] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 16 && matrix5[15] == "16" && botMove == "o") {
			matrix5[15] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 17 && matrix5[16] == "17" && botMove == "x") {
			matrix5[16] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 17 && matrix5[16] == "17" && botMove == "o") {
			matrix5[16] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 18 && matrix5[17] == "18" && botMove == "x") {
			matrix5[17] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 18 && matrix5[17] == "18" && botMove == "o") {
			matrix5[17] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 19 && matrix5[18] == "19" && botMove == "x") {
			matrix5[18] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 19 && matrix5[18] == "19" && botMove == "o") {
			matrix5[18] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 20 && matrix5[19] == "20" && botMove == "x") {
			matrix5[19] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 20 && matrix5[19] == "20" && botMove == "o") {
			matrix5[19] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 21 && matrix5[20] == "21" && botMove == "x") {
			matrix5[20] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 21 && matrix5[20] == "21" && botMove == "o") {
			matrix5[20] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 22 && matrix5[21] == "22" && botMove == "x") {
			matrix5[21] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 22 && matrix5[21] == "22" && botMove == "o") {
			matrix5[21] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 23 && matrix5[22] == "23" && botMove == "x") {
			matrix5[22] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 23 && matrix5[22] == "23" && botMove == "o") {
			matrix5[22] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 24 && matrix5[23] == "24" && botMove == "x") {
			matrix5[23] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 24 && matrix5[23] == "24" && botMove == "o") {
			matrix5[23] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}

		else if (randomMove == 25 && matrix5[24] == "25" && botMove == "x") {
			matrix5[24] = "\x1b[" + xColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		else if (randomMove == 25 && matrix5[24] == "25" && botMove == "o") {
			matrix5[24] = "\x1b[" + oColor + "m" + botMove + "\x1b[0m";
			botWork = false;
		}
		
	}
	drawField5();
}

void checkFirstMoveWithBot() {
	if (firstMove == "x") {
		botMove = "x";
		player = "o";
		firstMove = "";
	}
	else if (firstMove == "o") {
		botMove = "o";
		player = "x";
		firstMove = "";
	}
}
void checkFirstMove() {
	if (firstMove == "x") {
		player = "x";
		firstMove = "";
	}
	else if (firstMove == "o") {
		player = "o";
		firstMove = "";
	}
}
void ChangePlayer() {
	if (player == "x") {
		player = "o";
	}
	else if (player == "o") {
		player = "x";
	}
}

string win() {

	if (matrix[0] == matrix[1] && matrix[1] == matrix[2] && player == "x") {
		return xWin;
	}
	else if (matrix[3] == matrix[4] && matrix[4] == matrix[5] && player == "x") {
		return xWin;
	}
	else if (matrix[6] == matrix[7] && matrix[7] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[3] && matrix[3] == matrix[6] && player == "x") {
		return xWin;
	}
	else if (matrix[1] == matrix[4] && matrix[4] == matrix[7] && player == "x") {
		return xWin;
	}
	else if (matrix[2] == matrix[5] && matrix[5] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[4] && matrix[4] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[2] == matrix[4] && matrix[4] == matrix[6] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[1] && matrix[1] == matrix[2] && player == "x") {
		return oWin;
	}
	else if (matrix[3] == matrix[4] && matrix[4] == matrix[5] && player == "o") {
		return oWin;
	}
	else if (matrix[6] == matrix[7] && matrix[7] == matrix[8] && player == "o") {
		return oWin;
	}
	else if (matrix[0] == matrix[3] && matrix[3] == matrix[6] && player == "o") {
		return oWin;
	}
	else if (matrix[1] == matrix[4] && matrix[4] == matrix[7] && player == "o") {
		return oWin;
	}
	else if (matrix[2] == matrix[5] && matrix[5] == matrix[8] && player == "o") {
		return oWin;
	}
	else if (matrix[0] == matrix[4] && matrix[4] == matrix[8] && player == "o") {
		return oWin;
	}
	else if (matrix[2] == matrix[4] && matrix[4] == matrix[6] && player == "o") {
		return oWin;
	}
	else {
		return "/";
	}
}
string win4x4() {
	if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && player == "x") {
		return xWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && player == "x") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && player == "x") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && player == "x") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && player == "x") {
		return xWin;
	}
	// for o

	else if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && player == "o") {
		return xWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && player == "o") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && player == "o") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && player == "o") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && player == "o") {
		return xWin;
	}
	else {
		return "+/";
	}
}
string win5x5() {
	if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && player == "x") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && player == "x") {
		return xWin;
	}
	// for o
	if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && player == "o") {
		return oWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && player == "o") {
		return oWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && player == "o") {
		return oWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && player == "o") {
		return oWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && player == "o") {
		return oWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && player == "o") {
		return oWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && player == "o") {
		return oWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && player == "o") {
		return oWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && player == "o") {
		return oWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && player == "o") {
		return oWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && player == "o") {
		return oWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && player == "o") {
		return oWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && player == "o") {
		return oWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && player == "o") {
		return oWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && player == "o") {
		return oWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && player == "o") {
		return oWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && player == "o") {
		return oWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && player == "o") {
		return oWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && player == "o") {
		return oWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && player == "o") {
		return oWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && player == "o") {
		return oWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && player == "o") {
		return oWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && player == "o") {
		return oWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && player == "o") {
		return oWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && player == "o") {
		return oWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && player == "o") {
		return oWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && player == "o") {
		return oWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && player == "o") {
		return oWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && player == "o") {
		return oWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && player == "o") {
		return oWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && player == "o") {
		return oWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && player == "o") {
		return oWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && player == "o") {
		return oWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && player == "o") {
		return oWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && player == "o") {
		return oWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && player == "o") {
		return oWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && player == "o") {
		return oWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && player == "o") {
		return oWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && player == "o") {
		return oWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && player == "o") {
		return oWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && player == "o") {
		return oWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && player == "o") {
		return oWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && player == "o") {
		return oWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && player == "o") {
		return oWin;
	}
	else {
		return "+/";
	}
}

string winBot() {

	if (matrix[0] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[1] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[3] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[5] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[6] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[7] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[0] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[3] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[6] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[1] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[7] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[5] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[0] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m" && matrix[6] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[0] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[1] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[3] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[5] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[6] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[7] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[0] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[3] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[6] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[1] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[7] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[5] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[0] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m" && matrix[6] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}

	else if (matrix[0] == matrix[1] && matrix[1] == matrix[2] && player == "x") {
		return xWin;
	}
	else if (matrix[3] == matrix[4] && matrix[4] == matrix[5] && player == "x") {
		return xWin;
	}
	else if (matrix[6] == matrix[7] && matrix[7] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[3] && matrix[3] == matrix[6] && player == "x") {
		return xWin;
	}
	else if (matrix[1] == matrix[4] && matrix[4] == matrix[7] && player == "x") {
		return xWin;
	}
	else if (matrix[2] == matrix[5] && matrix[5] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[4] && matrix[4] == matrix[8] && player == "x") {
		return xWin;
	}
	else if (matrix[2] == matrix[4] && matrix[4] == matrix[6] && player == "x") {
		return xWin;
	}
	else if (matrix[0] == matrix[1] && matrix[1] == matrix[2] && player == "x") {
		return xWin;
	}
	else if (matrix[3] == matrix[4] && matrix[4] == matrix[5] && player == "o") {
		return xWin;
	}
	else if (matrix[6] == matrix[7] && matrix[7] == matrix[8] && player == "o") {
		return xWin;
	}
	else if (matrix[0] == matrix[3] && matrix[3] == matrix[6] && player == "o") {
		return xWin;
	}
	else if (matrix[1] == matrix[4] && matrix[4] == matrix[7] && player == "o") {
		return xWin;
	}
	else if (matrix[2] == matrix[5] && matrix[5] == matrix[8] && player == "o") {
		return xWin;
	}
	else if (matrix[0] == matrix[4] && matrix[4] == matrix[8] && player == "o") {
		return xWin;
	}
	else if (matrix[2] == matrix[4] && matrix[4] == matrix[6] && player == "o") {
		return xWin;
	}
	else {
		return "//";
	}
}
string winBot4x4() {
	if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && matrix4[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && matrix4[3] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && matrix4[6] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && matrix4[7] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && matrix4[10] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && matrix4[11] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && matrix4[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && matrix4[15] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && matrix4[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && matrix4[12] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && matrix4[9] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && matrix4[13] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && matrix4[10] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && matrix4[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && matrix4[11] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && matrix4[15] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && matrix4[10] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && matrix4[15] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && matrix4[9] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && matrix4[6] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && matrix4[11] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && matrix4[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && matrix4[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && matrix4[13] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	// for o

	if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && matrix4[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && matrix4[3] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && matrix4[6] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && matrix4[7] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && matrix4[10] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && matrix4[11] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && matrix4[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && matrix4[15] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && matrix4[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && matrix4[12] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && matrix4[9] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && matrix4[13] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && matrix4[10] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && matrix4[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && matrix4[11] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && matrix4[15] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && matrix4[10] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && matrix4[15] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && matrix4[9] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && matrix4[6] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && matrix4[11] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && matrix4[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && matrix4[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && matrix4[13] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}


	else if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && player == "x") {
		return xWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && player == "x") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && player == "x") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && player == "x") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && player == "x") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && player == "x") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && player == "x") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && player == "x") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && player == "x") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && player == "x") {
		return xWin;
	}
	// for o

	else if (matrix4[0] == matrix4[1] && matrix4[1] == matrix4[2] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[2] && matrix4[2] == matrix4[3] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[5] && matrix4[5] == matrix4[6] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[6] && matrix4[6] == matrix4[7] && player == "o") {
		return xWin;
	}
	else if (matrix4[8] == matrix4[9] && matrix4[9] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[9] == matrix4[10] && matrix4[10] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[13] && matrix4[13] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[13] == matrix4[14] && matrix4[14] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[4] && matrix4[4] == matrix4[8] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[8] && matrix4[8] == matrix4[12] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[5] && matrix4[5] == matrix4[9] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[9] && matrix4[9] == matrix4[13] && player == "o") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[6] && matrix4[6] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[6] == matrix4[10] && matrix4[10] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[7] && matrix4[7] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[11] && matrix4[11] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[0] == matrix4[5] && matrix4[5] == matrix4[10] && player == "o") {
		return xWin;
	}
	else if (matrix4[5] == matrix4[10] && matrix4[10] == matrix4[15] && player == "o") {
		return xWin;
	}
	else if (matrix4[3] == matrix4[6] && matrix4[6] == matrix4[9] && player == "o") {
		return xWin;
	}
	else if (matrix4[12] == matrix4[9] && matrix4[9] == matrix4[6] && player == "o") {
		return xWin;
	}
	else if (matrix4[1] == matrix4[6] && matrix4[6] == matrix4[11] && player == "o") {
		return xWin;
	}
	else if (matrix4[4] == matrix4[9] && matrix4[9] == matrix4[14] && player == "o") {
		return xWin;
	}
	else if (matrix4[2] == matrix4[5] && matrix4[5] == matrix4[8] && player == "o") {
		return xWin;
	}
	else if (matrix4[7] == matrix4[10] && matrix4[10] == matrix4[13] && player == "o") {
		return xWin;
	}
	else {
		return "/";
	}
	
}
string winBot5x5() {

	if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && matrix5[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && matrix5[3] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && matrix5[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && matrix5[7] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && matrix5[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && matrix5[9] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && matrix5[12] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && matrix5[13] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && matrix5[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && matrix5[17] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && matrix5[18] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && matrix5[19] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && matrix5[22] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && matrix5[23] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && matrix5[24] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && matrix5[10] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && matrix5[15] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && matrix5[20] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && matrix5[11] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && matrix5[16] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && matrix5[21] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && matrix5[12] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && matrix5[17] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && matrix5[22] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && matrix5[13] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && matrix5[18] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && matrix5[23] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && matrix5[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && matrix5[19] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && matrix5[24] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && matrix5[12] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && matrix5[18] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && matrix5[24] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && matrix5[12] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && matrix5[8] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && matrix5[4] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && matrix5[13] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && matrix5[19] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && matrix5[17] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && matrix5[23] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && matrix5[2] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && matrix5[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && matrix5[22] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && matrix5[14] == "\x1b[" + xColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	// for o
	else if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && matrix5[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && matrix5[3] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && matrix5[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && matrix5[7] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && matrix5[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && matrix5[9] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && matrix5[12] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && matrix5[13] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && matrix5[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && matrix5[17] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && matrix5[18] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && matrix5[19] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && matrix5[22] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && matrix5[23] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && matrix5[24] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && matrix5[10] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && matrix5[15] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && matrix5[20] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && matrix5[11] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && matrix5[16] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && matrix5[21] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && matrix5[12] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && matrix5[17] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && matrix5[22] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && matrix5[13] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && matrix5[18] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && matrix5[23] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && matrix5[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && matrix5[19] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && matrix5[24] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && matrix5[12] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && matrix5[18] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && matrix5[24] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && matrix5[12] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && matrix5[8] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && matrix5[4] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && matrix5[13] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && matrix5[19] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && matrix5[17] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && matrix5[23] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && matrix5[2] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && matrix5[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && matrix5[22] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && matrix5[14] == "\x1b[" + oColor + "m" + botMove + "\x1b[0m") {
		return botWin;
	}


	if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && player == "x") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && player == "x") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && player == "x") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && player == "x") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && player == "x") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && player == "x") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && player == "x") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && player == "x") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && player == "x") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && player == "x") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && player == "x") {
		return xWin;
	}
	// for o
	else if (matrix5[0] == matrix5[1] && matrix5[1] == matrix5[2] && player == "o") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[2] && matrix5[2] == matrix5[3] && player == "o") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[3] && matrix5[3] == matrix5[4] && player == "o") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[6] && matrix5[6] == matrix5[7] && player == "o") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[7] && matrix5[7] == matrix5[8] && player == "o") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[8] && matrix5[8] == matrix5[9] && player == "o") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[11] && matrix5[11] == matrix5[12] && player == "o") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[12] && matrix5[12] == matrix5[13] && player == "o") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[13] && matrix5[13] == matrix5[14] && player == "o") {
		return xWin;
	}
	else if (matrix5[15] == matrix5[16] && matrix5[16] == matrix5[17] && player == "o") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[17] && matrix5[17] == matrix5[18] && player == "o") {
		return xWin;
	}
	else if (matrix5[17] == matrix5[18] && matrix5[18] == matrix5[19] && player == "o") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[21] && matrix5[21] == matrix5[22] && player == "o") {
		return xWin;
	}
	else if (matrix5[21] == matrix5[22] && matrix5[22] == matrix5[23] && player == "o") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[23] && matrix5[23] == matrix5[24] && player == "o") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[5] && matrix5[5] == matrix5[10] && player == "o") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[10] && matrix5[10] == matrix5[15] && player == "o") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[15] && matrix5[15] == matrix5[20] && player == "o") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[6] && matrix5[6] == matrix5[11] && player == "o") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[11] && matrix5[11] == matrix5[16] && player == "o") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[16] && matrix5[16] == matrix5[21] && player == "o") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[7] && matrix5[7] == matrix5[12] && player == "o") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[12] && matrix5[12] == matrix5[17] && player == "o") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[17] && matrix5[17] == matrix5[22] && player == "o") {
		return xWin;
	}
	else if (matrix5[3] == matrix5[8] && matrix5[8] == matrix5[13] && player == "o") {
		return xWin;
	}
	else if (matrix5[8] == matrix5[13] && matrix5[13] == matrix5[18] && player == "o") {
		return xWin;
	}
	else if (matrix5[13] == matrix5[18] && matrix5[18] == matrix5[23] && player == "o") {
		return xWin;
	}
	else if (matrix5[4] == matrix5[9] && matrix5[9] == matrix5[14] && player == "o") {
		return xWin;
	}
	else if (matrix5[9] == matrix5[14] && matrix5[14] == matrix5[19] && player == "o") {
		return xWin;
	}
	else if (matrix5[14] == matrix5[19] && matrix5[19] == matrix5[24] && player == "o") {
		return xWin;
	}
	else if (matrix5[0] == matrix5[6] && matrix5[6] == matrix5[12] && player == "o") {
		return xWin;
	}
	else if (matrix5[6] == matrix5[12] && matrix5[12] == matrix5[18] && player == "o") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[18] && matrix5[18] == matrix5[24] && player == "o") {
		return xWin;
	}
	else if (matrix5[20] == matrix5[16] && matrix5[16] == matrix5[12] && player == "o") {
		return xWin;
	}
	else if (matrix5[16] == matrix5[12] && matrix5[12] == matrix5[8] && player == "o") {
		return xWin;
	}
	else if (matrix5[12] == matrix5[8] && matrix5[8] == matrix5[4] && player == "o") {
		return xWin;
	}
	else if (matrix5[1] == matrix5[7] && matrix5[7] == matrix5[13] && player == "o") {
		return xWin;
	}
	else if (matrix5[7] == matrix5[13] && matrix5[13] == matrix5[19] && player == "o") {
		return xWin;
	}
	else if (matrix5[5] == matrix5[11] && matrix5[11] == matrix5[17] && player == "o") {
		return xWin;
	}
	else if (matrix5[11] == matrix5[17] && matrix5[17] == matrix5[23] && player == "o") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[6] && matrix5[6] == matrix5[2] && player == "o") {
		return xWin;
	}
	else if (matrix5[22] == matrix5[18] && matrix5[18] == matrix5[14] && player == "o") {
		return xWin;
	}
	else if (matrix5[10] == matrix5[16] && matrix5[16] == matrix5[22] && player == "o") {
		return xWin;
	}
	else if (matrix5[2] == matrix5[8] && matrix5[8] == matrix5[14] && player == "o") {
		return xWin;
	}
	else {
		return "/";
	}
}

void checkWinBot() {
	if (start == true) {
		if (winBot() == botWin) {
			cout << "Бот победил!!\n";
			start = false;
		}
		else if (winBot() == xWin) {
			cout << "Победил игрок!!!\n";
			start = false;
		}
		else if (winBot() == "//" && n == 9) {
			cout << "draw!\n";
			start = false;
		}
	}
}
void checkWinBot4x4() {
	if (start == true) {
		if (winBot4x4() == botWin) {
			cout << "Бот победил!!!\n";
			start = false;
		}
		else if (winBot4x4() == xWin) {
			cout << "Победил игрок\n";
			start = false;
		}
		else if (winBot4x4() == "/" && n == 16) {
			cout << "draw";
			start = false;
		}
	}
}
void checkWinBot5x5() {
	if (start == true) {
		if (winBot5x5() == botWin) {
			cout << "Бот победил!!!\n";
			start = false;
		}
		else if (winBot5x5() == xWin) {
			cout << "Победил игрок\n";
			start = false;
		}
		else if (winBot5x5() == "/" && n == 25) {
			cout << "draw";
			start = false;
		}
	}
}

void checkWin() {
	if (win() == xWin) {
		cout << "x win\n";
		start = false;
	}
	else if (win() == oWin) {
		cout << "o win\n";
		start = false;
	}
	else if (win() == "/" && n == 9) {
		cout << "draw!\n";
		start = false;
	}
}
void checkWin4x4() {
	if (win4x4() == xWin) {
		cout << "x win\n";
		start = false;
	}
	else if (win4x4() == oWin) {
		cout << "o win\n";
		start = false;
	}
	else if (win4x4() == "+/" && n == 16) {
		cout << "draw!\n";
		start = false;
	}
}
void checkWin5x5() {
	if (win5x5() == xWin) {
		cout << "x win\n";
		start = false;
	}
	else if (win5x5() == oWin) {
		cout << "o win\n";
		start = false;
	}
	else if (win5x5() == "+/" && n == 25) {
		cout << "draw!\n";
		start = false;
	}
}

void startGameWithTwoPeople() {
	while (n <= 9) {
		while (start == true) {
			n++;
			checkFirstMove();
			drawField();
			input();
			checkWin();
			ChangePlayer();
			break;
		}
	}
}
void startGameWithTwoPeople4x4() {
	while (n <= 16) {
		while (start == true) {
			n++;
			checkFirstMove();
			drawField4();
			input4x4();
			checkWin4x4();
			ChangePlayer();
		}
	}

}
void startGameWithTwoPeople5x5() {
	while (n <= 25) {
		while (start == true) {
			n++;
			checkFirstMove();
			drawField5();
			input5x5();
			checkWin5x5();
			ChangePlayer();
		}
	}
}

void botGame() {
	while (n <= 9) {
		while (start == true) {
			n++;
			checkFirstMoveWithBot();
			botInput();
			drawField();
			checkWinBot();
			input();
			checkWinBot();
			botWork = true;
		}
	}
}
void botGame4x4() {
	while (n <= 16) {
		while (start == true) {
			n++;
			checkFirstMoveWithBot();
			drawField4();
			botInput4x4();
			checkWinBot4x4();
			input4x4();
			checkWinBot4x4();
			botWork = true;
		}
	}
}
void botGame5x5() {
	while (n <= 25) {
		while (start == true) {
			n++;
			checkFirstMoveWithBot();
			drawField5();
			botInput5x5();
			checkWinBot5x5();
			input5x5();
			checkWinBot5x5();
			botWork = true;
		}
	}
}

void setSetting() {
	system("cls");
	cout << "Добро пожаловать в настройки :)\n";
	cout << "[1] Поменять режим игры\n";
	cout << "[2] Поменять размер поля\n";
	cout << "[3] Поменять цвет чего-то...\n";
	cout << "[4] Кто первый ходит\n";
	cout << "Выбери желаемый путь, путник..\n";
	int c;
	cin >> c;
	switch (c) {
	case 1:
	{
		system("cls");
		cout << "Выберите режим игры\n[1] Два игрока \n[2] С ботом\n";
		int choise;
		cout << "Введи значение:";
		cin >> choise;
		switch (choise) {
		case 1:
			gameMode = 1;
			break;
		case 2:
			gameMode = 2;
			break;
		default:
			cout << "Неверное значение";
			system("pause");
			setSetting();
		}
		break;
	}
	case 2:
	{
		system("cls");
		cout << "Выберите размер поля:\n[1]3x3(default)\n[2]4x4\n[3]5x5\n";
		int choise;
		cin >> choise;
		cout << "Введи значение:";
		switch (choise) {
		case 1:
			FieldSize = 3;
			break;
		case 2:
			FieldSize = 4;
			break;
		case 3:
			FieldSize = 5;
			break;
		default:
			cout << "Не корректное значение";
			setSetting();
			break;
		}
		break;
	}
	case 3:
		system("cls");
		cout << "Выбираем чей цвет хотим поменять:\n[1]Крестика\n[2] Нолика\n";
		int choise;
		cout << "Введи значение:";
		cin >> choise;
		switch (choise) {
		case 1:
			cout << "Выберите желаемые цвета:\n[1]Обычный\n[2]Светло-серый\n[3]Серый\n[4]Красный\n[5]Зеленый\n[6]Желтый\n";
			int c;
			cin >> c;
			switch (c) {
			case 1: xColor = "0"; break;
			case 2: xColor = "89"; break;
			case 3: xColor = "90"; break;
			case 4: xColor = "91"; break;
			case 5: xColor = "92"; break;
			case 6: xColor = "93"; break;
			default: cout << "Mimo"; break;
			}
			break;
		case 2:
			cout << "Выберите желаемые цвета:\n[1]Обычный\n[2]Светло-серый\n[3]Серый\n[4]Красный\n[5]Зеленый\n[6]Желтый\n";
			int p;
			cin >> p;
			switch (p) {
			case 1: oColor = "0"; break;
			case 2: oColor = "89"; break;
			case 3: oColor = "90"; break;
			case 4: oColor = "91"; break;
			case 5: oColor = "92"; break;
			case 6: oColor = "93"; break;
			default: cout << "Mimo"; break;
			}
			break;
		default:
			cout << "Mimo";
			system("pause");
			setSetting();
		}
		break;
	case 4:
		system("cls");
		cout << "Выбери кто будет ходить первым:\n[1]Крестик\n[2]Нолик\n";
		int c;
		cout << "Введи значение:";
		cin >> c;
		switch (c) {
		case 1:
			firstMove = "x";
			break;
		case 2:
			firstMove = "o";
			break;
		default:
			cout << "Mimo";
			system("pause");
			setSetting();
		}
		break;
	default:
		cout << "Mimo";
		system("pause");
		setSetting();
	}
}

void showRules() {
	cout << "Правила просты, кто ходит первым решают игроки, бот всегда начинает первым, побеждает тот чьи фигуры займут 3 в ряд" << endl;
	system("pause");
}

int main() {
	setlocale(0, "");
	system("cls");
	cout << " Крестики нолики" << endl;
	cout << " [1] Играть \n [2] Настройки \n [3] Правила \n [4] Выход \n";
	cout << "Выберите желамеый пункт меню:";
	int choise;
	cin >> choise;

	if (choise == 1 && FieldSize == 3 && gameMode == 1) {
		startGameWithTwoPeople();
	}
	else if (choise == 1 && FieldSize == 4 && gameMode == 1) {
		startGameWithTwoPeople4x4();
	}
	else if (choise == 1 && FieldSize == 5 && gameMode == 1) {
		startGameWithTwoPeople5x5();
	}
	else if (choise == 1 && FieldSize == 3 && gameMode == 2) {
		botGame();
	}
	else if (choise == 1 && FieldSize == 4 && gameMode == 2) {
		botGame4x4();
	}
	else if (choise == 1 && FieldSize == 5 && gameMode == 2) {
		botGame5x5();
	}
	else if (choise == 2) {
		setSetting();
		main();
	}
	else if (choise == 3) {
		showRules();
		main();
	}

}
