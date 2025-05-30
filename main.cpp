#include <iostream>
#include <sstream>

#include "intTree.h"

using namespace std;

////////////////////////////////////////
// Global constants
///////////////////////////////////////
#define INSERT 1
#define IN_ORDER 2
#define LEAF_COUNT 3 
#define TREE_HEIGHT 4 
#define TREE_WIDTH 5 
#define EXIT 6 

const string MAIN_MENU = "1. Insert one integer into the tree\n2. In Order Display\n3. Display Leaf Count\n4. Display Tree Height\n5. Display Tree Width\n6. Exit\n";
const string MENU_PROMPT = "Please choose a menu option: ";
const string INSERT_PROMPT = "What value would you like to insert?";
const string ENTER_POS_NUM = "Please enter an integer greater than or equal to zero.";
const string INVALID_CHOICE = "Please enter a valid choice.";
const string THANK_YOU = "Thank you and goodbye.";

////////////////////////////////////////
// String to number function
///////////////////////////////////////
int GetNumber_From_String(string str)
{
   if (str.empty())
   {
      return 0; // empty string means zero
   }

   if (1 == str.size() && str.at(0) == '0')
   {
      return 0;
   }

   stringstream ss(str);
   int num = 0;

   ss >> num; // String to num

   if (0 == num) // Error for single char input
   {
      return -1;
   }

   return num;
}

////////////////////////////////////////
// Insert Function
///////////////////////////////////////
void ProcessInsert(IntTree& Oak)
{
   string input = "";
   int data = 0;

   do
   {
      cout << INSERT_PROMPT << endl; 
      getline(cin, input); // User input

      data = GetNumber_From_String(input);

      if (data < 0) // negative number error case
      {
         cout << "You entered " << input << endl << endl;
         cout << ENTER_POS_NUM << endl;
      }
      else
      {
         Oak.InsertNode(data);
		 
         cout << endl;
         break;
      }
   } while (true);
}

////////////////////////////////////////
// In order print function
///////////////////////////////////////
void ProcessDisplay(IntTree& Oak)
{
   cout << "Tree In Order: ";
   Oak.DisplayInOrder();
   cout << endl << endl;
}

////////////////////////////////////////
// Leaf count function
///////////////////////////////////////
void ProcessLeafCount(IntTree& Oak)
{
   int leaves = Oak.CountLeafNodes();
   cout << "Leaf Count: " << leaves << endl << endl;
}

////////////////////////////////////////
// Tree height function
///////////////////////////////////////
void ProcessTreeHeight(IntTree& Oak)
{
   int height = Oak.DisplayTreeHeight();
   cout << "Tree Height: " << height << endl << endl;
}

////////////////////////////////////////
// Tree width function
///////////////////////////////////////
void ProcessMaxTreeWidth(IntTree& Oak)
{
   int width = Oak.DisplayMaxWidth();
   cout << "Tree Width: " << width << endl << endl;
}

////////////////////////////////////////
// Driver function
///////////////////////////////////////
int main()
{
	string choice_str = "";
	IntTree Oak{};
	int choice = 0;

	do
	{
		cout << MAIN_MENU << endl;
		cout << MENU_PROMPT;

		getline(cin, choice_str);
		choice = GetNumber_From_String(choice_str);

		if (choice == EXIT)
		{
			cout << THANK_YOU << endl;
			break;
		}

		switch (choice)
		{
			case INSERT:
				ProcessInsert(Oak);
				break;
			case IN_ORDER:
				ProcessDisplay(Oak);
				break;
			case LEAF_COUNT:
				ProcessLeafCount(Oak);
				break;
			case TREE_HEIGHT:
				ProcessTreeHeight(Oak);
				break;
			case TREE_WIDTH:
				ProcessMaxTreeWidth(Oak);
				break;
			default:
				cout << INVALID_CHOICE << endl;
				break;
		}

	} while (true);

	return EXIT_SUCCESS;
}
