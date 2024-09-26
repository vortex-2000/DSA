//Problem link: https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    int find_min(int i, int j, int n, vector<vector<int>>& dp) {

        if (i == n) {
            return 0;
        }
        if (i > n) {
            return n;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int paste = 1 + find_min(i + j, j, n, dp);
        int copy = INT_MAX;
        if (i != j) {
            copy = 1 + find_min(i, i, n, dp);
        }

        return dp[i][j] = min(copy, paste);
    }
    int minSteps(int n) {

        if (n == 1) {
            return 0;
        }

        vector<vector<int>> dp(1001, vector<int>(1001, -1));

        return 1 + find_min(1, 1, n, dp);
    }
};