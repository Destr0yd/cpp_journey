#include <iostream>

#include "GameProcess/GameProcess.hpp"
#include "ask/ask.hpp"

int main()
{
	GameProcess game_proc;
	char winner;
	char go_first;

	std::cout << "Tic-Tac-Toe!\n\n";

	std::cout << " 0 | 1 | 2\n";
	std::cout << "---|---|---\n";
	std::cout << " 3 | 4 | 5\n";
	std::cout << "---|---|---\n";
	std::cout << " 6 | 7 | 8\n\n";

	go_first = ask_yn("Do you require the first move?");

	if (go_first == 'y')
		game_proc.set_turn(PLAYER);
	else
		game_proc.set_turn(COMPUTER);
	
	winner = game_proc.game_loop();

	if (winner == COMPUTER)
		std::cout << "You lost!\n";
	else if (winner == PLAYER)
		std::cout << "Congrats! You won a battle with Terminator!\n";
	else
		std::cout << "Tie! At least you have tried..\n";
}