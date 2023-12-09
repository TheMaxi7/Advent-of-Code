#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;
int find_next_value(vector<int>& numbers);
int main() {
    string numbers_stream;
    string number;
    string line;
    int i = 0;
    int next_value;
    int result = 0;
    
    ifstream infile("day9.in");
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    vector<int> line_vect; 
    while (getline(infile, line)) {
        line_vect.clear();
        istringstream numbers_stream(line);
        while (numbers_stream >> number)
            line_vect.push_back(stoi(number));
        next_value = find_next_value(line_vect);
        result += next_value;
    } 
        //cout << next_value << endl;
        
    
    cout << result<<endl;
    
    infile.close();
    return 0;
}

int find_next_value(vector<int>& numbers) {
    int next_value = numbers.back();
    cout << next_value << endl;
    while (true) {
        vector<int> differences;
        int y=numbers.size();
        // Generate a new sequence of differences
        for (int i = 0; i < y-1; i++) {
            differences.push_back(numbers[i + 1] - numbers[i]);
        }
        
        
        // Check if all values in the new sequence are zero
        if (all_of(differences.begin(), differences.end(), [](int diff) { return diff == 0; })) {
            break;  // If all values are zero, exit the loop
        }
        cout << "Last difference" << differences.back() << endl;
        next_value += differences.back();
        cout << "Updated next value" << next_value << endl;
        numbers = differences;
    }

    // The next value is the first element in the final sequence
    return next_value;
}
