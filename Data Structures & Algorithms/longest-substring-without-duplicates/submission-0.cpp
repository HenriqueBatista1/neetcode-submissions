class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> window;
        int maxLen = 0;
        for(int right = 0; right < s.size(); right++) {

            while(window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }

            window.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
