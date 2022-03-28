#include <iostream>
#include <fstream>

int main()
{
    std::ifstream finput { "day1_input.txt" };

    // number of open and closed parentheses
    int num_open = 0;
    int num_closed = 0;

    std::string input;
    finput >> input;
    for (int i = 0; i < static_cast<int>(input.length()); i++)
    {
        if (input[i] == '(')
        {
            num_open++;
        }
        else if (input[i] == ')')
        {
            num_closed++;
        }
        if (num_open - num_closed < 0) // entered the basement
        {
            std::cout << "entered the basement at position "
                << std::to_string(i + 1) << std::endl;
            return 0;
        }
    }
}
