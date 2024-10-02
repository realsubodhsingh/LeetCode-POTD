class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
 deque<int> maxDeque, minDeque;
        int left = 0, right;
        int maxLength = 0;

        for (right = 0; right < nums.size(); ++right) {
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }

            maxDeque.push_back(nums[right]);
            minDeque.push_back(nums[right]);

            while (maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[left]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[left]) {
                    minDeque.pop_front();
                }
                ++left;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
