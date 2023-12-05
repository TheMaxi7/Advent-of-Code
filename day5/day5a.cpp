#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;

long long seedToLocation(const long long& seed, const vector<vector<long long>>& map);

int main() {
    ifstream infile("day5.in");
    string line;
    string seeds_string;
    string seed_str;
    long long i = 0;

    if (!infile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    getline(infile, line);
    long long y = line.size();
    i = 0;
    while (i < y && line[i] != ':') {
        i++;
    }
    if (i < y) {
        seeds_string = line.substr(i + 1, y);
        i = 0;
    }

    vector<vector<long long>> seedToSoilMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        seedToSoilMap.push_back(row);
    }

    vector<vector<long long>> soilToFertilizerMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        soilToFertilizerMap.push_back(row);
    }

    vector<vector<long long>> fertilizerToWaterMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        fertilizerToWaterMap.push_back(row);
    }

    vector<vector<long long>> waterToLightMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        waterToLightMap.push_back(row);
    }

    vector<vector<long long>> lightToTemperatureMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        lightToTemperatureMap.push_back(row);
    }

    vector<vector<long long>> temperatureToHumidityMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        temperatureToHumidityMap.push_back(row);
    }

    vector<vector<long long>> humidityToLocationMap;
    getline(infile, line);
    while (getline(infile, line) && line != "") {
        istringstream mapStream(line);
        long long value;
        vector<long long> row;
        while (mapStream >> value) {
            row.push_back(value);
        }
        humidityToLocationMap.push_back(row);
    }
    
    infile.close();
    long long seedValue;
    long long min = LLONG_MAX; 
    istringstream tokenStream(seeds_string);
    while (tokenStream >> seed_str) {
            seedValue = std::stoll(seed_str);
            seedValue = seedToLocation(seedValue, seedToSoilMap);
            seedValue = seedToLocation(seedValue, soilToFertilizerMap);
            seedValue = seedToLocation(seedValue, fertilizerToWaterMap);
            seedValue = seedToLocation(seedValue, waterToLightMap);
            seedValue = seedToLocation(seedValue, lightToTemperatureMap);
            seedValue = seedToLocation(seedValue, temperatureToHumidityMap);
            seedValue = seedToLocation(seedValue, humidityToLocationMap);
            if (min > seedValue) min = seedValue;
    }
    cout << min << endl;

    return 0;
}

long long seedToLocation(const long long& seed, const vector<vector<long long>>& map) {
    for (const auto& row : map) {
        for (long long value : row) {
            long long destRangeStart = row[0];
            long long sourceRangeStart = row[1];
            long long rangeLength = row[2];

            if (seed >= sourceRangeStart && seed < (sourceRangeStart + rangeLength)) {
                long long dest = destRangeStart + (seed - sourceRangeStart);
                return dest;
            }
        }
    }
    long long dest = seed;
    return dest;
}