class DSU
{
private:
    int *parent, *size;

public:
    DSU(int n)
    {
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int num)
    {
        if (parent[num] == num)
        {
            return num;
        }
        return findParent(parent[num]);
    }

    void unionDSU(int u, int v)
    {
        int p1 = findParent(u), p2 = findParent(v);
        if (p1 == p2)
        {
            return;
        }

        if (size[p1] > size[p2])
        {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else
        {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        return;
    }
};

class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)   
    {
        DSU dsu(edges.size());
        vector<int> ans(2);
        for (int i = 0; i < edges.size(); i++)
        {
            if(dsu.findParent(edges[i][0]) == dsu.findParent(edges[i][1]))
            {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
                break;
            }
            else
            {
                dsu.unionDSU(edges[i][0], edges[i][1]);
            }
        }   
        return ans;
    }
};