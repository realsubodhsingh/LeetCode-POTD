class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
        int flips = 0, flipCount = 0;
        deque<int> flipQueue;
        
        for (int i = 0; i < n; ++i) {
            // Remove the flips that are out of the range of the current index
            if (!flipQueue.empty() && flipQueue.front() == i) {
                flipQueue.pop_front();
                flipCount--;
            }
            
            // If nums[i] needs to be flipped (odd flipCount for 0 or even flipCount for 1)
            if ((nums[i] == 0 && flipCount % 2 == 0) || (nums[i] == 1 && flipCount % 2 == 1)) {
                if (i + k > n) return -1; // If there are not enough elements to flip
                flipQueue.push_back(i + k);
                flipCount++;
                flips++;
            }
        }
        
        return flips;
    }    
    
};
