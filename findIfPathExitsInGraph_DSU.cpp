class Solution 
{
public:

    int findParent(int node, vector<int> &parent)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }

    void unionDSU(int u, int v, vector<int> &parent, vector<int> &size)
    {   
        int p1 = findParent(u, parent), p2 = findParent(v, parent);
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
            parent[p1] = p2;
            size[p2] += size[p1];    
        }
        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        vector<int> parent(n);
        vector<int> size(n);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        for(auto val : edges)
        {
            unionDSU(val[0], val[1], parent, size);
        }

        if(findParent(start, parent) == findParent(end, parent))
        {
            return true;
        }          
        return false;
    }
};