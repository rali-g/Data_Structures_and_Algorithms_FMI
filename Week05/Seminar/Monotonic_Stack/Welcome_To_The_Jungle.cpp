#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int size = 0;
    std::cin >> size;
    vector<int> nums(size);
    for(int i = 0; i < size; i++)
    {
        std::cin >> nums[i];
    }
    stack<int> st;
    int count = 0;
    int maxCount = -1;
    int index = -1;
    for(int i = size - 1; i >= 0; i--)
    {
        while(!st.empty() && nums[i] >= st.top())
        {
            st.pop();
            count--;
        }
        st.push(nums[i]);
        count++;
        if(count >= maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    std::cout << index;
    return 0;
}
