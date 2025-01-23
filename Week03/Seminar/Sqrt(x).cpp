class Solution {
public:
    int mySqrt(int x) {
        long left = 0;
        long right = x;
        while(left <= right)
        {
            long mid = left + (right - left) / 2;
            if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return mid;
            if(mid * mid < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};