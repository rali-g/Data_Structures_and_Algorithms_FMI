class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int firstStringHistogram[26];
        for(int i = 0; i < s.size(); i++)
        {
            firstStringHistogram[s[i] - 'a'] = i;
        }
        int permutations = 0;
        for(int i = 0; i < t.size(); i++)
        {
            permutations += abs(firstStringHistogram[t[i] - 'a'] - i);
        }
        return permutations;
    }
};