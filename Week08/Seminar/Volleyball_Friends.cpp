#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int firstSigned = 0;
    std::cin >> firstSigned;
    
    unordered_set<int> s;
    s.insert(firstSigned);
    
    int n = 0;
    std::cin >> n;
    int first = 0, second = 0;
    for(int i = 0; i < n; i++)
    {
        std::cin >> first >> second;
        if(s.count(first))
            s.insert(second);
    }
    std::cout << s.size();
}