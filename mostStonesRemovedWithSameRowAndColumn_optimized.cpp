class DSU
{
public:
    int *parent, *size;
    DSU(int n)
    {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
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
    bool isValid(int i, int j, vector<vector<int>> &stones)
    {
        if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1]))
        {
            return true;
        }
        return false;
    }

    int removeStones(vector<vector<int>>& stones) 
    {   
        int n = stones.size();
        DSU dsu(n);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {   
                int p1 = dsu.findParent(i);
                int p2 = dsu.findParent(j);
                if(isValid(i, j, stones) == true and p1 != p2)
                {
                    dsu.unionDSU(i, j);
                }     
            } 
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {   
            s.insert(dsu.findParent(dsu.parent[i]));          
        }
        return n - s.size();      
    }
};