#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adjlist, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adjlist, component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    cout<<"Hello world"<<endl;
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter the edges:\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    cout << "Connected Components:\n";
    for (const auto &component : components)
    {
        for (const auto &node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
