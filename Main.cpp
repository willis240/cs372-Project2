//main.cpp
//Blake Caldwell, William Fisher, Kaleeb _________
//March 27, 2020
//main for cs372 project 2

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::getline;
using std::string;

#include "Shape.hpp"

#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"

int main(int argc, char* argv[]) {

    Catch::Session session;
    int catchresult;

    catchresult = session.applyCommandLine(argc, argv);

    if (!catchresult) {
        cout << "Begin tests for class shapes and its derived classes:" << endl;
        catchresult = session.run();
        cout << "End of automated tests." << endl;
    }
    return 0;
}