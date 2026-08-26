class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<int, int> mp;
        int cnt = 0, n = s.size();

        string ans = "";

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') {
                cnt++;
                mp[cnt] = r;

                if (mp.count(cnt - k + 1)) {
                    int l = mp[cnt - k + 1];
                    string curr = s.substr(l, r - l + 1);

                    if (ans.empty() || curr.size() < ans.size() ||
                        (curr.size() == ans.size() && curr < ans)) {
                        ans = curr;
                    }
                }
            }
        }

        return ans;
    }
};