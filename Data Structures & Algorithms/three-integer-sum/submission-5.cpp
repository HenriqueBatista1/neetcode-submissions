class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int threeSum;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            threeSum = 0;

            while(j < k && j <= nums.size() - 1) {
                threeSum = nums[j] + nums[k] + nums[i];

                if (threeSum < 0) {
                    j++;
                }
                else if(threeSum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j - 1] && j < k) j++;
                }
            }
        }

        return ans;
    }
};
