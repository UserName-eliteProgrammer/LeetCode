class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {   
        int numOfRooms = rooms.size();
        vector<bool> visited(numOfRooms, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(q.empty() == false)
        {
            int roomNum = q.front();
            q.pop();

            for(auto key : rooms[roomNum])
            {   
                if(visited[key] == false)
                {
                    q.push(key);
                    visited[key] = true;
                }
            }
        }

        for(int i = 0; i < numOfRooms; i++)
        {
            if(visited[i] == false)
            {
                return false;
            }
        }
        return true;
    }
};