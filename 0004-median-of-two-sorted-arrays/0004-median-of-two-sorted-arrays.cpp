class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2= nums2.size();
        int i =0, j=0;
        int n = n1+n2;
        vector<float> nums3;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i <n1) nums3.push_back(nums1[i++]);
        while(j < n2) nums3.push_back(nums2[j++]);

        if(n%2 == 1) return nums3[n/2];
        else return (nums3[n/2] + nums3[n/2-1])/2; 
    }
};