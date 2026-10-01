class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;

        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x * x + y * y;

            maxHeap.push({distance, i});

            while(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while(!maxHeap.empty()) {
            auto [distance, index] = maxHeap.top();
            ans.push_back(move(points[index]));
            maxHeap.pop();
        }

        return ans;
    }
};
