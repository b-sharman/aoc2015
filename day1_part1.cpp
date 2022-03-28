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
    }

    /*
    std::cout << "num_open: " << std::to_string(num_open) << std::endl
        << "num_closed: " << std::to_string(num_closed) << std::endl;
    */

    std::cout << "end on floor " << std::to_string(num_open - num_closed) << std::endl;

    return 0;
}
