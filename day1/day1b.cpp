#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>

int findValueInSubstring(const std::string& substring, const std::map<std::string, int>& myMap);

using namespace std;

int main() {
    map<string, int> numberMap = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };
    int is_digit_spelled;
    ifstream infile("day1.in");
    string line;
    string cal_value_str;
    int cal_value;
    int i, sum = 0;
    int y;

    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    char first_digit, last_digit;

    while (getline(infile, line)) {
        y = line.size();
        i = 0;
        string first_sub, second_sub;
        while (i < y) {
            if (isdigit(line[i])) {
                first_digit = line[i];
                break;
            }
            first_sub = line.substr(0, i+1);
            is_digit_spelled = findValueInSubstring(first_sub, numberMap);
            if (is_digit_spelled != -1) {
                first_digit = is_digit_spelled + '0';
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
            second_sub = line.substr(y, line.size() - y);
            is_digit_spelled = findValueInSubstring(second_sub, numberMap);
            if (is_digit_spelled != -1) {
                last_digit = is_digit_spelled + '0'; 
                break;
            }
        }

        cal_value_str = string(1, first_digit) + last_digit;
        cal_value = stoi(cal_value_str);
        cout << cal_value << endl;
        sum += cal_value;
    }

    cout << sum << endl;
    infile.close();
    return 0;
}

int findValueInSubstring(const std::string& substring, const std::map<std::string, int>& myMap) {
    for (const auto& pair : myMap) {
        if (substring.find(pair.first) != std::string::npos) {
            return pair.second;
        }
    }

    return -1;
}