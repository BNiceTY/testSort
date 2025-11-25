// Program: Sort Method Comparison (testSort.cpp)
// Author: Bruce Nebergall
// Last updated: 2025-11-24
// Purpose: Build an unordered linked list of random 9-digit integers,
//          sort it using selection sort, merge sort, or both,
//          report the execution time for each method to compare



#include "utilities.h"
#include <chrono>

int main()
{
    std::cout << "Welcome to the Sort Method Comparison utility.\n";

    while (true)
    {
        int testSize = getIntInRange("\nHow many elements would you like to test with? (0 to quit): ", 0,1000000);

        if (testSize == 0)
            break;

        // Build random list from user-entered size
        unorderedLinkedList<int> testList = buildRandomIntList(testSize);
        unorderedLinkedList<int> sortList = testList;

        // Only Print's list less than or equal to 100 elements
        if (testSize <= 100)
        {
            testList.print();
            std::cout << "\n\nElements Generated...\n";
        }
        else
        {
            std::cout << "\n\nElements Generated (" << testSize 
                      << " elements; list not printed).\n";
        }

        int method = getIntInRange(
            "\n\nHow would you like to sort?\n"
            "1. Selection Sort\n"
            "2. Merge Sort\n"
            "3. Run Both and compare\n",
             1, 3);

        if (method == 1)
        {
            auto start = std::chrono::high_resolution_clock::now();
            sortList.selectionSort();
            auto stop  = std::chrono::high_resolution_clock::now();

            auto timeS = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

            if (testSize <= 100)
            {
                std::cout << "\n\n";
                sortList.print();
            }

            std::cout << "\n\nSelection sort complete in "
                      << timeS/1000.00 << " milliseconds.\n";
            waitLine("\nPress enter to continue.");
        }
        else if (method == 2)
        {
            auto start = std::chrono::high_resolution_clock::now();
            sortList.mergeSort();
            auto stop  = std::chrono::high_resolution_clock::now();

            auto timeS = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

            if (testSize <= 100)
            {
                std::cout << "\n\n";
                sortList.print();
            }

            std::cout << "\n\nMerge sort complete in "
                      << timeS/1000.000 << " milliseconds.\n";
            waitLine("\nPress enter to continue.");
        }
        else // method == 3
        {
            // Selection sort
            auto startS = std::chrono::high_resolution_clock::now();
            sortList.selectionSort();
            auto stopS  = std::chrono::high_resolution_clock::now();
            auto timeS  = std::chrono::duration_cast<std::chrono::microseconds>(stopS - startS).count();

            if (testSize <= 100)
            {
                std::cout << "\n\nSelection-sorted list:\n";
                sortList.print();
                std::cout << "\n";
            }

            // Reset to unsorted list
            sortList = testList;

            // Merge sort
            auto startM = std::chrono::high_resolution_clock::now();
            sortList.mergeSort();
            auto stopM  = std::chrono::high_resolution_clock::now();
            auto timeM  = std::chrono::duration_cast<std::chrono::microseconds>(stopM - startM).count();

            if (testSize <= 100)
            {
                std::cout << "\n\nMerge-sorted list:\n";
                sortList.print();
                std::cout << "\n";
            }

            std::cout << "\nComparison...\n"
                      << timeS/1000.00 << " milliseconds : selection sort\n"
                      << timeM/1000.00 << " milliseconds : merge sort\n\n";

            waitLine("Press enter to continue.");
        }
    }

    std::cout << "\nQuitting program. Goodbye!\n";
}
