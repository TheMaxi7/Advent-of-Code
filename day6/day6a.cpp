#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    string time;
    string distance;
    string race_distance;
    string race_time;
    ifstream infile("day6.in");
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    getline(infile, line);
    int y = line.size();
    int i = 0;
    while (i < y && line[i] != ':') {
        i++;
    }
    time = line.substr(i+1, y);
    vector<string> times;
    istringstream timeToken(time);
    while (timeToken >> race_time) {
        times.push_back(race_time);
    }

    getline(infile, line);
    y = line.size();
    i = 0;
    while (i < y && line[i] != ':') {
        i++;
    }
    distance = line.substr(i+1, y);
    vector<string> distances;
    istringstream distanceToken(distance);
    while (distanceToken >> race_distance) {
        distances.push_back(race_distance);
    }

    int result = 1, cnt = 0;
    for (int i = 0; i < times.size(); i++) {
        cnt = 0;
        for (int k = 0; k < stoll(times[i]); k++) {
            if ((k*(stoll(times[i])-k)) > stoll(distances[i])) {
                cnt++;
            }
        }
        result *= cnt;
    }
    cout << result <<endl;
    return 0;
}







