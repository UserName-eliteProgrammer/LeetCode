struct tup
{
public:
    int first, second, third;
    tup(int f, int s, int t)
    {
        first = f;
        second = s;
        third = t;
    }
};

class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid) 
    {   
        int n = grid.size(), ans = -1;
        queue<tup> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {   
                if(grid[i][j] == 1)
                {
                    q.push(tup(i, j, 0));
                    grid[i][j] = -1;
                }
            }
        }

        if(q.size() == 0 or q.size() == n * n) 
        {
            return -1;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(q.size())
        {
            tup node = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newX = node.first + dx[i];
                int newY = node.second + dy[i];
                if(newX >= 0 and newX < n and newY >= 0 and newY < n and grid[newX][newY] == 0)
                {
                    grid[newX][newY] = node.third + 1;
                    q.push(tup(newX, newY, grid[newX][newY]));
                    ans = max(ans, grid[newX][newY]);
                }
            }
        }
        return ans;
    }
};