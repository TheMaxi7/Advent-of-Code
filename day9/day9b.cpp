#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int calculate_next_value(vector<int>& sequence) {
  if (sequence.size() == 1) {
    sequence.push_back(sequence.back());
    return sequence.back();
  }
  vector<int> new_sequence;
  new_sequence.reserve(sequence.size() - 1);
  for (int i = 0; i < sequence.size() - 1; i++) {
    new_sequence.push_back(sequence[i+1] - sequence[i]);
  }
  if (any_of(sequence.begin(), sequence.end(), [](int ele) { return ele != 0; })) {
    const auto value_to_add = calculate_next_value(new_sequence); 
    sequence.push_back(sequence.back() + value_to_add);
    return sequence.back();
  } 
  sequence.push_back(sequence.back());
  return sequence.back();
}

vector<int> extract_numbers(const string& s) {
  vector<int> numbers;
  size_t start = 0;
  size_t end = s.find(' ', start);
  while (end != string::npos) {
    numbers.push_back(stoi(s.substr(start, end - start)));
    start = end + 1;
    end = s.find(' ', start);
  }
  numbers.push_back(stoi(s.substr(start, s.size() - start)));
  return numbers;
}

int main() {
  string input_file = "day9.in";
  ifstream infile(input_file);
  if (!infile.is_open()) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  string line;
  vector<vector<int>> sequences;
  while(getline(infile, line)) {
    if (line.empty()) continue;
    sequences.push_back(extract_numbers(line));
  } 
  int result = 0;
  for (auto& sequence : sequences) {
    reverse(sequence.begin(), sequence.end());
    result += calculate_next_value(sequence);
  }
  cout << result;
  
  infile.close();
  return 0;
}