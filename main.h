#include<iostream>
#include<stdlib.h>	//for clearing the screen
using namespace std;

#include "sorting.h"
#include "linkedlist.h"
#include "trees.h"
#include "binaryTree.h"
#include "basics.h"
#include "stack.h"


void main_functions()
{
	char repeat='n';	
	do
	{
		if(repeat == 'y')
			system("cls");
		
		cout<<"\t\t\t\t"
		"This is a C++ Program for various Data Structures\n\n"
		"1)Sorting Algorithms\n"
		"2)Linked Lists\n"
		"3)Trees\n"
		"4)Binary Trees\n"
		"5)Basics\n"
		"6)Stack\n"
		"7)Patterns\n";
		
		int answer;
		cout<<"\nEnter your choice: ";cin>>answer;
		
		switch(answer)
		{
			case 1:
				cout<<"\nYou have selected Sorting algorithms.";
				sorting_main();
				break;
			
			case 2:
				cout<<"\nYou have selected Linked lists.";
				linkedlist_main();
				break;
				
			case 3:
				cout<<"\nYou have selected trees.";
				trees_main();
				break;
				
			case 4:
				cout<<"\nYou have selected binary trees.";
				binaryTrees_main();
				break;
				
			case 5:
				basics_main();
				break;
				
			case 6:
				stack_main();
				break;
						
			default:
				cout<<"\nInvalid input\nPlease enter an input from 1-5";
				break;
		}
		
		cout<<"\n\nWould you like to repeat? (y/n): ";
		cin>>repeat;
			
	}while(repeat == 'y');
	
}

