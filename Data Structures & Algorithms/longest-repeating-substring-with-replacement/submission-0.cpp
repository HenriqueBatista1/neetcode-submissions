class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};

        int res = 0;
        int left = 0;
        int maxF = 0;

        for(int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;

            maxF = max(maxF, count[s[right] - 'A']);

            while((right - left + 1) - maxF > k) {
                count[s[left] - 'A']--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
