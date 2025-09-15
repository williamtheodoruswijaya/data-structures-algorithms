class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        * NAIVES SOLUTION, GONNA COMEBACK ON THIS ONE LATER
        */
        for (int num : nums2) {
            nums1.push_back(num);
        }
        
        sort(nums1.begin(), nums1.end());

        int length = nums1.size();
        double ans = 0;
        if (length % 2 == 0) {
            ans = (nums1[length/2 - 1] + nums1[length/2]) / 2.0;
        } else {
            ans = nums1[length/2];
        }

        return ans;
    }
};