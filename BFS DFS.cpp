#include<iostream>
using namespace std;

int cost[10][10];
int qu[10],front=0,rear=0;
int visited[10]={0};
int stk[10],top=0;
int visited1[10]={0},visit1[10]={0};

int main()
{
	int n,m,i,j,k,v;
	cout<<"enter the number of vertices :";
	cin>>n;
	cout<<"enter the number of edges : ";
	cin>>m;
	
	cout<<"\nEDGES cost: ";
	for(k=0;k<m;k++)
	{
		cin>>i>>j;
		cost[i][j]=1;
		cost[j][i]=1;
	}
	
	cout<<"\nthe adjacency matrix is : ";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<" "<<cost[i][j];
		}
		cout<<endl;
	}
	
	cout<<"\nenter the initial vertex : ";
	cin>>v;
	cout<<"\nthe bfs is : ";
	cout<<v<<" ";
	visited[v]=1;
	qu[rear++]=v;
	while(front<rear)
	{
		v=qu[front++];
		for(j=0;j<n;j++)
		{
			if(cost[v][j]=1 && visited[j]==0)
			{
				qu[rear++]=j;
				visited[j]=1;
				cout<<j<<" ";
			}
		}
	}
	
    cout << "\nEnter initial vertex: ";
    cin >> v;

    cout << "The DFS of the Graph is:\n";
    cout << v << " ";

    visited1[v] = 1;
    k = 1;

    while (k < n) {
        for (j=0; j<n; j++) {
            if (cost[v][j] == 1 && visited1[j] == 0 && visit1[j] == 0) {
                visit1[j] = 1;
                stk[top++] = j;
            }
        }

        if (top == 0) break; // No more nodes to visit

        v = stk[--top];      // Pop from stack
        cout << v << " ";
        k++;

        visit1[v] = 0;       // Remove temporary mark
        visited1[v] = 1;     // Permanently visited
    }

    return 0;
}
