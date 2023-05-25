#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class edge{
    public:
    int source;
    int dest;
    int weight;
    
};
bool compare (edge e1,edge e2)//we have create a comapre function for comparing two edges e1 and e2 here we can say that for increasing order e1 must be smaller than e2
{
    return e1.weight<e2.weight;
}
int findparent(int v,int *parent)// in this function we will cheak wheather the parent of th vertex is equal to the vertex its self if not the we will cheak for the parent of the element
{
    if(parent[v]==v){
        return v;
    }
    return findparent(parent[v],parent);
}
void kruskal(edge *input,int n,int e){
    // the first step we have to is we have to compare the the egde we will use a inbuild sort function 
    sort(input,input+e,compare);//is this case we have used a inbuld sort function in this case we can pass input which will indicate the first element of the array input +e will indicate the last element of the array as the size of the array will be e and we will not allow the sort function to sort according to its choice we will make a comapare
    edge *output=new edge[n-1];//creation of a output array 
    int*parent=new int[n];//parent array
    //nitial all the element will be its own parent 
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    int count =0;
    int i=0;
    while(count!=n-1){
        edge currentedge=input[i];
        //cheak wheather we can add it to the mst
        int sourceparent=findparent(currentedge.source,parent);
        int destparent=findparent(currentedge.dest,parent);
        if(sourceparent!=destparent){
            output[count]=currentedge;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
        
    }
    for(int i=0;i<n-1;i++)//we have used this for printing the output 
    {
        if(output[i].source<output[i].dest){
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
            
        }
        else{
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
            
        }
    }
    
};
int main(){
  int n,e;
  cin>>n>>e;
  edge *input=new edge[e];//creation of a new input array
  //we have create the arry as a object of the class edge as we have to use the properties of the edge class in the input array;
  for(int i;i<e;i++){
      int s,d,w;
      cin>>s>>d>>w;
      input[i].source=s;
      input[i].dest=d;
      input[i].weight=w;
      kruskal(input,n,e);
      
      
  }
}