class Solution 
{
public:
    bool help(vector<int>& arr, vector<bool> &visited, int index)
    {   
        if(index >= arr.size() or index < 0)
        {
            return false;
        }
        if(visited[index] == true)
        {
            return false;
        }
        if(arr[index] == 0)
        {
            return true;
        }

        visited[index] = true;
        if(help(arr, visited, index + arr[index]) or  help(arr, visited, index - arr[index]))
        {
            return true;
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) 
    {   
        vector<bool> visited(arr.size(), false);
        return help(arr, visited, start);
    }
};