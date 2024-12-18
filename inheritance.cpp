#include <iostream>
#include<string>
using namespace std;
 
class publication{
    public:
    string title;
    int price;

    void getdata(){
        cout<<"Enter the title ";
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the price ";
        cin>>price;
    }

    void display(){
    
    cout<<"title is "<<title<<endl;
    cout<<"Price is "<<price<<endl;
    }
};

class book : public publication{
    int page_count;
    public:

    void getdata(){
        try{
        publication::getdata();
        cout<<"Enter pages of the book  ";
        cin>>page_count;
        if( page_count<0)
        throw page_count;
        }catch(...){
            cout<<"error in book !!!!!!  ";
        }
    }

    void display(){
        publication::display();
        cout<<"page count is "<<page_count<<endl;
    }



};


class tape : public publication{
    float run_time;
    public:

    void getdata(){
        try{publication::getdata();
        cout<<"Enter run time for tapes  ";
        cin>>run_time;
        if(run_time<0)
        throw run_time;
        }catch(...){
            cout<<"error in tape!!!!!! ";
        }
    }

    void display(){
        publication::display();
        cout<<"page count is "<<run_time<<endl;
    }



};


int main() {

    int choice;
    tape tape_obj;
    book book_obj;

    do{

        cout<<"1.TAPE INFORMATION "<<endl;
        cout<<"2.BOOK INFORMATION "<<endl;
        cout<<"3.EXIT "<<endl;
        
        cin>>choice;
        switch(choice)
        {
            case 1:
        cout<<"IN TAPE\n";   
        tape_obj.getdata();
        tape_obj.display();
        break;

        case 2:
        cout<<"IN BOOK\n";
        book_obj.getdata();
        book_obj.display();
        break;

        case 3:
        cout<<"EXITING "<<endl;
        break;

        default:
        cout<<"invalid choice "<<endl;
        }
   }while(choice!=3);

    
 
   return 0;
}