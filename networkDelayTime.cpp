class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int, int>> *adj = new vector<pair<int, int>>[n + 1]; 
        
        for(int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
            // weight, adjacentNode
        }
        
        vector<int> timeTaken(n + 1, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        q.push({0 ,k});
        timeTaken[k] = 0;
        
        while(q.size())
        {
            int timeTillThisNode = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(int i = 0; i < adj[node].size(); i++)
            {
                if(timeTillThisNode + adj[node][i].first < timeTaken[adj[node][i].second])
                {
                    timeTaken[adj[node][i].second] = timeTillThisNode + adj[node][i].first;
                    q.push({timeTaken[adj[node][i].second], adj[node][i].second});
                    
                    // cout <<  timeTaken[adj[node][i].second] << " ";
                    // cout << adj[node][i].second << " ";
                }
            }
        }
        
        // for(int i = 0; i < adj[2].size(); i++)
        // {
        //     cout << adj[2][i].second << " ";
        // }
        
        int ans = -1;
        for(int i = 1; i <= n; i++)
        {   
            if(timeTaken[i] == INT32_MAX)
            {
                return -1;
            }
            // cout << timeTaken[i] << " ";
            ans = max(ans, timeTaken[i]);
        }
        return ans;
    }
};