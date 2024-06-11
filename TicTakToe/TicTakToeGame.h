#ifndef TICTAKTOE_H
#define TICTAKTOE_H
#include <array>
#include "Users.h"
using std::array;
using namespace gameUser;
#define defultRowCount 3

// use state design pattern ,  user 1 waiting or user 2 waiting states, game is over state , game is not started started staterov

class TicTakToeGame {


public:
	TicTakToeGame(const int nRow = defultRowCount, const int nCol = defultRowCount);
	void play();
	void setX(const int row, const int col);
	void setY(const int row, const int col);
	void closeGame();

	void printTable() const;

private:
	bool isEmptyPos(const int row, const int col) const;
	void checkGameState() const;
	GameUsers checkWinner() const;
	void checkPostition(const int row, const int col);
	bool setValue(const int row, const int col, const gameElements user);

private:
	array<array<gameElements, 3>, 3> matrix;
	int stepCount = 0;
};

#endif // !TICTAKTOE_H
