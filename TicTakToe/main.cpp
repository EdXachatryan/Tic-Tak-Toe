#include "TicTakToeGame.h"
#include <iostream>

int main() {
	
	TicTakToeGame game;
	bool playAgain{ true };
	
	while (playAgain)
	{
		game.play();
		std::cout << "Press 0 for quick ";
		std::cin >> playAgain;
		game.closeGame();
	}
	

	
	return 0;
}