#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
#include <numeric>

using namespace std;

void go_left(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count);
void go_right(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count);
int main() {
    string directions;
    string line;
    string node, left, right, last_visited;
    vector<string> starting_nodes;
    vector<tuple<string, string, string>> node_map;
    vector<int> steps;
    ifstream infile("day8.in");
    char chars[] = "(),=";
    int count = 0;
    unsigned long lcm = 1;
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    getline(infile, directions);
    while (getline(infile, line)) {
        if (line.size() == 0)              
            continue; 
        for (unsigned int i = 0; i < strlen(chars); ++i) {
            line.erase (remove(line.begin(), line.end(), chars[i]), line.end());
        }      
        istringstream nodesStream(line);
        nodesStream >> node >> left >> right;
        node_map.emplace_back(node, left, right);
    }

    infile.close();

    for (const auto &tuple : node_map) {
        if (get<0>(tuple)[2] == 'A') {
            starting_nodes.push_back(get<0>(tuple));
        }
    }
    bool arrived = false;
    int i = 0;
    for (const auto &string : starting_nodes) {
        last_visited = string;
        for (i = 0; last_visited[2] != 'Z'; i++) {
            if (i == directions.size())
                i = 0;
            if (last_visited[2] == 'Z')
                break;
            if (directions[i] == 'L') {
                go_left(node_map, last_visited,count);
            }
            if (directions[i] == 'R') {
                go_right(node_map, last_visited, count);
            }
        }
        steps.push_back(count);
        count=0;
    }

    for (const auto &num : steps) {
        lcm = num / gcd(num, lcm) * lcm; 
    }cout << lcm << endl;
    return 0;


}

void go_left(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count) {
    for (const auto &tuple : node_map) {
        if (get<0>(tuple) == last_visited) {
            last_visited = get<1>(tuple);
            count++;
            //cout << count << " " << "Visited  " << last_visited << endl;
            break;
        }
    }
}


void go_right(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count) {
    for (const auto &tuple : node_map) {
        if (get<0>(tuple) == last_visited) {
            last_visited = get<2>(tuple);
            count++;
            //cout << count << " " << "Visited  " << last_visited << endl;
            break;
        }
    }
}
