#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int ticketCount = 0;
    std::cin >> ticketCount;

    vector<bool> tickets(ticketCount + 1);
    int current = 0;
    for (int i = 0; i < ticketCount; i++)
    {
        std::cin >> current;
        if (current > ticketCount || current <= 0)
            continue;
        tickets[current] = true;
    }
    for (size_t i = 1; i <= tickets.size(); i++)
    {
        if (!tickets[i])
        {
            std::cout << i;
            break;
        }
    }
}