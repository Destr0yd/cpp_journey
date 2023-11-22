#include <iostream>
#include <ctime>

// This enum is only used for indexes of the `WORDS` :P
enum Fields
{
	WORD,
	HINT,
	N_FIELDS
};

// I decided to use my bEsT creativity skills and make my own silly words.
// Change these, if you want to add or remove a word
const unsigned N_WORDS = 4;
const std::string WORDS[N_WORDS][N_FIELDS]
{
	{ "lemon", "You wouldn't eat this fruit along." },
	{ "yogurt", "You store in a fridge. Good for breakfast." },
	{ "iceberg", "A large mass of ice." },
	{ "absolute", "Known vodka brand." }
};

// I'm not sure, if it was a good idea to make a function just for this purpose..
// Anyhoo, this function just returns a random index of row in `WORDS`
unsigned rand_pair()
{
	srand(time(NULL)); // use a seed based on time
	
	return rand() % N_WORDS;
}

// Mixes up the given word and returns it.
std::string mix_word(std::string word)
{
	unsigned word_len = word.size(); // ik it's size_t, but it'd be looking weird if I used it

	// I noticed there's a probability it won't even mix anything, because you know.. randomness
	for (unsigned i{}; i < word_len; i++)
	{
		unsigned from_i = rand() % word_len;
		unsigned to_i = rand() % word_len;

		// swap 'em
		char temp = word[from_i];
		word[from_i] = word[to_i];
		word[to_i] = temp;
	}

	return word;
}

// Just a game loop.
// Returns has the player won or not.
bool game(const std::string word, const std::string hint)
{
	std::string guess;

	for (;;)
	{
		std::cout << "-> ";
		std::cin >> guess;

		if (guess == word)
			return true;
		else if (guess == "h")
			std::cout << "Hint: " << hint << std::endl;
		else if (guess == "q")
			return false;
		else
			std::cout << "\"" << guess << "\" is a wrong word!" << std::endl;
	}
}

int main()
{
	const unsigned choice = rand_pair();
	const std::string word = WORDS[choice][WORD]; // ~ WORDS[choice][0]
	const std::string hint = WORDS[choice][HINT]; // ~ WORDS[choice][1]
	const std::string mixed = mix_word(word);
	bool has_guessed;

	std::cout << "Jumble Word Game! Type 'q' to give up, or type 'h' to get a hint." << std::endl;
	std::cout << "Jumbled word is \"" << mixed << "\"." << std::endl;

	has_guessed = game(word, hint);

	if (has_guessed)
		std::cout << "Congrats you won!" << std::endl;
	else
		std::cout << "You lost! The word was " << word << "." << std::endl;
}