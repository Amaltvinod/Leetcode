class Solution {
    using ll = long long;

    struct Node {
        ll cnt;
        ll sum;
        Node(ll c = 0, ll s = 0) : cnt(c), sum(s) {}
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev1, int prev2, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return Node(1, 0);
        }

        if (!tight && vis[pos][prev1 + 1][prev2 + 1][started]) {
            return dp[pos][prev1 + 1][prev2 + 1][started];
        }

        int lim = tight ? s[pos] - '0' : 9;
        Node res;

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, -1, -1, false, ntight);

                res.cnt += child.cnt;
                res.sum += child.sum;
            } else {
                int add = 0;
                int nprev1, nprev2;

                if (!started) {
                    nprev1 = -1;
                    nprev2 = d;
                } else {
                    if (prev1 != -1) {
                        if ((prev2 > prev1 && prev2 > d) ||
                            (prev2 < prev1 && prev2 < d)) {
                            add = 1;
                        }
                    }

                    nprev1 = prev2;
                    nprev2 = d;
                }

                Node child =
                    dfs(pos + 1, nprev1, nprev2, true, ntight);

                res.cnt += child.cnt;
                res.sum += child.sum + 1LL * add * child.cnt;
            }
        }

        if (!tight) {
            vis[pos][prev1 + 1][prev2 + 1][started] = true;
            dp[pos][prev1 + 1][prev2 + 1][started] = res;
        }

        return res;
    }

    ll solve(ll x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, -1, -1, false, true).sum;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(1LL * num1 - 1);
    }
};