class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
         std::vector<std::pair<int, int>> jobs;
        int n = difficulty.size();
        
        for (int i = 0; i < n; ++i) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());
        
        int max_profit = 0, total_profit = 0, job_index = 0;
        int num_jobs = jobs.size();
        
        for (int ability : worker) {
            while (job_index < num_jobs && jobs[job_index].first <= ability) {
                max_profit = std::max(max_profit, jobs[job_index].second);
                job_index++;
            }
            total_profit += max_profit;
        }
        
        return total_profit;
    
    }
};
