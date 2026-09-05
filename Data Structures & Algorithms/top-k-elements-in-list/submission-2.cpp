class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        vector<vector<int>> buckets(n + 1);
        vector<int> ans;
        ans.reserve(k);

        for (int val : nums) {
            freq[val]++;
        }

        for (auto& it : freq) {
            buckets[it.second].push_back(it.first);
        }

        for (int i = buckets.size() - 1; i > 0; i--) {
            for (int val : buckets[i]) {
                ans.push_back(val);
                if (ans.size() == k) return ans; 
            }
        }

        return ans;
    }
};