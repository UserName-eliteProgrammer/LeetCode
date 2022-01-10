#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int x, y, time;
    node(int x, int y, int time)
    {
        this->x = x;
        this->y = y;
        this->time = time;
    }
};

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(), orangeCount = 0, ans = 0;
        queue<node> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(node(i, j, 0));
                }
                if(grid[i][j] != 0)
                {
                    orangeCount++;
                }
            }
        }

        int rottenOranges = 0;
        while(q.size())
        {
            node org = q.front();
            q.pop();
            rottenOranges++;

            ans = max(ans, org.time);

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            int newX, newY;
            for (int i = 0; i < 4; i++)
            {
                newX = (org.x) + dx[i];
                newY = (org.y) + dy[i];
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and grid[newX][newY] == 1)
                {
                    q.push(node(newX, newY, (org.time) + 1));
                    grid[newX][newY] = 2;
                }
            }
        }
        if(orangeCount != rottenOranges)
        {
            ans = -1;
        }
        return ans;
    }
};

int main()
{

}