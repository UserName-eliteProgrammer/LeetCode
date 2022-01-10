class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {   
        int ans = 0;
        vector<int> *adj = new vector<int>[n];
        for (int i = 0; i < manager.size(); i++)
        {   
            int parentNode = manager[i];
            if(parentNode == -1)
            {
                continue;
            }
            adj[parentNode].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});
        while(q.size())
        {
            int node = q.front().first;
            int time = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node])
            {
                int totalTime = time + informTime[node];
                ans = max(ans, totalTime);
                q.push({adjacentNode, totalTime});
            }
        }
        return ans;
    }
};