class Solution 
{
public:
    vector<int> visited;
    bool oddCycleDetection(int node, vector<int> *adj, int parent, int code)
    {   
        visited[node] = code;
        for (int i = 0; i < adj[node].size(); i++)
        {   
            int adjNode = adj[node][i];
            if(visited[adjNode] == -1)
            {   
                if(oddCycleDetection(adjNode, adj, node, !code) == false)
                {
                    return false;
                }
            }
            else if(visited[adjNode] != -1 and adjNode != parent and visited[adjNode] == code)
            {  
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)       
    {
        vector<int> *adj = new vector<int>[n + 1];
        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        visited.resize(n + 1);

        for(int i = 0; i <= n; i++)
        {   
            visited[i] = -1;
        }

        bool ans = true;  
        for (int i = 1; i <= n; i++)
        {
            if(visited[i] == -1)
            {
                ans = oddCycleDetection(i, adj, 0, 1);
            }
            if(ans == false)
            {
                return ans;
            }
        }
        return ans;
    }
};