class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {   
        int ans = INT32_MAX;
        vector<pair<int,int>> *adj = new vector<pair<int, int>>[n];
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][2], flights[i][1]});    
        }

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,greater<pair<pair<int, int>, int>>> q;

        q.push({{0, src}, 0}); // cost, node, k;
        while(q.size())
        {
            int node, stops, cost;
            cost = q.top().first.first;
            node = q.top().first.second;
            stops = q.top().second;
            q.pop();
            
            if(stops > k)
            {
                continue;
            }
            if(node == dst)
            {   
                // cout << node << " ";
                ans = min(ans, cost);
                break;
                // continue;
            }

            for (int i = 0; i < adj[node].size(); i++)
            {
                if(adj[node][i].second != dst and stops + 1 <= k)
                {   
                    int newNode = adj[node][i].second;
                    int newNodeCost = adj[node][i].first + cost;
                    q.push({{newNodeCost, newNode}, stops + 1});
                }
                else if(adj[node][i].second == dst)
                {
                    int newNode = adj[node][i].second;
                    int newNodeCost = adj[node][i].first + cost;
                    q.push({{newNodeCost, newNode}, stops});    
                }
            }
        }
        if(ans == INT32_MAX)
        {
            return -1;
        }
        return ans;
    }
};