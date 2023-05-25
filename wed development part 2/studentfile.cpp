#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    struct studentfile
    {
        char name[20];
        int rollno;
        float cgpa;
        string address;
        string division;

    };
    studentfile a;
    
    int ch;
    cout<<"enter the choice that you want to choose:";
    cin>>ch;
    switch (ch)
    {
        case 1:
        {   
            cout<<"enter the number of student that you want to insert:";
            int n;
            cin>>n;
            ofstream f1("student.txt");
            for(int i=1;i<=n;i++){
            cout<<"enter the name of the student:";
            cin>>a.name;
            cout<<"\n enter the roll no of the student:";
            cin>>a.rollno;
            cout<<"\n enter the addresss of the student:";
            cin>>a.address;
            cout<<"\n enter the division of the student :";
            cin>>a.division;
            f1<<a.rollno<<"  "<<a.address<<"   "<<a.name<<"   "<<a.division;

        }
        f1.close();
        break;
        }
        case 2:
        {
            cout<<"enter the number of student that you want to add:";
            int ent;
            cin>>ent;
            fstream f2;
            f2.open("student.txt",fstream::app);
            for(int i=1;i<=n;i++)
            {
            cout<<"enter the name of the student:";
            cin>>a.name;
            cout<<"\n enter the roll no of the student:";
            cin>>a.rollno;
            cout<<"\n enter the addresss of the student:";
            cin>>a.address;
            cout<<"\n enter the division of the student :";
            cin>>a.division;
            f2<<a.rollno<<"  "<<a.address<<"   "<<a.name<<"   "<<a.division;

        }
        f2.close();
        break;


        }
        case 3:
        {
        string ss;
        ifstream f3("student.txt");
        cout<<"student data";
        while(!f3.eof()){
            getline(f3,ss);
            cout<<ss<<endl;
        }
        f3.close();
        break;
        }
        case 4:
        {
            cout<<"enter the rollno of the student that you want to search:";
            int srollno;
            cin>>arollno;
            string ss;
            ifstream f3;
            int f=0;
            f3.open("student.txt",ios::in);
            cout<<"the student data is:";
            while(getline(f3,ss))
            {
                if(!ss.find(srollno)){
                    cout<<ss<<endl;
                    f++;
                }
            }
            if(f==0){
                cout<<"the value not found!!!";
            }
            f3.close();
            break;
        }
        case 5:
        {
            cout<<"enter the rollno that you want to update:"<<endl;
            int urollno;
            cin>>urollno;
            string ss;
            ifstream f4;
            ofstream temp;
            f4.open("student.txt");
            temp.open("temp.txt");
            while(getline(f4,ss)){
                if(ss.find(urollno)){
                    temp<<ss<<endl;
                }
                else{
                    a.rollno=stoi(urollno);//to get where the line is there
            cout<<"enter the name of the student:";
            cin>>a.name;
            cout<<"\n enter the roll no of the student:";
            cin>>a.rollno;
            cout<<"\n enter the addresss of the student:";
            cin>>a.address;
            cout<<"\n enter the division of the student :";
            cin>>a.division;
            temp<<a.rollno<<"  "<<a.address<<"   "<<a.name<<"   "<<a.division;


                }
            }
            f4.close();
            temp.close();
            remove("student.txt");
            rename("temp.txt","student.txt");
            break;


        }
        case 6:
        {
            string line;
            int rollno;
            cout<<"enter the rollno of the student that u want to delete";
            cin>>rollno;
            ifstream f3;
            ofstream temp;
            f3.open("student.txt");
            temp.open("temp.txt");
            while(getline(f3,line)){
                if(line.find(rollno)){
                    temp<<line<<endl
                }
                
            }
            cout<<"the record ha bening deleted!!!";
            f3.close();
            temp.close();
            remove("student.txt");
            rename("temp.txt","student.txt")
        }
    
    }
    
}