// Iterative

// class Solution 
// {
// public:
//     int search(vector<int>& nums, int target) 
//     {
//         int low = 0, high = nums.size() - 1;
//         while(low <= high)
//         {
//             int mid = high - ((high - low) / 2);
//             if(nums[mid] < target)
//             {
//                 low = mid + 1;
//             }
//             else if(nums[mid] > target)
//             {
//                 high = mid - 1;
//             }
//             else
//             {
//                 return mid;
//             }
//         }
//         return -1;      
//     }
// };


class Solution 
{
public:
    int help(int low, int high, int target, vector<int> &nums)
    {   
        if(low > high)
        {
            return -1;
        }

        int mid = high - ((high - low) / 2);
        
        if(nums[mid] < target)
        {
            low = mid + 1;
        }
        else if(nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }

        return help(low, high, target, nums);
    }

    int search(vector<int>& nums, int target) 
    {
        return help(0, nums.size() - 1, target, nums);     
    }
};