
#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to the shop!" << std::endl;

	// set a hard limit of the number of items that a user can enter 
	const int maximumItems = 10;

	// set space in memory for the user's shopping list items
	std::string* shoppingList = new std::string[maximumItems];
	// REMEMBER: if you use "new", make sure to use "delete" at some point later!!!

	// keep track of how many items the user has entered so far
	int itemCount = 0;

	// Receive user input and either store it in the shopping list
	// or check if the user said "finished" to end the program
	std::string userInput;

	// loop until the user says "finished" or enters 10 items 
	while (itemCount < maximumItems) {
		std::cout << "Enter an item into the shopping list or type 'finished' to end the program" << std::endl;
		std::getline(std::cin, userInput);

		if (userInput == "finished") {
			// end the program
			break;
		}
		else {
			shoppingList[itemCount] = userInput;
			// make sure we increment this to make sure 
			// the while loop eventually ends AND 
			// that we don't overwrite existing shopping list items!
			itemCount++;
		}

	}


	// display the shopping list to the user 
	// 1. Bananas
	for (int shoppingListIndex = 0; shoppingListIndex < itemCount; shoppingListIndex++) {
		// make sure to do "shoppingListIndex + 1" to display the human-friendly list numbering
		std::cout << shoppingListIndex + 1 << ". " << shoppingList[shoppingListIndex] << std::endl;
	}

	// delete/release any claimed memory
	delete[] shoppingList;

	return 0;

}
