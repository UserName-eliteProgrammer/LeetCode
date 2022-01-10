#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x, y;
	node(int i, int j)
	{
		x = i;
		y = j;
	}
};

class Solution 
{
public:

	void bfs(int i, int j, vector<vector<bool>> &visited, int n, int m, vector<vector<char>> &grid)
	{
		visited[i][j] = true;
		queue<node> q;
		q.push(node(i, j));

		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};

		while(q.size())
		{   
			node location = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{	
				int newX = (location.x) + dx[i];
				int newY = (location.y) + dy[i];

				if(newX >= 0 and newX < n and newY >= 0 and newY < m and grid[newX][newY] == '1' and visited[newX][newY] == false)
				{	
					visited[newX][newY] = true;
					q.push(node(newX, newY));
				}	
			}
		}
		return;
	}

    int numIslands(vector<vector<char>>& grid) 
    {	
    	vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size()));
    	int connectedComponents = 0, n = grid.size(), m = grid[0].size();

  		for (int i = 0; i < grid.size(); i++)
  		{
  			for (int j = 0; j < grid[0].size(); j++)
  			{
  			    if(grid[i][j] == '1' and visited[i][j] == false)
  			    {	
  			    	bfs(i, j, visited, n, m, grid);
  			    	connectedComponents++;
  			    }      		
  			}          	
  		} 
  		return connectedComponents;         
    }
};

int main()
{

}