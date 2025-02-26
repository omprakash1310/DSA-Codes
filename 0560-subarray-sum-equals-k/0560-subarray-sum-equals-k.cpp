class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
    // Optimal Approach
    int n=arr.size();
    unordered_map<int, int> mpp;
    mpp[0]=1;
    int preSum =0, cnt=0;
    for(int i=0; i<n; i++){
        preSum +=arr[i];
        int remove = preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
   return cnt;
}
};