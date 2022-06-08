#include <array>
#include <iostream>
#include <fstream>

// dimensions of the light grid
const int WIDTH = 1000;
const int HEIGHT = 1000;

enum Instructions
{
    turn_on,
    turn_off,
    toggle,
};

struct Coords
{
    int x0 {};
    int y0 {};
    int x1 {};
    int y1 {};
};

// overload the insertion operator to make Coords streamable
std::ostream& operator<<(std::ostream& os, const Coords& coords)
{
    return os << "(" << coords.x0 << ", " << coords.y0
              << ") through (" << coords.x1 << ", " << coords.y1 << ")"
              << std::endl;
}

// input string of form "n,n through n,n"
Coords parse_coords(std::string coords)
{
    size_t idx;      // index of where we are in the string after calling stoi
    int c_array[4];  // array of 4 ints to be converted to a Coords
    int i = 0;       // index of coordinate we're currently building

    while (coords.size() > 0)
    {
        // if we're not on a digit, keep going until we are
        if (!std::isdigit(coords[0]))
        {
            coords = coords.substr(1);
            continue;
        }

        c_array[i] = std::stoi(coords, &idx);
        coords = coords.substr(idx);
        i++;
    }

    // probably some better way to do this that I haven't figured out :P
    return Coords
        {
            c_array[0],
            c_array[1],
            c_array[2],
            c_array[3],
        };
}

void execute(
        std::array<std::array<int, WIDTH>, HEIGHT>* grid,
        Instructions inst,
        Coords coords
        )
{
    //std::cout << grid << std::endl;
    //std::cout << grid[0][0] << std::endl;
    //std::cout << *grid << std::endl;
    //std::cout << (*grid)[0][0] << std::endl;

    // this assumes that the 0 coordinate is always less than the 1
    for (int y=coords.y0; y<=coords.y1; y++) {
        for (int x=coords.x0; x<=coords.x1; x++)
        {
            switch (inst)
            {
                case turn_on:
                    (*grid)[y][x]++;
                    break;

                case turn_off:
                    (*grid)[y][x] = std::max(0, (*grid)[y][x] - 1);
                    break;

                case toggle:
                    (*grid)[y][x] += 2;
                    break;
            }
        }
    }
}

// parse a line of input and call the appropriate function
void handle_line(
        std::array<std::array<int, WIDTH>, HEIGHT>* grid,
        std::string line
        )
{
    if (line.substr(0, 7) == "turn on")
    {
        execute(grid, turn_on, parse_coords(line.substr(8)));
    }
    else if (line.substr(0, 8) == "turn off")
    {
        execute(grid, turn_off, parse_coords(line.substr(9)));
    }
    else if (line.substr(0, 6) == "toggle")
    {
        execute(grid, toggle, parse_coords(line.substr(7)));
    }
}

int main()
{
    std::ifstream finput { "day6_input.txt" };
    std::string line;
    
    std::array<std::array<int, WIDTH>, HEIGHT> grid{};

    while (finput)
    {
        std::getline(finput, line);
        // skip empty lines
        if (line.size() == 0)
        {
            continue;
        }

        // parse the line and call the appropriate function
        handle_line(&grid, line);
    }

    // count total brightness
    int count = 0;
    for (size_t y=0; y<grid.size(); y++)
    {
        for (size_t x=0; x<grid[y].size(); x++)
        {
            count += grid[y][x];
        }
    }
    std::cout << count << " brightness" << std::endl;

    return 0;
}
