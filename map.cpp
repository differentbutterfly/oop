#include <iostream>
#include<iterator>
#include<map>
using namespace std;
 
int main() {
    string statename;
    int pop,n;
    map<string,int> state;
    cout<<"Enter the no.of states : "<<endl;
    cin>>n;

    for(int i = 0;i<n;i++){
        cout<<"Enter the name of the state: \n";
        cin>>statename;
        cout<<"Enter the population of the state: \n";
        cin>>pop;
        state.insert(pair<string,int>(statename,pop));

    }

    map<string,int>::iterator it;
    cout<<"\n";
    for(it=state.begin();it!=state.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }


    cout<<"to find state population\n";
    cout<<"Enter the state name  ";
    cin>>statename;
    it=state.find(statename);
    if(it==state.end()){
        cout<<"STATE DOES NOT EXIST\n";
    }
    else{
        cout<<"STATE POPULATION IS "<<it->second<<endl;
    }
 
   return 0;
}