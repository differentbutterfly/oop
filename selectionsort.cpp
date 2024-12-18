#include <iostream>
using namespace std;

template<typename T>

 void selection_sort(){
    int size;
    cout << "Enter the size of the array: \n";
    cin>>size;
    T *arr=new T[size];

    for(int i =0;i<size;i++){
        cout << "Enter element " << i << ": ";
        cin>>arr[i];

    }
    for(int i =0;i<size;i++){
        int min_element=i;
            for(int j=i+1;j<size;j++){
                if( arr[j]<arr[min_element] ){
                    min_element=j;
                }
            }
        if(min_element!=i){
            int temp=arr[i];
            arr[i]=arr[min_element];
            arr[min_element]=temp;
        }
    }

    cout<<"SORTED ARRAY: \n";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\n";
    }

} 
int main() {

    int choice;
    do{
    cout << "1. Integer nums \n2. Float nums \n3. exit\n";
    cin>>choice;
    switch(choice)
    {
    
    case 1:
    cout<<"for integer array: \n";
    selection_sort<int>();
    cout<<"\n";
    break;

    case 2:
    cout<<"for float array: \n";
    selection_sort<float>();
    cout<<"\n";
    break;

    case 3:
    cout<<"Exiting the program.\n";
    return 0;

    default:
    cout<<"Invalid choice. Please choose a valid option.\n";
    }

    
    }while(choice!=3);


   return 0;
}