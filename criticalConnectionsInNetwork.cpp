class Solution 
{
public:
    vector<vector<int>> ans;
    vector<int> time;
    vector<int> lowTime;

    void dfs(int node, vector<int> *adj, vector<bool> &visited, int parent, int timer)
    {
        visited[node] = true;
        time[node] = timer;
        lowTime[node] = timer;

        for (int i = 0; i < adj[node].size(); i++)
        {   
            int adjNode = adj[node][i];
            if(visited[adjNode] == false)
            {
                dfs(adjNode, adj, visited, node, timer + 1);
                lowTime[node] = min(lowTime[adjNode], lowTime[node]);

                if(lowTime[adjNode] > time[node])
                {   
                    vector<int> nodes(2);
                    nodes[0] = node;
                    nodes[1] = adjNode;
                    ans.push_back(nodes);
                }
            }
            else if(adjNode != parent)
            {
                lowTime[node] = min(lowTime[adjNode], lowTime[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {   
        time.resize(n);
        lowTime.resize(n);
        
        vector<int> *adj = new vector<int>[n];
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);
        dfs(0, adj, visited, -1, 0);

        return ans;
    }
};