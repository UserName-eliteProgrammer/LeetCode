class DSU
{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int num)
    {
        if (parent[num] == num)
        {
            return num;
        }
        return parent[num] = findParent(parent[num]);
    }

    void unionDSU(int u, int v)
    {
        int pu = findParent(u), pv = findParent(v);
        if (pu == pv)
        {
            return;
        }

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        return;
    }
};

class Solution 
{
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DSU dsu(n);
        int extra = 0, components = 0;
        for (int i = 0; i < connections.size(); i++)
        {  
            if(dsu.findParent(connections[i][0]) != dsu.findParent(connections[i][1]))
            {
                dsu.unionDSU(connections[i][0], connections[i][1]);
            }
            else
            {
                extra++;
            }
        }

        unordered_set<int> componentsParent;
        for (int i = 0; i < dsu.parent.size(); i++)
        {
            componentsParent.insert(dsu.findParent(dsu.parent[i]));
        }
        
             
        if(componentsParent.size() == 1)
        {
            return 0;
        }
        else if(componentsParent.size() - 1 <= extra)
        {
            return componentsParent.size() - 1;
        }
        return -1;
    }
};