class Solution {
public:
    int majorityElement(vector<int>& v) {
    // Optimal Approach
    int freq =0, ans =0;
    for(int i=0; i<v.size(); i++){
        if(freq== 0){
            ans = v[i];
        }
        if(ans == v[i]){
            freq++;
        }else{
            freq--;
        }
    }
    return ans;
    }
};