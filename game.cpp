#include<vector>
#include<iostream>
#include<random>
#include "head.h"
using namespace std;

int m, n;
vector<vector<char>>board;

void init() {
	cout << "请指定棋盘大小:" << endl;
	cin >> m >> n;
	board.resize(m);
	for (int i = 0; i < m; i++) {
		board[i].resize(n);
		for (int j = 0; j < n; j++)
			board[i][j] = '*';
	}
	cout << endl;
}

void print_board() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool is_legal(int x, int y) {
	if (0 <= x < m && 0 <= y < n) {
		if (board[x][y] == '*')
			return true;
		return false;
	}
	return false;
}

bool is_over() {
	if (board[0][0] == '*')
		return false;
	return true;
}

int random_num(int n) {
	random_device rd;
	mt19937 gen(rd());

	std::uniform_int_distribution<> dis(0, n);

	int random_num = dis(gen);
	return random_num;

}

void computer_move() {
	int x, y;
	do {
		x = random_num(m - 1);
		y = random_num(n - 1);
	} while (board[x][y] != '*');
	cout << "电脑的 吃子坐标为：" << x << " " << y << endl;
	for (int i = x; i < m; i++)
		for (int j = y; j < n; j++)
			board[i][j] = ' ';
}

void player_move() {
	int x, y;
	cout << "请输入吃子坐标：";
	cin >> x >> y;
	cout << endl;
	while (!is_legal(x, y)) {
		cout << "坐标不合要求，请重新输入坐标：";
		cin >> x >> y;
		cout << endl;
	}
	for (int i = x; i < m; i++)
		for (int j = y; j < n; j++)
			board[i][j] = ' ';
}

void pve() {
	init();
	print_board();
	while (true) {
		player_move();
		print_board();
		if (is_over()) {
			cout << "游戏结束，你输了" << endl;
			break;
		}
		computer_move();
		print_board();
		if (is_over()) {
			cout << "游戏结束，你赢了" << endl;
			break;
		}
	}
}

void pvp() {
	init();
	print_board();
	while (true) {
		cout << "玩家一回合" << endl;
		player_move();
		print_board();
		if (is_over())
			break;

		cout << "玩家二回合" << endl;
		player_move();
		print_board();
		if (is_over())
			break;
	}
	gameover();
}
void game() {
	cout << "欢迎来到蚕食游戏 ！" << endl;
	cout << "请选择你的游戏模式：" << endl;
	cout << "	  1.PVP  " << endl;
	cout << "	  2.PVE  " << endl;
	while (true) {
		char ch = getchar();
		switch (ch) {
		case '1':pvp(); break;
		case '2':pve(); break;
		default: break;
		}
		if (ch == '1' || ch == '2')
			break;
		cout << "请输入正确的游戏模式：";
		cout << "	  1.PVP  ";
		cout << "	  2.PVE  ";
	}
}

void gameover() {
	cout << "游戏结束";
}
