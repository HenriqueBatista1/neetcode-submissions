class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};

        int mostFrequent = 0;
        int left = 0;
        int maxLength = 0;
        for(int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;

            mostFrequent = max(mostFrequent, count[s[right] - 'A']);

            while((right - left + 1) - mostFrequent > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
