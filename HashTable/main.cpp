#include "HT.h"
#include <iostream>
#include <vector>
#include <unordered_map>


bool itemInCommon(std::vector<int> vect1, std::vector<int> vect2) {
    std::unordered_map<int, bool> myMap;

    for (auto i: vect1) {
        myMap.insert({i, true});
    }

    for (auto j: vect2) {
        if(myMap[j]) return true;
    }
    return false;
}


int main() {
    std::vector<int> vect1 {1, 3, 4};
    std::vector<int> vect2 {2, 4, 9};
    
    return 0;
}