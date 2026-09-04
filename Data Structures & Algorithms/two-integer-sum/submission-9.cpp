class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int difference;
        vector<int> ans;

        unordered_map<int, int> dict;

        for(int i = 0; i < nums.size(); i++) {
            difference = target - nums[i];

            if(auto it = dict.find(difference); it != dict.end()) {
                return {it->second, i};
            }
            dict[nums[i]] = i; 
        }

        return {};
    }
};
