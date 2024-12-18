#include <iostream>
#include<fstream>
#include <string>
using namespace std;
 
 class student{
int roll;
string name;
float marks;
   public:
   void getdata(){

      ofstream out;
      out.open("student.txt",ios::app);
      if(out){
         cout<<"Enter name " ;
         cin.ignore();
         getline(cin,name);

         cout<<"Enter Roll.no: ";
         cin>>roll;

         cout<<"Enter marks: ";
         cin>>marks;
         out <<name<<"\t"<<roll<<"\t"<<marks<<"\t \n";
      }
      else{
         cout<<"file not found";
      }
      out.close();

   }

   void display(){

      ifstream in;
      string line;
      if(in){
         in.open("student.txt",ios::in);
         while(!in.eof()){
            getline(in,line);
            cout<<line<<"\n";
         }
      }
      else{
         cout<<"file not found";
      }
      in.close();
   }

 };
int main() {
 student s1;

 s1.getdata();
 s1.display();
   return 0;
}