class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int counter = 0;
        if(coins < costs[0])
             return 0;
        for(int i = 0; i < costs.size(); i++)
        {
            coins -= costs[i];
            if(coins < 0)
                return counter;
            counter++;
        }
        return counter;
    }
};