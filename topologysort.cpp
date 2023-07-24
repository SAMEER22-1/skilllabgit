#include <bits/stdc++.h> 
#include<unordered_map>
#include<stack>
#include<list>
using namespace std;
void toposort(int node,vector<bool>&visited,stack<int>&s,unordered_map<int,list<int>>&adj)
{
   visited[node]=1;
   for(auto neighbour:adj[node])
   {
       if(!visited[neighbour])
       {
           toposort(neighbour, visited, s, adj);
       }
   }
       s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++)
    {
    int u=edges[i][0];
    int v=edges[i][1];

    adj[u].push_back(v);
    }
// call for the topologicalsort
vector<bool>visited(v);
stack<int>s;
for(int i=0;i<v;i++)
{
    if(!visited[i])
    {
        toposort(i,visited,s,adj);
    }
}
    vector<int>ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
return ans;
}
int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter the edges:\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological ordering: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
