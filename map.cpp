#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, string> m;

    m[1] = "Om";
    m[2]="Hello";
    m[4]="Gyas...";

    for(auto i:m){
        cout<<i.first<<endl;
    }
    cout<<endl;
    m.insert({5,"Bheem"});
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

   // cout<<"Finding 4 ->"<<m.count(4)<<endl;
}