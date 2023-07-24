#include <bits/stdc++.h> 
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
using namespace std;
void prepareadjlist(unordered_map<int,set<int>>&adjlist,vector<pair<int,int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>>&adjlist,unordered_map<int,bool>&visited,vector<int>&ans,int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int frontnode=q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto i:adjlist[frontnode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    // first prepare adj list
    unordered_map<int,set<int>>adjlist;
    vector<int>ans;
    unordered_map<int,bool>visited;

    prepareadjlist(adjlist,edges);
    // traverse all the components of the graph
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
        {
            bfs(adjlist,visited,ans,i);
        }
    }
    return ans;
}
int main() {
    int vertex, edgesCount;
    cout << "Enter the number of vertices: ";
    cin >> vertex;
    cout << "Enter the number of edges: ";
    cin >> edgesCount;
  
    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edgesCount; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
  
    vector<int> result = BFS(vertex, edges);
  
    cout << "BFS traversal order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
