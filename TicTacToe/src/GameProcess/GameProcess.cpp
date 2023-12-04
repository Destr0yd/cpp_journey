#include <iostream>

#include "GameProcess.hpp"
#include "../ask/ask.hpp"

GameProcess::GameProcess() : board(9, EMPTY), turn(NULL) {}

char GameProcess::game_loop()
{
	char outcome;
	unsigned move;

	render_board();

	while (outcome = game_outcome(), outcome == NO_ONE)
	{
		if (turn == PLAYER)
			move = player_move();
		else if (turn == COMPUTER)
			move = computer_move();

		make_move(move);
		next_turn();

		render_board();
	}

	return outcome;
}

void GameProcess::render_board() const
{
	system("cls");

	std::cout << ' ' << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
	std::cout << "---|---|---\n";
	std::cout << ' ' << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
	std::cout << "---|---|---\n";
	std::cout << ' ' << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

inline bool GameProcess::is_legal(unsigned n) const
{
	return board[n] == EMPTY;
}

inline void GameProcess::make_move(unsigned n)
{
	board[n] = turn;
}

void GameProcess::set_turn(char turn)
{
	this->turn = turn;
}

void GameProcess::next_turn()
{
	if (turn == PLAYER)
		turn = COMPUTER;
	else
		turn = PLAYER;
}

unsigned GameProcess::player_move()
{
	unsigned move;

	for (;;)
	{
		move = ask_num("Your move", 0, 8);

		if (is_legal(move))
			break;
		else
			std::cout << "The spot #" << move << " is already taken!\n";
	}

	return move;
}

unsigned GameProcess::computer_move()
{
	unsigned move;
	bool found = false;

	// Search for winning computer move:
	for (move = 0; move < board.size(); move++)
	{
		if (is_legal(move))
		{
			board[move] = COMPUTER;
			found = (game_outcome() == COMPUTER);
			board[move] = EMPTY;
		}

		if (found)
			return move;
	}

	// Prevent player win:
	for (move = 0; move < board.size(); move++)
	{
		if (is_legal(move))
		{
			board[move] = PLAYER;
			found = (game_outcome() == PLAYER);
			board[move] = EMPTY;
		}

		if (found)
			return move;
	}

	// Moves ranging from the best to worst
	static const unsigned BEST_MOVES[]
	{
		4, 0, 2, 6, 8, 1, 3, 5, 7
	};
	for (unsigned i{}; i < board.size(); i++)
	{
		move = BEST_MOVES[i];
		if (is_legal(move))
			return move;
	}
}

char GameProcess::game_outcome() const
{
	// Winning positions
	static const unsigned TOTAL_ROWS = 8;
	static const unsigned WINNING_ROWS[TOTAL_ROWS][3]
	{
		{ 0, 1, 2 },
		{ 3, 4, 5 },
		{ 6, 7, 8 },
		{ 0, 3, 6 },
		{ 1, 4, 7 },
		{ 2, 5, 8 },
		{ 0, 4, 8 },
		{ 2, 4, 6 }
	};

	// If the board is fully filled then it's tie
	if (std::count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;

	for (unsigned row{}; row < TOTAL_ROWS; row++)
	{
		// Make sure that the spot is not empty and
		// other spots are the same
		if ((board.at(WINNING_ROWS[row][0]) != EMPTY) &&
			(board.at(WINNING_ROWS[row][0]) == board.at(WINNING_ROWS[row][1])) &&
			(board.at(WINNING_ROWS[row][1]) == board.at(WINNING_ROWS[row][2])))
		{
			return board.at(WINNING_ROWS[row][0]); // return the winner (char)
		}
	}

	return NO_ONE;
}