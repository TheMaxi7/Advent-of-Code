#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ifstream infile("day4.in");
    string line;
    string valid_numbers;
    string my_numbers;
    string number;
    int i = 0;
    int card_points = 0;
    int total_points = 0;
    int winning_numbers = 0;

    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(infile, line)) {
        int y = line.size();
        i = 0;
        card_points = 0;
        winning_numbers = 0;
        while (i < y && line[i] != ':') {
            i++;
        }

        if (i < y) {
            line = line.substr(i + 1, y);
            i = 0;

            cout << line << endl;

            while (i < y && line[i] != '|') {
                i++;
            }

            valid_numbers = line.substr(0, i);
            my_numbers = line.substr(i + 1, y);
            cout << "valid numbers: " << valid_numbers << endl;
            cout << "my numbers: " << my_numbers << endl;

            istringstream tokenStream(my_numbers);

            while (tokenStream >> number) {
                if (valid_numbers.find(" " + number + " ") != string::npos) {
                    cout << "found:" << number << endl;
                    card_points = 1;
                    winning_numbers++;
                }
            }

            card_points = card_points * pow(2, winning_numbers - 1);
            total_points += card_points;
        }
    }
    cout << total_points << endl;
    infile.close();
    return 0;
}

