
bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2];
}

class Union
{
public:
    vector<int> parent;
    vector<int> size;

    Union(int n)
    {   
        parent.reserve(n);
        size.reserve(n);
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findParent(int point)
    {   
        if(parent[point] == point)
        {
            return parent[point];
        }
        return parent[point] = findParent(parent[point]);
    }

    void unionThem(int point_1, int point_2)
    {
        int p1 = findParent(point_1), p2 = findParent(point_2);
        if(p1 == p2) return;

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
};

class Solution 
{
public:
    void calDis(vector<int>& point_1, vector<int>& point_2, vector<int>& info)
    {   
        int dis = abs(point_1[0] - point_2[0]) + abs(point_1[1] - point_2[1]);
        info.push_back(dis);
        return;
    }

    void makeConnection(vector<int>& info, int i, int j)
    {
        info.push_back(i);
        info.push_back(j);
        return;
    }

    int minCostConnectPoints(vector<vector<int>>& points) 
    {   
        int ans = 0;
        vector<vector<int>> edgeList;
        for(int i = 0; i < points.size() - 1; i++)
        {
            for(int j = i + 1; j < points.size(); j++)
            {   
                vector<int> info;
                makeConnection(info, i, j);
                calDis(points[i], points[j], info);
                edgeList.push_back(info);
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp); // greedy (kruskal's)

        Union u(points.size()); 
        for (int i = 0; i < edgeList.size(); i++)
        {   
            int point_1 = edgeList[i][0], point_2 = edgeList[i][1];
            if(u.findParent(point_1) != u.findParent(point_2))
            {
                u.unionThem(point_1, point_2);
                ans += edgeList[i][2];
            }
        }
        return ans;
    }
};