class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
  unordered_map<int, int> indexMap;
    for (int i = 0; i < arr2.size(); ++i) {
        indexMap[arr2[i]] = i;
    }

    // Partition arr1 into two parts
    vector<int> part1;
    vector<int> part2;
    
    for (int num : arr1) {
        if (indexMap.find(num) != indexMap.end()) {
            part1.push_back(num);
        } else {
            part2.push_back(num);
        }
    }

    // Sort part1 based on their order in arr2 using indexMap
    sort(part1.begin(), part1.end(), [&indexMap](int a, int b) {
        return indexMap[a] < indexMap[b];
    });

    // Sort part2 in ascending order
    sort(part2.begin(), part2.end());

    // Combine the sorted parts
    part1.insert(part1.end(), part2.begin(), part2.end());
    
    return part1;
}
};



// Question Description
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
