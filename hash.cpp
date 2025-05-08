#include<iostream>
#include<string>
using namespace std;
struct node{
	int telephone;
	string name;
	struct node* next; //for seperate chaining
};

struct node1{
	int telephone;
	string name; // for liner probing
};

class linear {
	
	node1*hashtable[10]; //initialize hashtable of size 10
public:
	linear() //constuctor
	{
		for(int i=0;i<10;i++){
			hashtable[i]=NULL;  //slots assigned with null value
		}
	}
	void insert(){
		int telephone;
		string name;
		cout<<"enter the telephone number : ";
		cin>>telephone;
		cout<<"enter the name : ";
		cin>>name;
		
		int loc=telephone%10;//index=key%10 or table size
	    struct node1*ptr=new node1;
		ptr->telephone=telephone;
		ptr->name=name;
		
		if(hashtable[loc]==NULL)
		{
			hashtable[loc]=ptr;
			cout<<"Inserted successfully !"<<endl;
		}
		else if(hashtable[loc]!=NULL)
		{
			while(hashtable[loc]!=NULL)
			{
				loc=(loc+1)%10;
			}
			hashtable[loc]=ptr;
			cout<<"inserted at the next null position ";
		}
		
	}
	void search()
	{
		int telephone;
		cout<<"enter the telephone number to be searched";
		cin>>telephone;
		
		int loc=telephone%10;
		int originalloc=loc;
		
		while(hashtable[loc]!=NULL)
		{
			if(hashtable[loc]->telephone==telephone)
			{
				cout<<"the telephone number is found at "<<loc<<"the name is : "<<hashtable[loc]->name;
				return;
			}
			loc=(loc+1)%10;
			if(loc==originalloc) break;
		}
	cout<<"no such element found ";
	}
	
	void display()
	{
		for(int i=0;i<10;i++)
		{
			if(hashtable[i]!=NULL)
			{
				cout<<"index"<<i<<"telephone :"<<hashtable[i]->telephone;
				cout<<"name: "<<hashtable[i]->name;
			}
			else{
				cout<<"index: "<<i<<"empty";
			}
	    }
    }
};
class colision
{
	node*hashtable[10];
public:
	colision()
	{
		for(int i=0;i<10;i++)
		{
			hashtable[i]=NULL;
		}
	}
	void insert()
	{
		int telephone;
		string name;
		cout<<"enter the telephone :";
		cin>>telephone;
		cout<<"enter the name ";
		cin>>name;
		
		int loc=telephone%10;
		node*ptr=new node;
		ptr->telephone=telephone;
		ptr->name=name;
		ptr->next=NULL;
		
		if(hashtable[loc]==NULL)
		{
			hashtable[loc]=ptr;
			cout<<"inserted !";
		}
		else{
			node*ptr2=hashtable[loc];
			while(ptr->next!=NULL)
			{
				ptr2=ptr2->next;
			}
			ptr->next=ptr;
			cout<<"inserted in ll ";
		}
	}
	void search(){
		int telephone;
		cout<<"enter the telephone number to be searched ";
		cin>>telephone;
		
		int loc=telephone%10;
		node*current=hashtable[loc];
		while(current!=NULL)
		{
			if(current->telephone==telephone)
			{
				cout<<"telephone number found at loaction "<<loc<<"name is : "<<current->name;
				return;
			}
			current=current->next;
		}
		cout<<"telephone number not found !";
	}
	void display()
	{
		for(int i=0;i<10;i++)
		{
			node*current=hashtable[i];
			if(current==NULL)
			{
				cout<<"empty";
			}
			else {
				while(current!=NULL)
				{
					cout<<"telephone: "<<hashtable[i]->telephone<<"name : "<<hashtable[i]->name;
					current=current->next;
				}
			}
			cout<<"\n";
		}
	}
};
int main()
{
	int choice;
	int method;
	linear l1;
	colision c1;
	cout<<"select the hashing methond"<<endl;
	cout<<"\n1.linear probing "<<endl;
	cout<<"\n2.seperate chaining"<<endl;
	cout<<"\nenter your choice :";
	cin>>method;
	
	do{
		cout<<"menu"<<endl;
		cout<<"\n1.insert \n2.search \n3.display \n4.exit "<<endl;
		cout<<"enter the choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				if(method==1)
				{
					l1.insert();
				}else if(method==2){
				c1.insert();
				}
				break;
			case 2:
				if(method==1)
				{
					l1.search();
				}else if(method==2)
				{
					c1.search();
				}
				break;
			case 3:
				if(method==1)
				{
					l1.display();
				}
				else if(method==2)
				{
					c1.display();
				}
				break;
			case 4:
				cout<<"exit";
				break;
			default:
				cout<<"enter a valid choice ";
		}
	}
	while(choice!=4);
	return 0;
}
