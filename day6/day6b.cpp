#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> 

using namespace std;

int main() {
    string line;
    string time;
    string distance;
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
    time.erase(remove(time.begin(), time.end(), ' '), time.end());

    getline(infile, line);
    y = line.size();
    i = 0;
    while (i < y && line[i] != ':') {
        i++;
    }
    distance = line.substr(i+1, y);
    distance.erase(remove(distance.begin(), distance.end(), ' '), distance.end());
    int win = 0;

    
    for (int k = 0; k < stoll(time); k++) {
        if ((k*(stoll(time)-k)) > stoll(distance)) {
            win++;
        }
    }
    cout << win<<endl;

}