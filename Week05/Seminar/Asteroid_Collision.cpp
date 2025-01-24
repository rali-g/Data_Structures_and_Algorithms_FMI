class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int i = 0; i < asteroids.size(); i++)
        {
            if(asteroids[i] > 0 || result.size() > 0 && result.back() < 0)
            {
                result.push_back(asteroids[i]);
                continue;
            }
            while(result.size() > 0 && result.back() > 0 && abs(asteroids[i]) > result.back())
            {
                result.pop_back();
            }
            if(result.size() <= 0 || result.back() < 0)
            {
                result.push_back(asteroids[i]);
            } 
            else if(result.back() == abs(asteroids[i])) 
            {
                result.pop_back();
            }      
        }
        return result;
    }
};