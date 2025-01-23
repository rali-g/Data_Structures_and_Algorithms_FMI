#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    std::cin >> n;
    vector<string> nums(n);
    for(int i = 0; i < n; i++)
    {   
        std::cin >> nums[i];
    }
    std::sort(nums.begin(), nums.end(), [](auto& first, auto& second){
        return first + second > second + first;
    });
    bool isZero = 1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] != "0")
        {
            isZero = 0;
            break;
        }
    }
    if(isZero)
    {
        std::cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << nums[i];
    }
}
