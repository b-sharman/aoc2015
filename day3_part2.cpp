#include <iostream>
#include <fstream>
#include <array>
#include <set>

using namespace std;

class Carrier
{
private:
    // std::set stores unique values, so it will only count each point once
    set<array<int, 2>> points {};

    int x {};
    int y {};

public:
    Carrier()
    {
        points = {array<int, 2> {0, 0}};
        // carriers start at the origin
        x = 0;
        y = 0;
    }

    /* change x or y based on the direction, which should be one of ^v<>
     * then add the new position to points
     * returns the new point
     */
    array<int, 2> travel(char d)
    {
        if (d == '<')
        {
            x--;
        }
        else if (d == '>')
        {
            x++;
        }
        else if (d == '^')
        {
            y++;
        }
        else if (d == 'v')
        {
            y--;
        }
        /* if for some reason d was an invalid character (e.g. an \n), nothing
         * should be done
         */
        else
        {
            // hopefully this isn't bad :~
            return array<int, 2> {x, y};
        }

        // add the new location to points
        points.emplace(array<int, 2> {x, y});

        return array<int, 2> {x, y};
    }

    // return the number of points (houses) visited
    int num_points()
    {
        return points.size();
    }
};

int main()
{
    ifstream finput { "day3_input.txt" };

    string input;
    finput >> input;

    Carrier santa;
    Carrier robo;
    set<array<int, 2>> points {array<int, 2> {0, 0}};

    for (size_t i=0; i<input.size(); i++)
    {
        if (i%2 == 0)
        {
            points.emplace(santa.travel(input[i]));
        }
        else
        {
            points.emplace(robo.travel(input[i]));
        }
    }

    cout << "Santa visited " << santa.num_points()
        << " houses, and Robo-Santa visited " << robo.num_points()
        << " houses." << endl;
    cout << "Together, they visited " << points.size() << " houses."
        << endl;
    return 0;
}
