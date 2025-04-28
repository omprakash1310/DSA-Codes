class Solution {
public:

    bool canItAll(vector<int> &piles, int mid, int h){
        int actualH=0;
        for(int &x:piles){
            actualH += x/mid;

            if(x % mid !=0 ) actualH++;
        }
        

        return actualH <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= *max_element(begin(piles), end(piles));

        while(low<high){
            int mid = low+ (high-low) /2;
            if(canItAll(piles, mid, h)){
                high= mid;
            }else low = mid+1;
        }
        return low;
        
    }
};