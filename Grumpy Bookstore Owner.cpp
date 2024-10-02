class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int always_satisfied = 0;

    // Calculate always satisfied customers
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            always_satisfied += customers[i];
        }
    }

    // Calculate the initial extra satisfied customers for the first window
    int extra_satisfied = 0;
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            extra_satisfied += customers[i];
        }
    }

    int max_extra_satisfied = extra_satisfied;

    // Slide the window across the array
    for (int i = minutes; i < n; ++i) {
        if (grumpy[i - minutes] == 1) {
            extra_satisfied -= customers[i - minutes];
        }
        if (grumpy[i] == 1) {
            extra_satisfied += customers[i];
        }
        max_extra_satisfied = max(max_extra_satisfied, extra_satisfied);
    }

    return always_satisfied + max_extra_satisfied;
}

};
