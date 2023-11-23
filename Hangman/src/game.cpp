#include <iostream>
#include "Word.hpp"

bool start_game(Word secret_word, unsigned attempts)
{
	string guess;
	size_t found; // index of possibly matched letter

	// Game loop
	do
	{
		if (secret_word.is_revealed())
			return true; // stop the game loop, if player revealed whole word

		std::cout << "\nSo far, the Word is: " << secret_word.encoded_word << std::endl;
		std::cout << "You have " << attempts << " attempts left!\n\n";
		std::cout << "\tYour guess: ";
		std::cin >> guess;

		found = secret_word.word.find(guess, 0); // seek for specific character or whole word
		
		// Player has entered a full correct word?
		if (guess == secret_word.word)
			return true;
		// Player has entered a correct letter and it's not revealed yet?
		if (HAS_MATCH(found) && !secret_word.is_revealed(found))
			secret_word.reveal(secret_word.word.at(found));
		else
			attempts--;
	} while (attempts);

	return false;
}