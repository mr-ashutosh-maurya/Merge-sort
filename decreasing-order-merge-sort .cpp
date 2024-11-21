#include<bits/stdc++.h>
using namespace std;
void sort(vector<int>&a,vector<int>&b,vector<int>&res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
       if(a[i]<b[j]) res[k++]=b[j++];
       else res[k++]=a[i++];
    }
    if(i==a.size()) while(j<b.size()) res[k++]=b[j++];
    if(j==b.size()) while(i<a.size()) res[k++]=a[i++];
}
void mergeSort(vector<int>&v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2;
    int n2=n-n/2;
    vector<int>v1(n1);
    vector<int>v2(n2);
    for(int i=0;i<n1;i++) v1[i]=v[i];
    for(int i=0;i<n2;i++) v2[i]=v[i+n1];
    mergeSort(v1);
    mergeSort(v2);
    sort(v1,v2,v);
}
int main(){
    int arr[]={5,21,8,3,9,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    for(int ele : v) cout<<ele<<" ";
    cout<<endl;
    mergeSort(v);
    for(int ele : v) cout<<ele<<" ";
}