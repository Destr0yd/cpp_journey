#include <iostream>

#include "ask.hpp"

char ask_yn(std::string question)
{
	std::string response;

	for (;;)
	{
		std::cout << question << " (y/n): ";
		std::getline(std::cin, response);

		if (response == "y" || response == "n")
			break;
		else
			std::cout << "Wrong input! Please input 'y' or 'n'.\n";
	}

	return response[0];
}

int ask_num(std::string question, int low, int high)
{
	int response;

	do
	{
		std::cout << question << " (" << low << "-" << high << "): ";
		std::cin >> response;

		while (std::cin.fail())
		{
			std::cin.clear(); // clear out of failed cin state
			std::cin.ignore(256, '\n'); // ignore some garbage

			std::cout << "Wrong input! Please input a number from " << low << " to " << high << ": ";
			std::cin >> response;
		}
	} while (response < low || response > high);

	return response;
}