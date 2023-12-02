#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream infile("day2.in");
    string line;
    int i = 0;
    int game_number = 0, total_power = 0;

    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(infile, line)) {
        game_number++;
        int y = line.size();
        while (line[i] != ':')
            i++;
        line = line.substr(i + 1, y);
        istringstream iss(line);
        string game;
        int value;
        string color;
        int minRed = 0, minGreen = 0, minBlue = 0;
        int power = 0;

        while (getline(iss, game, ';')) {
            istringstream tokenStream(game);
            int set_number = 0;

            while (tokenStream >> value >> color) {
                if (color.find("blue") != string::npos) {
                    if (minBlue < value) {
                        minBlue = value;
                    }
                } else if (color.find("green") != string::npos) {
                    if (minGreen < value) {
                        minGreen = value;
                    }
                } else if (color.find("red") != string::npos) {
                    if (minRed < value) {
                        minRed = value;
                    }
                }
            }
            power = minGreen * minRed * minBlue;
            i = 0;
        }
        total_power += power;
    }
    cout << "Total power: " << total_power << endl;
    infile.close();
    return 0;
}
