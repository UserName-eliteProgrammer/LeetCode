
class Solution 
{
public:

    int minimumEffortPath(vector<vector<int>>& heights) 
    {   
        int ans = INT32_MAX;
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int, int>> *adj = new vector<pair<int, int>>[n * m];

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {   
                for (int k = 0; k < 4; k++)
                {   
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if(newX >= 0 and newX < n and newY >= 0 and newY < m)
                    {
                        adj[(i * m) + j].push_back({abs(heights[newX][newY] - heights[i][j]), (newX * m) + newY});
                    }   
                }
            }
        }

        // Dijkstra with Binary Search

        int low = 0;
        int high = 1000000;
        bool possible = false;
        while(low <= high)
        {
            int k = (low + high) / 2;
        

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            possible = false;
            vector<int> dis(n * m, INT32_MAX);
            vector<bool> visited(n * m);
            dis[0] = heights[0][0];
            q.push({dis[0], 0});

            while(q.size())
            {
                int edgeWt = q.top().first;
                int nodeNum = q.top().second;
                q.pop();
                
                
                if(nodeNum == ((n - 1) * m) + (m - 1))
                {
                    possible = true;
                    ans = min(ans, k);
                }
                
                if(possible == true)
                {
                    break;
                }

                for (int i = 0; i < adj[nodeNum].size(); i++)
                {
                    if(adj[nodeNum][i].first <= k and visited[adj[nodeNum][i].second] == false)
                    {
                        q.push({adj[nodeNum][i].first, adj[nodeNum][i].second});
                        visited[adj[nodeNum][i].second] = true;
                    }
                }  
            }

            if(possible)
            {
                high = ans - 1;
            }
            else if(possible == false)
            {
                low = k + 1;
            }
            possible = false;
        }
        return ans;
    }
};
