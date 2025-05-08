#include<iostream>
#include<strings.h>
using namespace std;

struct node{
	string label;
	int childcount;
	node* children[10];
};

class BookTree {
	node* root;
public:
	BookTree()
	{
		root=NULL;
	}
	
	void createbook()
	{
		root= new node();
		cout<<"enter the title of the book: ";
		cin.ignore();
		getline(cin,root->label);
		
		cout<<"enter the number of chapters ";
		cin>>root->childcount;
		
		for(int i=0;i<root->childcount;++i)
		{
			root->children[i]=new node();
			cout<<"enter the name of the chapter"<<i+1<<":"<<endl;
			cin.ignore();
			getline(cin,root->children[i]->label);
			
			cout<<"enter the number of sections "<<endl;
			cin>>root->children[i]->childcount;
			
			for (int j=0;j<root->children[i]->childcount;++j)
			{
				root->children[i]->children[j]=new node();
				cout<<"enter the name of the section "<<j+1<<":"<<endl;
				cin.ignore();
				getline(cin,root->children[i]->children[j]->label);
				
				cout<<"enter the number of subsections "<<endl;
				cin>>root->children[i]->children[j]->childcount;
				
				for(int k=0;k<root->children[i]->children[j]->childcount;++k)
				{
					root->children[i]->children[j]->children[k]=new node();
					cout<<"enter the name of the subsection "<<k+1<<":"<<endl;
					cin.ignore();
					getline(cin,root->children[i]->children[j]->children[k]->label);
				}
			}
		}
	}
	
	void displaybook()
	{
		if(!root)
		{
			cout<<"no book data found !";
			return;
		}
		
		cout<<"\n---BOOK HIERARCHY---";
		cout<<"\nBOOK: "<<root->label;
		
		for(int i=0;i<root->childcount;++i)
		{
			node* chapter=root->children[i];
			cout<<"\nCHAPTER"<<i+1<<":"<<chapter->label;
			int j;
			for(int j=0;j<chapter->childcount;++j);
			{
				node* section=chapter->children[j];
				cout<<"\nSECTION"<<j+1<<":"<<section->label;
				
				for(int k=0;k<section->childcount;++k)
				{
					node* subsection=section->children[k];
					cout<<"\nSUBSECTION"<<k+1<<":"<<subsection->label;
				}
			}
		}
	}
};
int main()
{
	BookTree bt;
	int choice;
	while(true)
	{
		cout<<"\nBOOK STRUCTURE PROGRAM ";
		cout<<"\n MENU";
		cout<<"\n1.Create ";
		cout<<"\n2.Display";
		cout<<"\n3.Exit";
		cout<<"\nplease enter your choice";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				bt.createbook();
				break;
			case 2:
				bt.displaybook();
				break;
			case 3:
				cout<<"thank you for using this program exiting !!";
				return 0;
			default:
				cout<<"enter valid choice";
	    }
    }
    return 0;
}
