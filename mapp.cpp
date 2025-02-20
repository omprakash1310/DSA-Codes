#include<bits/stdc++.h>

using namespace std;
int main(){

    map<string, int> m;

    pair<string, int> pair1 = make_pair("Microsoft", 1);
    m.insert(pair1);
    pair<string, int> pair2 =make_pair("Google", 2);
    m.insert(pair2);
    pair<string, int> pair3 =make_pair("SAP", 3);
    m.insert(pair3);
    cout<<m["SAP"];
    return 0;
}