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
    // three vowels
    int vowel_count = 0;
    for (char c : s)
    {
        for (char v : VOWELS)
        {
            if (c == v)
            {
                vowel_count++;
            }
        }
    }
    //cout << s << " has " << vowel_count << " vowels" << endl;
    if (vowel_count < 3)
    {
        return naughty;
    }

    // one letter that appears twice in a row
    bool double_letter = false;
    for (size_t i = 0; i < s.size()-1; i++)
    {
        if (s[i] == s[i+1])
        {
            double_letter = true;
            break;
        }
    }
    if (!double_letter)
    {
        return naughty;
    }

    // contains bad strings
    for (string bad_string : BAD_STRINGS)
    {
        if (s.find(bad_string) != string::npos)
        {
            return naughty;
        }
    }

    return nice;
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

        // could do naughty_count += nice_or_naughty(line) but I feel like
        // that is "less clean"
        if (nice_or_naughty(line) == nice)
        {
            nice_count++;
        }
    }

    cout << nice_count << " nice strings" << endl;

    return 0;
}
