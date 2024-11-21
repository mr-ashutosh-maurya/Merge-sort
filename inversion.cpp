#include<iostream>
#include<vector>
using namespace std;
int count=0;  //global variable declearation
int inversionCount(vector<int>&a,vector<int>&b){
    int c=0;
    int i=0,j=0;
    while(i<a.size() and j<b.size()){
        if(a[i]>b[j]){  //just like [3,4,5] compares with [1,2,4] by indexes
            c+=(a.size()-i);
            j++;
        }
        else i++;
    }
    return c;
}
void merge(vector<int>&a,vector<int>&b,vector<int>&res){ //merging newly created array
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]) res[k++]=a[i++];
        else res[k++]=b[j++];
    }
    if(i==a.size()) while(j<b.size()) res[k++]=b[j++];
    if(j==b.size()) while(i<a.size()) res[k++]=a[i++];
}
void mergeSort(vector<int>&v){
    int n=v.size();
    if(n==1) return;
    int n1=n/2,n2=n-n/2;
    vector<int>a1(n1),a2(n2);
    for(int i=0;i<n1;i++) a1[i]=v[i];
    for(int i=0;i<n2;i++) a2[i]=v[i+n1];
    mergeSort(a1);
    mergeSort(a2);
    count+=inversionCount(a1,a2); //calling inversion function adding returned value into count
    merge(a1,a2,v);
    a1.clear();  //removing extra created array to optimize space o(n)
    a2.clear();
}
int main(){
    int arr[]={8,4,12,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(arr,arr+n);
    cout<<endl;
    mergeSort(v); 
    cout<<count;
}