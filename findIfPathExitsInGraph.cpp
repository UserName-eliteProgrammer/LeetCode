class Solution 
{
public:
    bool possible(int node, vector<int> *adj, vector<bool> &visited, int end)
    {   
        if(node == end)
        {
            return true;
        }
        visited[node] = true;

        for (int i = 0; i < adj[node].size(); i++)
        {   
            int adjNode = adj[node][i];
            if(visited[adjNode] == false)
            {
                bool temp = possible(adjNode, adj, visited, end);
                if(temp == true)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        vector<int> *adj = new vector<int>[n];
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); i++)
        {   
            int node1 = edges[i][0], node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        return possible(start, adj, visited, end);
    }
};