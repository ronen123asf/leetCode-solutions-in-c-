class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res;
        priority_queue<int> pq[n];

        for(int l = 0; l < n - k + 1; l++){
            for(int i = l; i < l + k; i++)
                pq[l].push(nums[i]);
            
            while(pq[l].size() > k / 2 + 1) pq[l].pop();

            if(k % 2 == 0){
                double low = double(pq[l].top());
                pq[l].pop();
                double high = (double)pq[l].top();
                res.push_back(( low + high )/ 2);
            }

            if(k % 2 == 1) res.push_back(pq[l].top());
        }

        return res;
    }
};
