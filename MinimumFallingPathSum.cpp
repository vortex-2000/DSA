
//Problem link: https://leetcode.com/problems/minimum-falling-path-sum/


// Approach 1

class Solution {
public:
    int worker(vector<vector<int>>& mat, int i,int j,vector<vector<int>>&dp)
    {
        if(i==mat.size())
            return 0;

        if(j>=mat.size() || j<0)
            return 1000;

        if(dp[i][j]>-1) return dp[i][j];
     
        dp[i][j] =  mat[i][j] + min({worker(mat,i+1,j-1,dp), worker(mat,i+1,j,dp), worker(mat,i+1,j+1,dp)});

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        int ans=INT_MAX;
        for(int i=0;i<mat.size();i++)
        {
            ans = min(ans,worker(mat,0,i,dp));
        }
        return ans;
    }
};

// Approach 2

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            prev[i] = mat[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

                if (j + 1 < n)
                    op1 = prev[j + 1];
                op2 = prev[j];
                if (j - 1 >= 0)
                    op3 = prev[j - 1];

                curr[j] = mat[i][j] + min({op1, op2, op3});
            }
            prev = curr;
        }

        for (int i = 0; i < mat.size(); i++) {
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};

//Approach 3

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            prev[i] = mat[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;

                if (j + 1 < n)
                    op1 = prev[j + 1];
                op2 = prev[j];
                if (j - 1 >= 0)
                    op3 = prev[j - 1];

                curr[j] = mat[i][j] + min({op1, op2, op3});
            }
            prev = curr;
        }

        for (int i = 0; i < mat.size(); i++) {
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};