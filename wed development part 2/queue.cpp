#include<iostream>
using namespace std;
class circularqueue{
    //declaration of the variables
    public :
    int rear,front;
    string arr[5];
    circularqueue()
    {
        rear=-1;
        front=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]="0";
        }
    }
    bool sizefull(){
        if(rear+1==front||rear==4 &&front==0){
            return 1;
        }
        return 0;

    }
    bool empty(){
        if(rear==-1&&front==-1){
            return 1;
        }
        return 0;
    }
    void add(){
        if(sizefull()){
            cout<<"\n the queue is full!!!";
        }
        else{
            cout<<"enter the name of the the students that u want to add in the queue:";
            string name;
            cin>>name;
            rear=(rear+1)%5;
            arr[rear]=name ;
            if(front==-1){
                front=0;
            }
        }
    }
    void deletion(){
        if(empty()){
            cout<<"\n the queue is empty!!!!";
        }
        else{
            arr[front]="0";
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{

            
            front=(front+1)%5;
            }
        }
    }
    void display(){
        for(int i=0;i<5;i++){
            cout<<arr[i]<<" ";
        }
    }




};
int main(){
    circularqueue q;
    int ch;
    int s;
    do{
    cout<<"enter number of names you want to add:";
    cin>>ch;
    
    switch(ch){
        case 1:
        q.add();
        break;
        case 2:
        q.deletion();
        break;
        case 3:
        q.display();
        break;
        

    }
    cout<<"\n do you want to continue:";
        cin>>s;
    }while(s==1);
}