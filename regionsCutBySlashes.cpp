class DSU
{
	vector<int> parent;
	vector<int> size;

public:
	DSU(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			parent.push_back(i);
			size.push_back(1);
		}
	}

	int findParent(int n)
	{
		if(parent[n] == n)
		{
			return n;
		}

		return parent[n] = findParent(parent[n]);
	}

	void dsuUnion(int u, int v)
	{
		int p1 = findParent(u);
		int p2 = findParent(v);
		if(p1 == p2)
		{
			return;
		}

		if(size[p1] > size[p2])
		{
			parent[p2] = p1;
			size[p1] += size[p2];
		}
		else
		{
			parent[p2] = p1;
			size[p1] += size[p2];	
		}
		return;
	}
};

class Solution 
{
public:
    int regionsBySlashes(vector<string>& grid) 
    {	
    	int ans = 1, n = grid.size(), m = grid[0].size();
    	int numOfPoints = (n + 1) * (m + 1);
        DSU dsu(numOfPoints);

        for (int i = 0; i <= n; i++)
        {
        	for (int j = 0; j <= m; j++)
        	{
        		if(i == 0 or i == n or j == 0 or j == m)
        		{	
        			int point1 = 0, point2 = (i * m) + j;
        			if(dsu.findParent(point1) != dsu.findParent(point2))
        			{
        				dsu.dsuUnion(point1, point2);
        			}
        		}	
        	}
        }

        for (int i = 0; i < n; i++)
        {
        	for (int j = 0; j < m; j++)
        	{
        		int point1 = -1, point2 = -1;
        		if(grid[i][j] == '/')
        		{
        			point1 = (i * m) + (j + 1);
        			point2 = ((i + 1) * m) + j;
        		}
        		else if(grid[i][j] != ' ')
        		{
        			point1 = (i * m) + j;
        			point2 = ((i + 1) * m) + (j + 1);
        		}

        		if(grid[i][j] != ' ')
        		{
        			int p1 = dsu.findParent(point1);
        			int p2 = dsu.findParent(point2);
        			if(p1 == p2)
        			{
        				ans++;
        			}
        			else
        			{
        				dsu.dsuUnion(p1, p2);
        			}
        		}
        	}
        }
        return ans;
    }
};