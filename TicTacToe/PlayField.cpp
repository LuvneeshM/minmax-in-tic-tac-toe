#include <vector>
#include <iostream>
#include "PlayField.h"

using namespace std;

#define PLAY_SIZE 4
#define X 1
#define EMPTY 0
#define O -1
#define X_WIN 1
#define DRAW 0
#define X_LOSE -1
#define NOT_OVER -2

Play_field::Play_field() : field(vector<vector<int>>(PLAY_SIZE)) {
	for (int i = 0; i < PLAY_SIZE; ++i) {
		for (int j = 0; j < PLAY_SIZE; ++j)
			field[i].push_back(EMPTY);
	}
}

void Play_field::put(int x, int y, int shape) { field[y][x] = shape; }
int Play_field::get(int x, int y) { return field[y][x]; }

void Play_field::display() {
	cout << "\n";
	for (vector<int> a : field) {
		for (int i = 0; i < PLAY_SIZE; ++i) {
			if (a[i] == EMPTY) cout << "* ";
			else if (a[i] == X) cout << "X ";
			else cout << "O ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Play_field::clear() {
	for (int i = 0; i < PLAY_SIZE; ++i) {
		for (int j = 0; j < PLAY_SIZE; ++j)
			field[i][j] = EMPTY;
	}
}

int Play_field::check_win_condition() {
	int player, win_condition = NOT_OVER;
	//check row win condition
	for (int row = 0; row < PLAY_SIZE; ++row) {
		if ((player = field[row][0]) != EMPTY) {
			for (int col = 1; col < PLAY_SIZE; ++col) {
				if (field[row][col] != player) break;
				if (col == PLAY_SIZE - 1) win_condition = player;
			}
		}
	}

	if (win_condition != -2) return win_condition;

	//check column win condition
	for (int col = 0; col < PLAY_SIZE; ++col) {
		if ((player = field[0][col]) != EMPTY) {
			for (int row = 1; row < PLAY_SIZE; ++row) {
				if (field[row][col] != player) break;
				if (row == PLAY_SIZE - 1) win_condition = player;
			}
		}
	}

	if (win_condition != -2) return win_condition;

	//check diagonal win condition
	if ((player = field[0][0]) != EMPTY) {
		for (int i = 1; i < PLAY_SIZE; ++i) {
			if (field[i][i] != player) break;
			if (i == PLAY_SIZE - 1) win_condition = player;
		}
	}
	if (win_condition != -2) return win_condition;

	if ((player = field[PLAY_SIZE - 1][0]) != EMPTY) {
		for (int i = 1; i < PLAY_SIZE; ++i) {
			if (field[PLAY_SIZE - i -1][i] != player) break;
			if (i == PLAY_SIZE - 1) win_condition = player;
		}
	}
	if (win_condition != -2) return win_condition;


	//Check if Draw
	win_condition = DRAW;
	for (int i = 0; i < PLAY_SIZE; ++i) {
		for(int j = 0; j < PLAY_SIZE; ++j)
			if (field[i][j] == EMPTY) {
				win_condition = NOT_OVER;
				break;
			}
	}

	return win_condition;
}