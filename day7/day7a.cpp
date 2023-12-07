#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool pokerCompare(const string &a, const string &b) {
    string strengthOrder = "AKQJT98765432";
    for (int i = 0; i < a.size() && i < b.size(); ++i) {
        size_t indexA = strengthOrder.find(a[i]);
        size_t indexB = strengthOrder.find(b[i]);

        if (indexA > indexB) {
            return true;
        } else if (indexA < indexB) {
            return false;
        }
    }
    return a.size() < b.size();
}

bool sortbyth(const tuple<string, int, int> &a, const tuple<string, int, int> &b) {
    if (get<2>(a) < get<2>(b)) {
        return true;
    } else if (get<2>(a) > get<2>(b)) {
        return false;
    }
    return pokerCompare(get<0>(a), get<0>(b));
}

int check_hand_type(string hand);

int main() {
    string line;
    vector<tuple<string, int, int>> hands;
    string hand;
    int value;
    ifstream infile("day7.in");
    int rank = 0;
    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(infile, line)) {
        
        istringstream handStream(line);
        handStream >> hand >> value;
        int type = check_hand_type(hand);
        hands.emplace_back(hand, value, type);
    }

    infile.close();

    sort(hands.begin(), hands.end(), sortbyth);
    int hand_value = 0;
    int result = 0;
    for (const auto &tuple : hands) {
        rank++;
        hand_value = get<1>(tuple) * rank;
        result += hand_value;
        cout << "Hand: " << get<0>(tuple) << " Value: " << get<1>(tuple) << " Type: " << get<2>(tuple) << endl;

    }
    cout << result << endl;
    return 0;
}


int check_hand_type (string hand){
    int type = 1;
    int count = 1;
    int pair_amount = 0;
    int tris= 0;
    bool four_of_a_kind = false;
    bool five_of_a_kind = false;
    int l = hand.size();
    //cout << hand <<endl;
    for (int i = 0; i < l; i++) {
        count = 1;
        for(int j = i+1; j < l; j++) {
            if(hand[i] == hand[j] && hand[i] != '0') { 
                count++; 
                hand[j] = '0'; 
                if (count == 2)
                    pair_amount += 1;
                if (count == 3) {
                    tris += 1;
                    pair_amount -= 1;
                }
                if (count==4)
                    four_of_a_kind = true;
                if (count==5)
                    five_of_a_kind = true;
            }
        }
    }
    if (pair_amount == 1) 
        type = 2;
    if (pair_amount == 2)
        type = 3;
    if (tris == 1)
        type = 4;
    if (tris == 1 && pair_amount ==1)
        type = 5;
    if (four_of_a_kind)
        type = 6;
    if (five_of_a_kind)
        type = 7;
    //cout << "Type: " << type << endl;
    //cout << "Pairs: " << pair_amount << endl;
    //cout << "Tris: " << tris << endl;
    return type;
}
    
    








