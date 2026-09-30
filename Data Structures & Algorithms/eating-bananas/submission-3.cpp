class Solution {
public:

    int check_hours(vector<int>& piles, int k) {
        int total_hours = 0;

        for(int i = 0; i < piles.size(); i++) {
            total_hours += (piles[i] + k - 1) / k;
        }

        return total_hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int answer = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(check_hours(piles, mid) <= h) {
                answer = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return answer;
    }
};
