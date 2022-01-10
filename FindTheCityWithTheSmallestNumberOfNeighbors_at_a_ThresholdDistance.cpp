class Solution 
{
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int ansNode = -1, neighbours = INT32_MAX;
        vector<pair<int, int>> *adj = new vector<pair<int, int>>[n];

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        

        // Dijkstra
        for (int i = 0; i < n; i++)
        {   
            vector<int> dist(n, INT32_MAX);
            unordered_set<int> s;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.push({0, i});
            dist[i] = 0;

            while(q.empty() == false)
            {   
                int dis = q.top().first;
                int node = q.top().second;
                q.pop();

                for (int j = 0; j < adj[node].size(); j++)
                {   
                    int adjNode = adj[node][j].first;
                    int wt = adj[node][j].second;
                            

                    if(dis + wt <= distanceThreshold and dis + wt < dist[adjNode])
                    {   
                        q.push({dis + wt, adjNode});
                        dist[adjNode] = dis + wt;
                        s.insert(adjNode);
                    }
                }
            }
            
        
            if(s.size() < neighbours)
            {
                neighbours = s.size();
                ansNode = i;
            }
            else if(s.size() == neighbours)
            {   
                if(i > ansNode)
                {
                    ansNode = i;
                }
            }
        }
        return ansNode;
    }
};