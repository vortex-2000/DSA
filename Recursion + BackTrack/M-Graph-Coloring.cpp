 bool checker(int sv,int c,vector<vector<int>>&adj,vector<int>&color)
    {
        for(auto i: adj[sv])
        {
            if(color[i] == c)
                return false;
        }
        return true;
    }
    
    bool worker(vector<vector<int>>&adj,int sv,vector<int>&color,int m)
    {
        if(sv == adj.size())
            return true;
        
        for(int i=0;i<m;i++)
        {
            if(checker(sv,i,adj,color))
            {
                color[sv] = i;
                if(worker(adj,sv+1,color,m))
                    return true;
                color[sv] = -1;
                
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(graph[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> color(n,-1);
        return worker(adj,0,color,m);
    }