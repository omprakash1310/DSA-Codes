#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot= arr[low];
    int i=low;
    int j= high;
    while(i<j){
        while(arr[i] <= pivot && i<= high -1){
            i++;
        }
        while(arr[j] > pivot && j >= low +1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qS(vector<int> &arr, int low, int high){
    if(low<high){
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex -1);
        qS(arr, pIndex +1, high);
    }
}

vector<int> quickSort(vector<int> arr){
    qS(arr, 0, arr.size()-1);
    return arr;
}

int main(){
    vector<int> arr ={4,5,3,2,1,5,6,7,1,0};
    int n = arr.size();
    cout<<"before Sorting: "<<endl;
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    arr= quickSort(arr);
    cout<<"After Sorting: "<<"\n";
    for(int i =0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

    return 0;
}