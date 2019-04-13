#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// define default capacity of the stack
#define SIZE 10

// Class for stack





void delay()
{
	for(int i=0;i<500;i++)
	{

	}
}

vector<int> frame_sequence;



class stack
{
	int *arr;
	int top;
	int capacity;

public:
	stack(int size = SIZE);		// constructor

	void push(int);
	int pop(int,int,int);
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
	int search(int ,int);
};

// Constructor to initialize stack
stack::stack(int size)
{
	arr = new int[size];
	capacity = size;
	top = -1;
}

// Utility function to add an element x in the stack
void stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}


	arr[++top] = x;
}

// Utility function to pop top element from the stack
int stack::pop(int n ,int x,int y)
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	
	for(int i=y+1;i<n;i++){
	    arr[i-1]=arr[i];
	}
	arr[n-1]=x;

}

// Utility function to return top element in a stack
int stack::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int stack::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
	return top == -1;	// or return size() == 0;
}

// Utility function to check if the stack is full or not
bool stack::isFull()
{
	return top == capacity - 1;	// or return size() == capacity;
}

int stack::search(int x ,int y){
    int l=-1;
    for(int i=0;i<y;i++){
        if(arr[i]==x)
        l=i;
    }
    return l;
}

void run(int n)
{
	clock_t start=clock();
  
  	
    stack s(n); 
    
    long long fault=0;
    for(int i=0;i<frame_sequence.size();i++){
        int x= frame_sequence[i];
        int index=s.search(x,s.size());
     
        if(index==-1){
       //   delay();
          fault++;

          if(s.size()==n){
             s.pop(n,x,0);  
          }else{
             s.push(x);
          }
        }else{
             s.pop(s.size(),x,index);  
        }
        
    }
    start=clock()-start; 
    cout<<((double)start/CLOCKS_PER_SEC)<<endl;
   
   
   
  /*cout<<fault<<endl;*/



}





// main function
int main()
{
  
   freopen("input.txt", "r", stdin);
   freopen("real_output.txt","w",stdout);
   //int input_size;cin>>input_size;
   
   int val=10;
   
   for(int i=0;i<1e6;i++)
   {
   	  int x;
   	  cin>>x;
   	  frame_sequence.push_back(x);
   	  if(val==i+1)
   	  {
   	    run(50);
   	    val=val*10;	
   	  }
   	   

   }
		
  

  
  
  
    

	return 0;
}
