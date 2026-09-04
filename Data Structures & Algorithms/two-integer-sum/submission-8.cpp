class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int difference;
        vector<int> ans;
        unordered_map<int, int>::iterator it;

        unordered_map<int, int> dict;

        for(int i = 0; i < nums.size(); i++) {
            difference = target - nums[i];

            it = dict.find(difference);

            if(it != dict.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
            }
            dict[nums[i]] = i; 
        }

        return ans;
    }
};
