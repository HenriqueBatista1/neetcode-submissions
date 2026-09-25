class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        for(auto it: mp) {
            buckets[it.second].push_back(it.first);
        }

        for(int i = buckets.size() - 1; i >= 0; i--) {
            for(int v: buckets[i]) {
                ans.push_back(v);

                if(ans.size() == k) return ans;
            }
        }

        return ans;

    }
};
