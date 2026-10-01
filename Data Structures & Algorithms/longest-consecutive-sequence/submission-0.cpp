class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        int length;

        for(int& n: nums) {
            if(!numSet.count(n - 1)) {
                length = 0;
                while(numSet.count(n + length)) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
