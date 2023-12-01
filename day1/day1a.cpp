#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream infile("day1.in");
    string line;
    string cal_value_str;
    int cal_value;
    int i, sum= 0;
    int y;

    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    char first_digit, last_digit;

    while (getline(infile, line)) {
        y = line.size();
        i = 0;
        while (i < y) {
            if (isdigit(line[i])) {
                first_digit = line[i];
                break;
            }
            i++;
        }

        while (y > 0) {
            y--;
            if (isdigit(line[y])) {
                last_digit = line[y];
                break;
            }
        }
        
        cal_value_str = string(1, first_digit) + last_digit;
        cal_value = stoi(cal_value_str);
        sum += cal_value;
    }

    cout << sum << endl;
    infile.close();
    return 0;
}
