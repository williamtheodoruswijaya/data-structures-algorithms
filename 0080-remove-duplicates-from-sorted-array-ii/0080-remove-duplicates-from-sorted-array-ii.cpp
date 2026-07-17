class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> maps;
        int index = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            maps[nums[i]]++;
            if(maps[nums[i]] <= 2)
            {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};