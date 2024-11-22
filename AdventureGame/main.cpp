/****************************************************************************
* Adventure Game Project
* File: main.cpp
* Author: William Newman and Wonjoon Jun
* Purpose: The game simulates a choose your own adventure scenario where 
* the player interacts with different walls in a room, collects items, goes 
* through dialogue options, and opens doors to progress through the game. 
* Version: 1.0 October 10, 2024
* Resources: Used provided powerpoint code from lecture 2, 3, 4, 5, 6, 7, 8, 10,
* 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 27, 28, 29, 30 and I used info from
https://en.cppreference.com/w/cpp/language/operator_assignment
https://www.w3schools.com/cpp/cpp_classes.asp
https://en.cppreference.com/w/cpp/language/access
https://en.cppreference.com/w/cpp/language/static
https://www.geeksforgeeks.org/constructors-c/
https://cplusplus.com/doc/tutorial/inheritance/
https://cplusplus.com/doc/tutorial/dynamic/
https://cplusplus.com/doc/tutorial/polymorphism/
https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
https://www.w3schools.com/cpp/cpp_arrays_loop.asp
https://en.cppreference.com/w/cpp/header/fstream
https://cplusplus.com/reference/ostream/ostream/operator-free/
https://cplusplus.com/doc/tutorial/files/
https://www.geeksforgeeks.org/chrono-in-c/
https://en.cppreference.com/w/cpp/memory/unique_ptr
https://www.geeksforgeeks.org/exception-handling-c/
https://www.geeksforgeeks.org/operator-overloading-cpp/
https://en.cppreference.com/w/cpp/language/ascii
https://cplusplus.com/reference/memory/unique_ptr/
https://stackoverflow.com/questions/17902405/how-to-implement-make-unique-function-in-c11
https://cplusplus.com/reference/fstream/fstream/
https://en.cppreference.com/w/cpp/error/exception
https://en.cppreference.com/w/cpp/chrono
https://en.cppreference.com/w/cpp/container
https://cplusplus.com/reference/iostream/
https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-cpp/
https://en.cppreference.com/w/cpp/language/classes
https://cplusplus.com/forum/beginner/212073/
https://cplusplus.com/forum/beginner/284833/
https://cplusplus.com/forum/beginner/218300/
https://en.cppreference.com/w/cpp/language/list_initialization
https://www.geeksforgeeks.org/const-member-functions-c/
https://en.cppreference.com/w/cpp/header
https://www.geeksforgeeks.org/override-keyword-c/
https://en.cppreference.com/w/cpp/language/virtual
https://www.geeksforgeeks.org/inheritance-in-c/
https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
https://isocpp.org/wiki/faq/dtors
https://www.geeksforgeeks.org/constructor-delegation-c/
https://en.cppreference.com/w/cpp/language/constructor
https://www.geeksforgeeks.org/virtual-function-cpp/
https://cplusplus.com/reference/fstream/ifstream/
https://cplusplus.com/reference/fstream/ofstream/
https://en.cppreference.com/w/cpp/container/vector
https://en.cppreference.com/w/cpp/language/range-for
https://cplusplus.com/forum/beginner/94966/
https://cplusplus.com/forum/beginner/14379/
https://en.cppreference.com/w/cpp/language/operators
https://en.cppreference.com/w/cpp/language/operator_logical
https://stackoverflow.com/questions/2564873/how-do-i-use-reference-parameters-in-c
https://www.w3schools.com/cpp/cpp_polymorphism.asp#:~:text=Polymorphism%20means%20%22many%20forms%22%2C,methods%20to%20perform%20different%20tasks.
https://en.cppreference.com/w/cpp/language/override
*******************************************************************************/

#include "AdventureGame.h"

using namespace std;

int main() {
    AdventureGame game;
    game.start();
    return 0;
}
