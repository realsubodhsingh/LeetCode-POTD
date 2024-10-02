class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if (hand.size() % groupSize != 0) return false;
        
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        for (auto it = count.begin(); it != count.end(); ++it) {
            int start = it->first;
            int numGroups = it->second;
            if (numGroups > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (count[start + i] < numGroups) {
                        return false;
                    }
                    count[start + i] -= numGroups;
                }
            }
        }
        
        return true;
    }
};
