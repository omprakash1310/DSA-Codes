#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;

    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(1);

    for(auto i:s){
        cout<<i<<endl; 
    }cout<<endl;

    set<int> :: iterator it = s.begin();
    it++;
    s.erase(it);

    for(auto i:s){
        cout<<i<<endl;
    }

    cout<<"5 is present or not:-> "<<s.count(5)<<endl;
    return 0;
}