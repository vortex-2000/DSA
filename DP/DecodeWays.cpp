class Solution {
public:
    int worker(string s,int i,vector<int>&dp)
    {
       

        if(i>=s.length())
            return 1;

        int op2 = 0,op1=0;
        if(dp[i]>0) return dp[i];

        if(s[i]!='0')
            op1 = worker(s,i+1,dp);

        if( i+1 < s.length() && s[i]!='0' && stoi(s.substr(i,2)) <= 26)
            op2 = worker(s,i+2,dp);
        
        dp[i] = op1 + op2;
        return op1 + op2;
    }

    int numDecodings(string s) {
        bool notPossible = false;
       vector<int>dp(s.length(),-1);
       int ans = worker(s,0,dp);

       return ans;
    }
};