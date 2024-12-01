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

int Solution::numDecodings(string str) {

    int n = str.length();
    vector<int>dp(n+1,-1);
    if (n == 0 || str[0] == '0') return 0; // If the string starts with '0', no valid decoding

    dp[0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        int op1=0,op2 =0;
        if(str[i-1]!='0')
            op1 = dp[i-1];
    
        if(i-2>=0){
        
            string t = str.substr(i-2,2);
    
            if(stoi(t)<=26 && stoi(t)>=10)
                op2 = dp[i-2];
        }
    
        dp[i] = (op1+ op2)%1000000007;
    }
    
    return dp[n];
}