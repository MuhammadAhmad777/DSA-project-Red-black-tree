#include"RBT.h"
#include<fstream>

void displayOptions();
void proj();
int main()
{
	RBT<int>ob;
	proj();
	return 0;
}
void displayOptions()
{
	cout << "\n\t\t~:~: MENU :~:~\n";
	cout << ":::: Press 1 to insert values in the tree(one by one)\n";
	cout << ":::: Press 2 for searching a value from the tree\n";
	cout << ":::: Press 3 for pre - order traversal NLR\n";
	cout << ":::: Press 4 for in - order traversal LNR\n";
	cout << ":::: Press 5 for post - order traversal LRN\n";
	cout << ":::: Press 6 for pre - order traversal 2 NRL\n";
	cout << ":::: Press 7 for in - order traversal 2 RNL\n";
	cout << ":::: Press 8 for post - order traversal 2 RLN\n";
	cout << ":::: Press 9 for displaying parent of a node present in Tree\n";
	cout << ":::: Press 10 to read integer values from the file \"input.txt\" to create a red - black tree\n";
	cout << ":::: Press 11 to delete all duplicate values from the tree\n";
	cout << ":::: Press 12 to destroy the complete tree\n";
	cout << ":::: Press 13 to EXIT\n";
}
void proj()
{
	cout << "\t\t\t\t!<: RED BLACK TREE :>!\n";
	int userOpt = 0;
	RBT<int>myob;
	int inp = 0;
	while (1)
	{
		displayOptions();
		cout << "__________________________________________________________________\n";
		cout << "Your choice: ";
		cin >> userOpt;
		if (userOpt == 1)
		{
			cout << "Enter a value to insert : ";
			cin >> inp;
			myob.insertValue(inp);
			cout << "Required Task performed\n";
		}
		else if (userOpt == 2)
		{
			cout << "Enter a value to search : ";
			cin >> inp;
			if (myob.search(inp) == true)
			{
				cout << "::> True,This value is present in Tree\n";
			}
			else
			{
				cout << "::> False,This value is not present in Tree\n";
			}
			cout << "Required Task performed\n";
		}
		else if (userOpt == 3)
		{
			myob.preorder();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 4)
		{
			myob.inorder();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 5)
		{
			myob.postorder();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 6)
		{
			myob.preorder2();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 7)
		{
			myob.inorder2();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 8)
		{
			myob.postorder2();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 9)
		{
			cout << "Enter a value of (child) Node of which you want see parent node : ";
			cin >> inp;
			myob.displayingParent(inp);
			cout << "Required Task performed\n";
		}
		else if (userOpt == 10)
		{
			ifstream fin;
			fin.open("input.txt");
			if (fin)
			{
				while (fin >> inp)
				{
					myob.insertValue(inp);
				}
				fin.close();
			}
			else
			{
				cout << "::>> input.txt file couldn't found\n";
			}
			cout << "Required Task performed\n";
		}
		else if (userOpt == 11)
		{
			myob.deleteDuplicates();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 12)
		{
			myob.destroyCompleteTree();
			cout << "Required Task performed\n";
		}
		else if (userOpt == 13)
		{
			cout << ":::: GOOD BYE,THANKS FOR USING THIS PROGRAM ::::\n";
			break;
		}
		else
		{
			cout << ">> Invalid Input,Enter again with valid Input\n";
		}
		cout << "__________________________________________________________________\n";
		cout << "Going Back to Menu\n";
	}
}

