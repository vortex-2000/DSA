//https://leetcode.com/problems/wildcard-matching

// recursive
class Solution {
public:

    int worker(string wild, string pattern, int i, int j, vector<vector<int>>&dp)
    {
        
        if(i==wild.length() && j==pattern.length())
            return 1;
        
        if(i==wild.length())
            return 0;
        
        if(j==pattern.length())
        {
            while(wild[i]=='*')
                i++;
            if(i==wild.length())
                return 1;
            return 0;
        }

        if(dp[i][j]>-1) return dp[i][j];
        
        int op1 = 0;
        
        if(wild[i] == pattern[j] || wild[i] == '?')
            op1 = worker(wild, pattern, i+1, j+1,dp);

        
        int op3 = 0;
       if(wild[i] == '*')
       {

                op3  = worker(wild, pattern, i + 1, j, dp) || worker(wild, pattern, i, j + 1, dp);

       }

        
        dp[i][j] = (op1 || op3);

        return dp[i][j];
        
    }
    
    

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.length(), vector<int>(s.length(), -1 ));
        return worker(p, s, 0,0,dp);

    }
};


//iterative

class Solution {
public:
    bool isMatch(string s, string p) {
    int n = p.length();
    int m = s.length();

    // dp[i][j] represents whether p[0..i-1] matches s[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: empty pattern matches empty string
    dp[0][0] = 1;

    // Initialize first column (pattern matching empty string)
    for (int i = 1; i <= n; ++i) {
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 1][0];
        else
            break; // Stop initialization as non-'*' characters can't match an empty string
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } else if (p[i - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches zero or more characters
            }
        }
    }

    return dp[n][m];
}
};