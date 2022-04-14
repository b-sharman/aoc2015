#include <iostream>
#include <fstream>
#include <array>
#include <set>

int main()
{
    std::ifstream finput { "day3_input.txt" };

    std::string input;
    finput >> input;

    // std::set stores unique values, so it will only count each point once
    std::set<std::array<int, 2>> points;
    int x = 0;
    int y = 0;
    points.emplace(std::array<int, 2> {x, y});

    //for (int i=0; i<static_cast<int>(input.size()); i++)
    for (auto c : input)
    {
        if (c == '<')
        {
            x--;
        }
        else if (c == '>')
        {
            x++;
        }
        else if (c == '^')
        {
            y++;
        }
        else if (c == 'v')
        {
            y--;
        }

        // add the new location to points
        points.emplace(std::array<int, 2> {x, y});
    }

    std::cout << "number of points: " << points.size() << std::endl;
    std::cout << "Santa visited " << points.size() << " houses." << std::endl;

    return 0;
}
