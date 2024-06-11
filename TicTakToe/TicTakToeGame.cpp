#include "TicTakToeGame.h"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "Utilities.h"

TicTakToeGame::TicTakToeGame(const int nRow, const int nCol) {
	for (auto row : matrix) {
		std::fill(row.begin(), row.end(), gameElements::Empty);
		row.fill(gameElements::Empty);
	}

	for (size_t i = 0; i < nRow; i++)
	{
		for (size_t j = 0; j < nCol; j++)
		{
			matrix[i][j] = gameElements::Empty;
		}
	}
}

void TicTakToeGame::play() {

	// use state design pattern vor game managing
	// while (noWinner)
	GameUsers winner = GameUsers::Non;
	for (size_t i = 0; i < 9; ++i) {
		pairInts positions = getTwoNumber();
		if (i % 2 == 0) {
			setX(positions.first, positions.second);
		}
		else {
			setY(positions.first, positions.second);
		}
		winner = checkWinner();
		if (winner != GameUsers::Non) {
			break;
		}
	}
	std::cout << "Win " << getUserNameFromInt(static_cast<int>(winner));
}

void TicTakToeGame::setX(const int row, const int col) {

	try {
		setValue(row, col, gameElements::X);
	}
	catch (const std::invalid_argument& ex) {
		std::cout << ex.what() << "\n";
		pairInts positions = getTwoNumber();
		setX(positions.first, positions.second);
	}
}

void TicTakToeGame::checkPostition(const int row, const int col) {

	if ((row < 0 || row >= 3) || (col < 0 || col >= 3)) {
		throw std::invalid_argument("Postion can't be under 0 ir higher 3");
	}
}

void TicTakToeGame::setY(const int row, const int col) {
	try {
		setValue(row, col, gameElements::Y);
	}
	catch (const std::invalid_argument& ex) {
		std::cout << ex.what() << "\n";
		pairInts positions = getTwoNumber();
		setY(positions.first, positions.second);

	}
}

bool TicTakToeGame::setValue(const int row, const int col, const gameElements value) {
	checkPostition(row, col);
	if (isEmptyPos(row, col)) {
		matrix.at(row).at(col) = (value);
	}
	else {
		std::cout << "position isn't empty" << "\n";
		throw  std::invalid_argument("postion isn't empty");
	}
	++stepCount;
	printTable();
	return true;
}

GameUsers TicTakToeGame::checkWinner() const {
	
	GameUsers user = GameUsers::Non;
	
	if (stepCount < 5) {
		return user;
	}
	// horizontal
	for (size_t i = 0; i < 3; i++)
	{
		if (matrix[i][0] == matrix[i][1] == matrix[i][2])
			return gameUser::getUserFromInt(matrix[i][0]);
	}

	// vertical
	for (size_t i = 0; i < 3; i++) {
		if (char(matrix[0][i]) == char(matrix[1][i]) == char(matrix[2][i])) {
			return gameUser::getUserFromInt(matrix[0][i]);
		}
	}

	// main diagonal
	if (matrix[0][0] == matrix[1][1] == matrix[2][2]) {
		return gameUser::getUserFromInt(matrix[0][0]);
	}

	// secondary diagonal
	if (matrix[0][2] == matrix[1][1] == matrix[2][0]) {
		 return gameUser::getUserFromInt(matrix[0][2]);
	}
	return user;
}

bool TicTakToeGame::isEmptyPos(const int row, const int col) const {
	try
	{
		return (matrix[row][col] == gameElements::Empty);

	} catch (const std::exception& ex) 	{
		std::cerr <<ex.what() << " invalid postion\n";
		return false;
	}
}


void TicTakToeGame::printTable() const {
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix.size(); j++)
		{
			std::cout << static_cast<char>(matrix[i][j]) << " ";
		}
		std::cout << "\n";
	}
}

void TicTakToeGame::closeGame() {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			matrix[i][j] = gameElements::Empty;
		}
	}
}