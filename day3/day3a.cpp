#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int getNumLength(int num)
{
    int length = 1;
    while (num /= 10)
    {
        length++;
    }
    return length;
}

int getPartNumber(const vector<string> &schematic, int row, int col)
{

    if (!isdigit(schematic[row][col]))
    {
        return 0;
    }

    int num = stoi(schematic[row].substr(col));

    if (col > 0 && isdigit(schematic[row][col - 1]))
    {
        return 0;
    }
    int length = getNumLength(num);

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + length; j++)
        {
            if (i < 0 || i >= schematic.size() || j < 0 || j >= schematic[row].size())
            {
                continue;
            }

            char ch = schematic[i][j];
            if (ch != '.' && !isdigit(ch))
            {
                return num;
            }
        }
    }
    return 0;
}

int main()
{
    ifstream infile("day3.in");
    if (!infile)
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    vector<string> schematic;
    string line;
    while (getline(infile, line))
    {
        schematic.push_back(line);
    }
    infile.close();
    int sum = 0;

    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < schematic[i].size(); j++)
        {
            int num = getPartNumber(schematic, i, j);
            if (num > 0)
            {
                sum += num;
            }
        }
    }
    cout << sum << endl;

    return 0;
}