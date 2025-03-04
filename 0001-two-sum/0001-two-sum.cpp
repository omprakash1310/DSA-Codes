class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
    unordered_map<int, int> mpp;
    vector<int>ans;
    int n = arr.size();
    for(int i =0; i<n; i++){
        int first= arr[i];
        int sec = target - first;
        if(mpp.find(sec) != mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[sec]);
            break;
            
        }
        mpp[first] = i;
    }
    return ans;
    }
};