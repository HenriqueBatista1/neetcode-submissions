class TimeMap {

private:
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }
 
    void set(string key, string value, int timestamp) { 
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";

        int left = 0;
        int right = mp[key].size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (mp[key][mid].first <= timestamp) {
                ans = mp[key][mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
