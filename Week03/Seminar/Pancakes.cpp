#include <iostream>
using namespace std;

long long cookersTime[100000]{};
long long calculcateOptimalPancakes(long long cookers, long long time)
{
    long long currentPancakes = 0;
    for(long long i = 0; i < cookers; i++)
    {
        currentPancakes += (time / cookersTime[i]);
    }
    return currentPancakes;
}

int main() {
    long long pancakes = 0;
    long long cookers = 0;
    std::cin >> pancakes >> cookers;
    for(int i = 0; i < cookers; i++)
    {
        std::cin >> cookersTime[i];
    }
    
    long long left = 0;
    long long right = cookersTime[0] * pancakes;
    long long endTime = right;
    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long currentPancakes = calculcateOptimalPancakes(cookers, mid);
        if(currentPancakes >= pancakes)
        {
            endTime = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    std::cout << endTime;
}