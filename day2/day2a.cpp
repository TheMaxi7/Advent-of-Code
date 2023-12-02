#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream infile("day2.in");
    string line;
    int i = 0;
    int game_number = 0, valid_games_sum = 0;

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
        bool game_valid = true;
        int set_number = 0;

        while (getline(iss, game, ';')) {
            set_number++;
            istringstream tokenStream(game);
            int setRed = 12, setGreen = 13, setBlue = 14;

            while (tokenStream >> value >> color) {
                if (color.find("blue") != string::npos)
                    setBlue -= value;
                else if (color.find("green") != string::npos)
                    setGreen -= value;
                else if (color.find("red") != string::npos)
                    setRed -= value;
            }

            if (setRed < 0 || setGreen < 0 || setBlue < 0) {
                game_valid = false;
                break;
            }
            i = 0;
        }

        if (game_valid) {
            valid_games_sum += game_number;
        }
    }

    cout << "Total sum of valid games: " << valid_games_sum << endl;
    infile.close();
    return 0;
}
