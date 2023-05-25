#include<iostream>
using namespace std;
void swap(arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int  partition(int arr[],int l,int r){
    int i=l-1;
    int pivot=arr[];
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    
    }
    swap(arr,i+1,r);
    return i+1;

}
void quicksort(int arr[],int l,int h){
    if(l<r){
        int pi=partion(arr[],l,r);
        quicksort(arr,pi+1,h);
        quicksort(arr,l,pi-1);
    }
}
int main(){
    
    int arr[5]={5,4,3,2,1};
    quicksort(arr,0,4);
    cout<<"the sorted array:";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}