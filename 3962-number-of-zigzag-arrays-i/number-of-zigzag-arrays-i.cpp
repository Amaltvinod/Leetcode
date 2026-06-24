class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1000000007LL;

        int k = r - l + 1;

        if (n == 1) return k;

        vector<long long> up(k + 1), down(k + 1);

        // Length = 2
        for (int i = 1; i <= k; i++) {
            up[i] = i - 1;      // last move increasing
            down[i] = k - i;    // last move decreasing
        }

        for (int len = 3; len <= n; len++) {

            vector<long long> prefUp(k + 1, 0);
            vector<long long> prefDown(k + 1, 0);

            for (int i = 1; i <= k; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            long long totalUp = prefUp[k];

            for (int i = 1; i <= k; i++) {
                long long newUp = prefDown[i - 1];
                long long newDown = (totalUp - prefUp[i] + MOD) % MOD;

                up[i] = newUp;
                down[i] = newDown;
            }
        }

        long long ans = 0;

        for (int i = 1; i <= k; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};