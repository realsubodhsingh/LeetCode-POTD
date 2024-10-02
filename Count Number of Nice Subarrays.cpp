class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     // Convert nums to an array of 1s and 0s (1 for odd, 0 for even)
    for (int& num : nums) {
        num = num % 2;
    }
    
    // Map to store the count of prefix sums
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1;  // To handle the case when the prefix sum is exactly k at some index
    
    int prefixSum = 0;
    int result = 0;
    
    // Traverse the array and calculate the number of nice subarrays
    for (int num : nums) {
        prefixSum += num;
        
        // If there's a prefixSum that, when subtracted by k, is present in the map,
        // it means there's a subarray ending at the current index with exactly k odd numbers.
        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            result += prefixCount[prefixSum - k];
        }
        
        // Update the count of the current prefixSum in the map
        prefixCount[prefixSum]++;
    }
    
    return result;
}
};
