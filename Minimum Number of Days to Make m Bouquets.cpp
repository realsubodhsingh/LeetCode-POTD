class Solution {
public:
    bool canMakeBouquets(const vector<int>& bloomDay, int days, int m, int k) {
    int bouquets = 0;
    int flowers = 0;

    for (int bloom : bloomDay) {
        if (bloom <= days) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0;
        }
        
        if (bouquets >= m) {
            return true;
        }
    }
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    
    // Use long long to handle large m and k
    if ((long long)m * k > n) {
        return -1;
    }
    
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canMakeBouquets(bloomDay, mid, m, k)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
};
