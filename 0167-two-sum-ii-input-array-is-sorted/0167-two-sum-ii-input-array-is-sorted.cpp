class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n = num.size();
        vector<int> ans;
        int start =0, end = n-1;
        while(start < end){
            if(num[start] + num[end] == target){
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }else if(num[start] + num[end] < target) start++;
            else end--;
        }
        return ans;
    }
};