class Solution {
public:

    int sum_dig(int n) {
        int s = 0;

        while(n > 0) {
            int digit = n % 10;
            s += digit * digit;
            n = n / 10;
        }

        return s;
    }

    bool isHappy(int n) {
        unordered_set<int> mp;

        while(1) {
            n = sum_dig(n);

            if(n == 1) return true;
            if(mp.count(n)) return false;

            mp.insert(n);
        }
    }
};