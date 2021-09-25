/**
 * Fall 2021 PA 02 Template Repo.
 */

#include <iostream>
#include <fstream>

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
#include "DSVector.h"

int main(int argc, char** argv) {
    if(argc == 1) {
        runCatchTests();
    }
    else {
        std::cout << "Hello, 2341 students!" << std::endl;
        std::cout << "Attempting to open and write to " << argv[2] << std::endl;
        std::ofstream o(argv[2]);
        o << "Writing to output file." << std::endl;
        o.close();
        DSVector <int> test;
        DSVector <int> test2;
        for (int i = 0; i < 15; i++)
            test.push_back(i);
        for (int i = 0; i < test.getSize(); i++)
            std::cout << test.at(i) << std::endl;
        std::cout << test.getSize() << std::endl;
        std::cout << test.getCapacity() << std::endl;
        test.remove(8);
        for (int i = 0; i < test.getSize(); i++)
            std::cout << test.at(i) << std::endl;
        std::cout << test.getSize() << std::endl;
        std::cout << test.getCapacity() << std::endl;

        std::cout << test.search(12) << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < 30; i++)
            test2.push_back(i*2);

        test = test2;
        test2 = test;

        for (int i = 0; i < test.getSize(); i++)
            std::cout << test2.at(i) << std::endl;
        std::cout << test2.getSize() << std::endl;
        std::cout << test2.getCapacity() << std::endl;
    }


    return 0;
}
