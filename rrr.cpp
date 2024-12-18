#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
class item
{
 public: 
	string name;
	int code;
	int cost;
	int quantity;
	
	bool operator < (const item& i1)
	{
	return code<i1.code;
	}
	bool operator == (const item& i1)
	{
	return code==i1.code;
	}
	
};

vector<item>v1;
void insert()
{
	item i1;
	cout<<"Enter Code: "<<endl;
	cin>>i1.code;
	cout<<"Enter Name: "<<endl;
    cin.ignore();
	getline(cin,i1.name);
	cout<<"Enter Quantity: "<<endl;
	cin>>i1.quantity;
	cout<<"Enter Cost: "<<endl;
	cin>>i1.cost;
	v1.push_back(i1);
}
void display()
{
	cout<<"\n\tItemcode\tName\tCost\tQuantity"<<endl;
	vector<item>::iterator itr;
	for(itr=v1.begin();itr!=v1.end();itr++)
	{
	cout<<"\t"<<itr->code<<"\t\t"<<itr->name<<"\t"<<itr->cost<<"\t"<<itr->quantity<<endl;
	}
}
void search()
{
	vector<item>::iterator p;
	item i1;
	cout<<"Enter item code to search:";
	cin>>i1.code;
	cout<<endl;
	p=find(v1.begin(),v1.end(),i1);
	if(p==v1.end())
	{
	cout<<"item not found"<<endl;
	}
	else
	{
	cout<<"item found"<<endl;
	}
}
int main()
{
	int ch;
	do
	{
	cout<<"1.Insert Item\n2.display item\n3.search item\n4.Sort item\n5.Exit"<<endl;
	cout<<"Enter your Choice: ";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:
		insert();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		
		break;
	case 4:
		sort(v1.begin(),v1.end());
		cout<<"Sorted element is: "<<endl;
		display();
		break;
	case 5:
		exit(0);		
	}
}
	while(ch!=6);

	return 0;
}