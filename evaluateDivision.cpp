class Solution 
{
public:

    float temp;
    bool flag = false;
    void dfs(string node, string target, map<string, vector<pair<string, float>>> &adj, float res, set<string> &visited)
    {   
        if(visited.find(node) != visited.end())
        {
            return;
        }
        if(node == target)
        {   
            temp = res;
            flag = true;
            return;
        }
        visited.insert(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            dfs(adj[node][i].first, target, adj, res * adj[node][i].second, visited);
        }
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        map<string, vector<pair<string, float>>> adj;
        set<string> visited;
        
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {   
            if(adj.find(queries[i][0]) == adj.end() and adj.find(queries[i][1]) == adj.end())
            {
                ans.push_back(-1);
                continue;
            }
            
            flag = false;
            dfs(queries[i][0], queries[i][1], adj, 1, visited);
            if(flag == true)
            {
                ans.push_back(temp);
            }
            else
            {   
                ans.push_back(-1);
            }
            
            visited.clear();
        }
        return ans;
    }
};