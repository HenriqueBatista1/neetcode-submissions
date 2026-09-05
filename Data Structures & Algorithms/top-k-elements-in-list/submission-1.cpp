class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        for (int val: nums) {
            freq[val]++;
        }

        for (auto& it: freq) {
            pq.push({it.second, it.first});
        }

        for(int i = 0; i < k; i++) {
            pair<int, int> atual = pq.top();
            ans.push_back(atual.second);
            pq.pop();
        }

        return ans;
    }
};
