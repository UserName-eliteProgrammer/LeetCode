// class Solution 
// {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)     
//     {
//         int i = 0, j = 0;
//         vector<int> temp;
//         while(i < m and j < n)
//         {
//             if(nums1[i] < nums2[j])
//             {
//                 temp.push_back(nums1[i]);
//                 i++;
//             }
//             else
//             {
//                 temp.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while(i < m)
//         {
//             temp.push_back(nums1[i]);
//             i++;
//         }
//         while(j < n)
//         {
//             temp.push_back(nums2[j]);
//             j++;
//         } 

//         nums1 = temp;
//         return;  
//     }
// };


class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int index = n + m - 1, i = m - 1, j = n - 1;
        while(i >= 0 and j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[index] = nums1[i];
                i--;
            }
            else
            {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }

        while(i >= 0)
        {
            nums1[index] = nums1[i];
            i--;
            index--;
        }
        while(j >= 0)
        {
            nums1[index] = nums2[j];
            j--;
            index--;
        }
        return;
    }
};