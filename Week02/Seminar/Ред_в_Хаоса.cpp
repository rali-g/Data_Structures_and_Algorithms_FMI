#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long n = 0;
    std::cin >> n;
    vector<long> input(n);
    int histogram[100000]{0};
    for(long i = 0; i < n; i++)
    {
        std::cin >> input[i];
        histogram[input[i]]++;
    }
    for(int i = 1; i < 100000; i++)
    {
        histogram[i] += histogram[i - 1];
    }
    vector<long> result(n);
    for(long i = n - 1; i >= 0; i--)
    {
        result[i] = histogram[input[i]] - 1;
        histogram[input[i]]--;
    }
    for(long i = 0; i < n; i++)
    {
        std::cout << result[i] << " ";
    }
}
