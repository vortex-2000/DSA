//Link: https://www.interviewbit.com/problems/paint-house/

int worker(vector<vector<int> > &arr,int i,int j,vector<vector<int>>&dp)
{
    if(i==arr.size())
        return 0;
    
    if(dp[i][j+1]>-1)
        return dp[i][j+1];
        
    int op=INT_MAX;
    for(int k=0;k<3;k++)
    {
        if(k==j)
            continue;
        
        op = min(op,arr[i][k] + worker(arr,i+1,k,dp));
    }
    dp[i][j+1] = op;
    
    return op;
}


int Solution::solve(vector<vector<int> > &arr) {
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    int ans=worker(arr,0,-1,dp);

    return ans;
};