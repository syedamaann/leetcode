class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {};
        result.push_back(-1);
        result.push_back(-1);
        
        int n = nums.size();
        if(n == 0)
        {
            return result;
        }
        
        int left = 0;
        int right = n - 1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target)
            {
                int temp1 = mid;
                int temp2 = mid;
                while(temp1 - 1 >= 0)
                {
                    if(nums[temp1] == nums[temp1 - 1])
                    {
                       temp1 -= 1; 
                    }
                    else
                    {
                        break;
                    }
                }
                while(temp2 + 1 < n)
                {
                    if(nums[temp2] == nums[temp2 + 1])
                    {
                       temp2 += 1; 
                    }
                    else
                    {
                        break;
                    }
                }
                
                result[0] = temp1;
                result[1] = temp2;
                return result;
            }
            else
            {
                if(nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        
        return result;
    }
};