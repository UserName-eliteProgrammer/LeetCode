class Solution 
{
public:
    bool ans = true;

    int change(int n)
    {
        if(n == 0)
        {
            return 1;
        }
        return 0;
    }

    void cycleDetection(int node, int parent, int alter, vector<int> &visited, vector<vector<int>> &graph)
    {   
        visited[node] = alter;
        for(auto adj : graph[node])
        {   
            if(ans == false)
            {
                return;
            }

            if(visited[adj] == -1)
            {
                cycleDetection(adj, node, change(alter), visited, graph);
            }
            else if(adj != parent)
            {
                if(visited[adj] == alter)
                {   
                    ans = false;
                    return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) 
    {   
        vector<int> visited(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++)
        {   
            if(visited[i] == -1)
            {   
                cycleDetection(i, -1, 0, visited, graph);
            }
        }
        return ans;
    }
};