// problem Link: https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


public:
	int worker(string s1,string s2,int i1, int i2,vector<vector<int>>&dp)
{
	if(i1==s1.length() && i2==s2.length())
		return 0;

	if(i1==s1.length())
		return (s2.length()-i2);
	if(i2==s2.length())
		return (s1.length()-i1);
		
	if(dp[i1][i2]>-1)
	    return dp[i1][i2];

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX,op4=INT_MAX;

	if(s1[i1]==s2[i2])
		op1 = worker(s1,s2,i1+1,i2+1,dp);
	else{
		op2 = 1+ worker(s1,s2,i1,i2+1,dp);
		op3 = 1+ worker(s1,s2,i1+1,i2,dp);
		op4 = 2+ worker(s1,s2,i1+1,i2+1,dp);
	}

	

	dp[i1][i2] =  min(op4,min(op1,min(op2,op3)));
	
	return dp[i1][i2];
}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    
	    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
	    

	    for(int i=0;i<=m;i++)
	        dp[0][i] = i;
	       
	    for(int j=0;j<=n;j++)
	        dp[j][0] = j;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            int op4 = INT_MAX;
	            if(str1[i-1] == str2[j-1])
	            {
	                op4 = dp[i-1][j-1];
	            }
	            int op1 = 1 + dp[i][j-1];
	            int op2 = 1 + dp[i-1][j];
	            int op3 = 2 + dp[i-1][j-1];
	            
	            dp[i][j] = min(op1,min(op2,min(op3,op4))); 
	        }
	    }
	    
	    
	    return dp[n][m];
	    
	} 