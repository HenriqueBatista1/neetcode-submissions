class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        bool check = true;

        while(left < right) {

            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) {
                check = false;
            }

            left++;
            right--;
        }

        return check;
    }
};
