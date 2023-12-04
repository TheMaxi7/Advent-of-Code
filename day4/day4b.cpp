#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream infile("day4.in");
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string line, valid_numbers, my_numbers, number;
    int card_number = 0;
    vector<pair<int, int>> card_data;

    while (getline(infile, line)) {
        card_number++;
        int y = line.size();
        int i = 0, card_copies = 1, winning_numbers = 0;

        while (i < y && line[i] != ':') {
            i++;
        }

        if (i < y) {
            line = line.substr(i + 1, y);
            i = 0;

            while (i < y && line[i] != '|') {
                i++;
            }

            valid_numbers = line.substr(0, i);
            my_numbers = line.substr(i + 1, y);

            istringstream tokenStream(my_numbers);

            while (tokenStream >> number) {
                if (valid_numbers.find(" " + number + " ") != string::npos) {
                    winning_numbers++;
                }
            }
            card_data.emplace_back(winning_numbers, card_copies);
        }
    }

    for (int k = 0; k < card_number; k++) {
        int current_copy = card_data[k].second;
        for (int j = k + 1; j < k + card_data[k].first + 1; j++) {
            card_data[j].second += current_copy;
        }
    }

    for (const auto& card : card_data) {
        cout << "Winning Numbers: " << card.first << ", Card Copies: " << card.second << endl;
    }

    int total_points = 0;
    for (const auto& card : card_data) {
        total_points += card.second;
    }

    cout << "Total Points: " << total_points << endl;
    infile.close();
    return 0;
}
