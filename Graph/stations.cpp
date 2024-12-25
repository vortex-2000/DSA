// Problem Description:
// You are given a set of stations connected by bidirectional paths, where each path has a pass value associated with it. 
// The pass value represents the minimum pass required to travel on that path. The goal is to determine the minimum pass value required to travel from a source station to a destination station.
// Print the path

#include<bits/stdc++.h>
using namespace std;

//Time = O(V+E) Space = O(V+E)
int bfsTraversal(vector<vector<pair<int,int>>>&adj, int src, int dest,int n)
{
	queue<pair<int,int>> q;

	q.push({0,src});
	vector<int> vis(n,INT_MAX);

	while(!q.empty())
	{
		pair<int,int> curr = q.front();
		int currNode  = curr.second;
		int currPass = curr.first;
		q.pop();

		
		for(int i=0;i<adj[currNode].size();i++)
		{
			pair<int,int> p = adj[currNode][i];
			int pass = p.second;
			int nxt = p.first;
			
			int max_pass = max(pass, currPass); // persists traversal's max pass max(curr_pass, prev_pass)

			if(max_pass<vis[nxt]){
				q.push({max_pass, nxt});
				vis[nxt] = max_pass;
			}
		}
	}
	return vis[dest];
}

//Time = O(V+E) Space = O(V+E)
void dfsTraversal(vector<vector<pair<int,int>>>&adj, int src,int dest, int max_pass,int& ans,vector<int>&vis)
{
	if(src == dest){
		ans = min(ans, max_pass);
		return;
	}
	vis[src] = 1;

	for(int i=0;i<adj[src].size();i++)
	{
		pair<int,int> p = adj[src][i];
		int pass = p.second;
		int nxt = p.first;

		if(!vis[nxt])
			dfsTraversal(adj,nxt,dest,max(max_pass, pass),ans,vis);
	}

	vis[src] = 0;
}

//tracks the optimal path by recording the parents  
void printPath(vector<int>par, int src, int dest)
{
	int currNode = dest;
	vector<int>path;

	while(currNode!=-1)
	{
		path.push_back(currNode);
		currNode = par[currNode];
	}

	reverse(path.begin(), path.end());

	for(int i=0;i<path.size();i++)
	{
		cout<<path[i]<<" ";
	}
	return;
}

// TC: less than normal bfs / dfs  - O((V+E)logV)
int dijkstraTraversal(vector<vector<pair<int,int>>>&adj, int src, int dest, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0,src});
	vector<int> vis(n,INT_MAX);	

	vector<int> parent(n,-1);
	vis[src] = 0;

	while(!pq.empty())
	{
		pair<int,int> curr = pq.top();
		int currNode  = curr.second;
		int currPass = curr.first;
		pq.pop();

		if (currNode == dest) {
			printPath(parent, src, dest);
            return currPass; // Found the destination with minimum max pass early exit due to dijkstra
        }

		for(int i=0;i<adj[currNode].size();i++)
		{
			pair<int,int> p = adj[currNode][i];
			int pass = p.second;
			int nxt = p.first;

			
			int max_pass = max(pass, currPass); // persists traversal's max pass max(curr_pass, prev_pass)

			if(max_pass<vis[nxt]){
				pq.push({max_pass, nxt});
				vis[nxt] = max_pass;
				parent[nxt] = currNode;
			}
		}
	}

	return INT_MAX;
}


// Binary search approach involves sorting all the pass values in the stations arrat which will cause a addition of another ElogE TC for sorting and then validating the chosen pass by any traversals, making the total worst case TC: O(ElogE) + O(V + E)logE

int main()
{
	vector<vector<int>> stations = {{0,1,2}, {1,2,50}, {2,3,8}, {3,4,90}, {2,4,100}};

	int n=0;
	for(int i=0;i<stations.size();i++)
	{
		n = max({n, stations[i][0], stations[i][1]});
	}
	
	n++;
	vector<vector<pair<int,int>>>adj(n);

	int src = 0, dest = 4;

	for(int i=0;i<stations.size();i++)
	{
		adj[stations[i][0]].push_back({stations[i][1], stations[i][2]});
		adj[stations[i][1]].push_back({stations[i][0], stations[i][2]});
	}
	int ans = INT_MAX;

	vector<int> vis(n,0);

	ans = dijkstraTraversal(adj, src, dest,n);

	
	//dfsTraversal(adj,src,dest,0,ans,vis);

	if (ans == INT_MAX)
        cout << "No path exists between the source and destination." << endl;
    else 
        cout << "Minimum pass value required: " << ans << endl;

}
