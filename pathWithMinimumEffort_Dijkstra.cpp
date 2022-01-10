// i think and code this solution with help of my educator but without taking any hint or  without looking someone's code.

// i am very grateful that i am able to learn Programming with help of lot of people and my hard work.

// Thank You Bhagwaan !!

class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {   
        int n = heights.size();
        int m = heights[0].size();
        int numOfNodes = ((n - 1) * m) + (m - 1);
        vector<pair<int, int>> *adj = new vector<pair<int, int>>[n * m];
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int currNodeNum = (i * m) + j;
                for (int k = 0; k < 4; k++)
                {
                    int newX = i + dx[k], newY = j + dy[k];
                    if(newX >= 0 and newX < n and newY >= 0 and newY < m)
                    {
                        int neighbourNodeNum = (newX * m) + newY;
                        adj[currNodeNum].push_back({abs(heights[i][j] - heights[newX][newY]), neighbourNodeNum});
                    }
                }
            }
        }

        vector<int> jumps(n * m, INT32_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        jumps[0] = 0;
        q.push({jumps[0], 0});

        while(q.empty() == false)
        {
            int jumpTillNow = q.top().first;
            int currNodeNum = q.top().second;
            q.pop();

            for (int i = 0; i < adj[currNodeNum].size(); i++)
            {   
                int jumpBetweenTheseNodes = adj[currNodeNum][i].first;
                int adjNodeNum = adj[currNodeNum][i].second;

                if(max(jumpTillNow, jumpBetweenTheseNodes) < jumps[adjNodeNum])
                {   
                    jumps[adjNodeNum] = max(jumpTillNow, jumpBetweenTheseNodes);
                    q.push({jumps[adjNodeNum], adjNodeNum});
                }
            }
        }

        return jumps[numOfNodes];  
    }
};