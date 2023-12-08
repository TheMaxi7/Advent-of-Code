#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

void go_left(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count);
void go_right(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count);
int main() {
    string directions;
    string line;
    string node, left, right, start_node, last_visited;
    vector<tuple<string, string, string>> node_map;
    ifstream infile("day8.in");
    char chars[] = "(),=";
    int count = 0;
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
    start_node = "AAA";
    last_visited = start_node;
    bool arrived = false;
    int i;
    
    for (i = 0; last_visited != "ZZZ"; i++) {
        if (i == directions.size())
            i=0;
        if (last_visited == "ZZZ")
            break;
                
        if (directions[i] == 'L') {
            go_left(node_map, last_visited,count);
        }
        if (directions[i] == 'R') {
            go_right(node_map, last_visited, count);
        }
    }
    cout << count << endl;
    return 0;
}

void go_left(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count) {
    for (const auto &tuple : node_map) {
        if (get<0>(tuple) == last_visited) {
            last_visited = get<1>(tuple);
            count++;
            break;
        }
    }
}


void go_right(vector<tuple<string,string,string> >& node_map, string& last_visited, int& count) {
    for (const auto &tuple : node_map) {
        if (get<0>(tuple) == last_visited) {
            last_visited = get<2>(tuple);
            count++;  
            break;
        }
    }
}
