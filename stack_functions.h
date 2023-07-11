#include<iostream>
#include<iomanip>
using namespace std;

const int maximum = 5;

class Stack{
//	private: 
		
	public: 
		int top;
		int arr[maximum];
		
		Stack(): top(-1){}
		
		int push(int x)
		{
			if(top == maximum-1)
			{
				cout<<"Stack is full";
				cout<<"\nExiting...";
				exit(1);
			}
			else
				arr[++top] = x;
		}
		
		void pop()
		{
			if(top<0)
			{
				cout<<"Underflow... cannot delete items.";
				cout<<"\nExiting...";
				exit(1);
			}
			else
				cout<<arr[top--];
		}
		
		void show()
		{
			cout<<"\nStack is: "<<endl;
			for(int i=top; i>=0; i--)
				cout<<setw(3)<<arr[i]<<"("<<i<<")"<<endl;
		}
		
		bool isEmpty()
		{
			return (top == -1);
		}
		
		void peek()
		{
			if (isEmpty()) 
	            cout<<"Stack is empty";
			else 
	        	cout<<"The top is: "<<arr[top];
		}
};

void stack_functions()
{
	Stack obj;
	cout<<"Stack contains space for 5 elements...";
	obj.push(13);
	obj.push(57);
	obj.push(23);
	obj.show();
	
	char perform;
	do{		
		cout<<endl<<endl;
		cout<<"Enter any task to perform('e' to exit): \n";
		cout<<"1. push\n";
		cout<<"2. pop\n";
		cout<<"3. peek\n";
		cout<<"input: ";cin>>perform;
		cout<<endl<<endl;
		switch(perform){
			case '1':
				cout<<"Enter the element to push: ";
				int x; cin>>x;
				obj.push(x);
				cout<<endl;
				obj.show();
				break;
				
			case '2': 
				cout<<"\nPopping :";
				obj.pop();
				obj.show();
				break;
			
			case '3':
				obj.peek();
				break;
			
			case 'e':
				break;
				
			default:
				cout<<"(Invalid Option...)\nPlease select only from the above options.";
				break;
		}
	}while(perform != 'e');
}


//void stack_functions()
//{
//	cout<<"\n1)A"
//		  "\n2)B"
//		  "\n3)C"
//	      "\n4)D"
//	      "\n5)E"
//	      "\n6)F"
//	      "\n7)G\n\n";
//}
