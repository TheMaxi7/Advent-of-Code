#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using gearList = vector<int>;

vector<vector<gearList>> gearToNums;

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
    bool hasSymbol = false;
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
                hasSymbol = true;
            }
        }
    }
    if (!hasSymbol)
    {
        return 0;
    }
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + length; j++)
        {
            if (i < 0 || i >= schematic.size() || j < 0 || j >= schematic[row].size())
            {
                continue;
            }
            char ch = schematic[i][j];
            if (ch == '*')
            {
                gearToNums[i][j].push_back(num);
            }
        }
    }
    return num;
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
    gearToNums.resize(schematic.size());
    for (auto &row : gearToNums)
        row.resize(schematic[0].size());
    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < schematic[i].size(); j++)
        {
            getPartNumber(schematic, i, j);
        }
    }

    int sum = 0;
    for (int i = 0; i < schematic.size(); i++)
    {
        for (int j = 0; j < schematic[i].size(); j++)
        {
            if (schematic[i][j] == '*')
            {
                const auto &currentGearList = gearToNums[i][j];
                if (currentGearList.size() == 2)
                {
                    sum += currentGearList[0] * currentGearList[1];
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}