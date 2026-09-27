class Solution {
public:

    int sum_dig(int n) {
        int sum = 0;

        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = sum_dig(n);

        while(fast != 1 && slow != fast) {
            slow = sum_dig(slow);
            fast = sum_dig(sum_dig(fast));
        }

        return fast == 1;
    }
};