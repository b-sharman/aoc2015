#include <iostream>
#include <fstream>

using namespace std;

// given a line axbxc, where a, b, and c are integers, return a, b, and c
int * parse(string line)
{
    // static to avoid returning a reference to a local variable
    static int ret[3];

    string current_num = "";

    // are we assembling the first, second, or third number?
    int num_index = 0;

    /* add an x to the line as a simple way to tell the loop to stop looking
     * for a number
     */
    line.append("x");

    /*
     * loop through the string
     * if the current character is not an x
     * assume it is a number and append it to a string
     * otherwise
     * move on to the next string
     */
    for (char c : line)
    {
        if (c == 'x')
        {

            // convert current_num to an int and store it in ret
            ret[num_index] = stoi(current_num, nullptr);

            current_num = "";
            num_index++;

            continue;
        }

        current_num.append(
            // fill constructor: 1 copy of the char c
            string(1, c)
            );
    }

    return ret;
}

/* return the surface area of a right rectangular prism with width w, length l,
 * and height h
 */
int surface_area(int w, int l, int h)
{
    return 2*(l*w + w*h + h*l);
}

/* return the area of the smallest face of a right rectangular prism with
 * width w, length l, and height h
 */
int smallest_face_area(int w, int l, int h)
{
    // TODO: find a less expensive way to compute this
    return min(min(l*w, w*h), h*l);
}

int main()
{
    ifstream finput { "day2_input.txt" };

    // store each line
    string line;

    // store the 3 integers in each box
    int* output;

    // how many square feet of wrapping paper is necessary?
    int total = 0;

    while (finput)
    {
        // read a line
        getline(finput, line);

        // skip the line if it is blank
        if (line.length() < 1)
        {
            continue;
        }

        output = parse(line);

        total += surface_area(output[0], output[1], output[2])
                     + smallest_face_area(output[0], output[1], output[2]);
    }

    cout << total << endl;

    return 0;
}
