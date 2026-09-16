class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        int diff;

        for(int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];

            auto it = dict.find(diff);

            if(it != dict.end()) {
                return {it->second, i};
            }

            dict[nums[i]] = i;
        }

        return {};
    }
};
