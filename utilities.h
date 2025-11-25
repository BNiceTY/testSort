// utilities.h
#ifndef H_UTILITIES
#define H_UTILITIES

#include <string>
#include <random>


#include "unorderedLinkedList.h" 


unorderedLinkedList<int> buildRandomIntList(int size)
{
    unorderedLinkedList<int> list;

    static std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    static std::uniform_int_distribution<int> dist(100000000, 999999999);

    for (int i = 0; i < size; ++i)
    {
        int value = dist(rng);   // random 9-digit int
        list.insertLast(value);
    }

    return list;
}


#include <limits> // for numeric_limits

int getInt(const string& prompt)
{
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            // Bad input (non-numeric)
            cin.clear(); // clear failbit
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the line

            cout << "Invalid input. Please enter an integer.\n";
        }
        else
        {
            // Good read; discard any extra junk on the same line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


int getIntInRange(const string& prompt, int minValue, int maxValue)
{
    int value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear line

        if (value < minValue || value > maxValue)
        {
            cout << "Please enter a value between " 
                 << minValue << " and " << maxValue << ".\n";
            continue;
        }

        return value;
    }
}

double getDouble(const string& prompt)
{
    double value;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

char getChar(const string& prompt)
{
    char c;

    while (true)
    {
        cout << prompt;
        cin >> c; // formatted extraction, skips leading whitespace

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid character input. Try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return c;
    }
}

bool getYesNo(const string& prompt)
{
    while (true)
    {
        cout << prompt << " (Y/N): ";
        char c;
        cin >> c;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter Y or N.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        if (c == 'y') return true;
        if (c == 'n') return false;

        cout << "Please enter Y or N.\n";
    }
}

string getLine(const string& prompt)
{
    cout << prompt;

    string line;
    getline(cin, line);

    if (cin.fail() && !cin.eof())
    {
        cin.clear();
    }
    return line;
}

void waitLine(const string& prompt)
{
    cout << prompt;

    string line;
    getline(cin, line);

    if (cin.fail() && !cin.eof())
    {
        cin.clear();
        return;
    }
    cin.clear();
    return;
}

#endif // H_UTILITIES
