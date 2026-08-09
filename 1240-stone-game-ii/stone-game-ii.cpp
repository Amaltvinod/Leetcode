class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        for (int i = n - 2; i >= 0; i--)
            piles[i] += piles[i + 1];

        unordered_map<int, int> memo;

        auto dfs = [&](this auto&& dfs, int i, int m) -> int {
            int key = i * 101 + m;

            if (memo.count(key))
                return memo[key];

            if (i + 2 * m >= n)
                return piles[i];

            int ans = 0;

            for (int x = 1; x <= 2 * m; x++) {
                ans = max(ans,
                          piles[i] - dfs(i + x, max(m, x)));
            }

            return memo[key] = ans;
        };

        return dfs(0, 1);
    }
};