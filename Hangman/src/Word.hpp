// Main purpose of this header file is to define a `Word`
// class that will be used for the game.

#pragma once

#include <vector>
#include <string>
#include <ctime>

// Checks whether string::find has matched something
#define HAS_MATCH(x) (x != string::npos)

using std::string;

class Word
{
	// Ik, it's a bad habit to make class attributes public, but I thought
	// it'd be painful (and too complicated for this small game) to create separate
	// setters and getters for 'em.
public:
	string word; // what you need to guess
	string encoded_word; // '-' n times

	Word(const std::vector<string> words);
	void reveal(char letter); // reveal all correct letters in `encoded_word`
	bool is_revealed(); // is `encoded_word` fully revealed?
	bool is_revealed(size_t i); // is specific character at `i` already revealed?
};