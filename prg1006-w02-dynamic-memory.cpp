// prg1006-w02-dynamic-memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // claim memory on free store  for this string 
    std::string* message = new std::string("Hello World!");

    std::cout << message << std::endl;

	// release memory back to free store
    delete message;
    // specifically set the pointer back to null so we don't
	// accidentally use it again and cause a runtime error
    message = nullptr;
	// confirm that the pointer is null
    std::cout << message;


    // nothrow helps the app run even after something would've broken
	// its memory allocation, e.g. bad user input, or a memory leak, etc.
    // (std::nothrow)
    try {
        int* someNumberPointer = new int[10000000000000];
        std::cout << someNumberPointer << std::endl;
        if (someNumberPointer == nullptr) {
            std::cout << "Memory allocation failed!" << std::endl;
        }
    }
    catch (const std::bad_alloc& error) {
        std::cout << "Memory allocation failed: " << error.what() << std::endl;
        // we should return 1 here to close the app, but......
        return 1;
    }
	
    std::cout << "See if this message appears after the catch message!" << std::endl;




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
