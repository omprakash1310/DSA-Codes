#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq; //max heap
    priority_queue<int, vector<int>, greater<int>> pp; //min heap
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    int n=pq.size();
    for(int i=0; i<n; i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<endl;

    pp.push(10);
    pp.push(11);
    pp.push(12);
    pp.push(13);

    int m= pp.size();
    for(int i=0; i<m; i++){
        cout<<pp.top()<<" ";
        pp.pop();
    }
  

}