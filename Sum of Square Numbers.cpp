class Solution {
public:
    bool judgeSquareSum(int c) {
      if (c < 0) {
            return false;
        }
        long long a = 0;
        long long b = static_cast<long long>(sqrt(c));
        
        while (a <= b) {
            long long sumOfSquares = a * a + b * b;
            if (sumOfSquares == c) {
                return true;
            } else if (sumOfSquares < c) {
                ++a;
            } else {
                --b;
            }
        }
        
        return false;
    }
};
