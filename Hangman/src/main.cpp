#include <iostream>
#include "Word.hpp"

// You can modify this value how you want
// (just pls don't set it to zero or negative xD)
#define MAX_ATTEMPTS 8

// Function that serves the main game loop
// Returns: has the player won
bool start_game(Word secret_word, unsigned attempts); // game.cpp

int main()
{
	const std::vector<string> words // you can modify this for sure
	{
		"holiday",
		"aviation",
		"architect",
		"manufacturer"
	};
	Word secret_word(words);
	bool has_won;

	// Print the greeting
	std::cout << "Welcome to the Hangman Game!\n";
	std::cout << "--------------------------------------------\n";

	has_won = start_game(secret_word, MAX_ATTEMPTS);

	std::cout << "\n--------------------------------------------\n";

	// Check outcome of the game
	if (has_won)
		std::cout << "Congrats! You won!\n";
	else
	{
		std::cout << "Oof! You lost! :(\n";
		std::cout << "The word was \"" << secret_word.word << "\"" << std::endl;
	}
}