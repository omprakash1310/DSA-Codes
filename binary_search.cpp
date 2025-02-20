#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    cout<<"Finding 3-> "<<binary_search(v.begin(), v.end(), 3)<<endl;

    //upper bound and lower bound

    cout<<"Lower bound -> "<<lower_bound(v.begin(), v.end(), 4)-v.begin()<<endl;
    cout<<"Upper bound -> "<<upper_bound(v.begin(), v.end(), 4)-v.begin()<<endl;
}