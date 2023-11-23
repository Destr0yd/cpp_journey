#include "Word.hpp"

Word::Word(const std::vector<string> words)
{
	string word;
	unsigned word_i;
	string encoded_word;

	srand(time(NULL)); // use a seed based on seconds
	
	word_i = rand() % words.size(); // get the random index of `words`
	word = words[word_i]; // choose a decoded word
	encoded_word.append(word.length(), '-'); // fill the encoded word with '-'

	this->word = word;
	this->encoded_word = encoded_word;
}

void Word::reveal(char letter)
{
	for (unsigned i{}; i < word.length(); i++)
	{
		// Lookup for specific letter and replace '-' with it
		if (word[i] == letter)
			encoded_word[i] = letter;
	}
}

bool Word::is_revealed()
{
	return encoded_word == word;
}

bool Word::is_revealed(size_t i)
{
	return HAS_MATCH(encoded_word.find(word[i], 0));
}