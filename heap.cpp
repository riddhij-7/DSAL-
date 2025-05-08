#include<iostream>
using namespace std;

void MinHeap(int arr[],int  i){
    int parent = (i-1)/2;
    int current =i;
    while(parent >= 0 && arr[parent] > arr[current]){
    	swap(arr[parent],arr[current]);
    	current = parent;
    	parent = (current-1)/2;
    	
	}
}
void MaxHeap(int arr[],int  i){
    int parent = (i-1)/2;
    int current =i;
    while(parent >= 0 && arr[parent] < arr[current]){
    	swap(arr[parent],arr[current]);
    	current = parent;
    	parent = (current-1)/2;
    	
	}
}
int main(){
    int n;
    cout<<"Enter No of Students: ";
    cin>>n;

    int arr[n] = {};
    cout<<"Enter DSA Marks of "<<n<<" students : "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    
    for(int i=1; i<6 ;i++){
        MinHeap(arr,i);

    }
    cout<<"------------------------------"<<endl;
    cout << "Minimum Score: "<<arr[0]<<endl;

    for(int i=1; i<6; i++){
    	MaxHeap(arr, i);
	}
    cout<<"------------------------------"<<endl;
    cout << "Max Score: "<<arr[0]<<endl;
    return 0;
}
