#include <array>
#include <iostream>
#include <fstream>

using namespace std;

array<char, 5> VOWELS = {'a', 'e', 'i', 'o', 'u'};
array<string, 4> BAD_STRINGS = {"ab", "cd", "pq", "xy"};

enum Status
{
    nice,
    naughty
};

Status nice_or_naughty(string s)
{
    // nonoverlapping pairs
    bool pairs = false;
    for (size_t i = 0; i < s.size()-1; i++)
    {
        // look for another pair in the rest of the string
        for (size_t j = i+2; j < s.size()-1; j++)
        {
            if (s[i] == s[j] && s[i+1] == s[j+1])
            {
                pairs = true;
                // if we've already found one, no need to keep looping
                break;
            }
        }
    }
    if (!pairs)
    {
        return naughty;
    }

    //repeating letter with one letter inbetween
    for (size_t i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == s[i+2])
        {
            // if we've gotten here, we've already passed the first test,
            // so we can go right ahead and return nice
            return nice;
        }
    }

    return naughty;
}

int main()
{
    ifstream finput { "day5_input.txt" };

    string line;
    int nice_count = 0;

    while (finput)
    {
        getline(finput, line);
        // skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        if (nice_or_naughty(line) == nice)
        {
            nice_count++;
        }
    }

    cout << nice_count << " nice strings" << endl;

    return 0;
}
