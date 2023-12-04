#pragma once

#include <vector>

const char EMPTY = ' ';

enum GameOutcome
{
	NO_ONE = 'N',
	TIE = 'T',
	PLAYER = 'X',
	COMPUTER = 'O'
};

class GameProcess
{
public:
	GameProcess();

	char game_loop();
	void set_turn(char turn);

private:
	std::vector<char> board;
	char turn;

	void render_board() const;
	inline bool is_legal(unsigned n) const;
	inline void make_move(unsigned n);
	void next_turn();
	unsigned player_move();
	unsigned computer_move();
	char game_outcome() const;
};