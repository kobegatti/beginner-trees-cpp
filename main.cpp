#include <iostream>
#include <sstream>

#include "intTree.h"


////////////////////////////////////////
// Global constants
///////////////////////////////////////
#define INSERT 1
#define IN_ORDER 2
#define LEAF_COUNT 3 
#define TREE_HEIGHT 4 
#define TREE_WIDTH 5 
#define EXIT 6 

const std::string MAIN_MENU = "1. Insert one integer into the tree\n2. In Order Display\n3. Display Leaf Count\n4. Display Tree Height\n5. Display Tree Width\n6. Exit\n";
const std::string MENU_PROMPT = "Please choose a menu option: ";
const std::string INSERT_PROMPT = "What value would you like to insert?";
const std::string ENTER_POS_NUM = "Please enter an integer greater than or equal to zero.";
const std::string INVALID_CHOICE = "Please enter a valid choice.";
const std::string THANK_YOU = "Thank you and goodbye.";

////////////////////////////////////////
// String to number function
///////////////////////////////////////
int GetNumber_From_String(std::string str)
{
   if (str.empty())
   {
      return 0; // empty string means zero
   }

   if (1 == str.size() && str.at(0) == '0')
   {
      return 0;
   }

   std::stringstream ss(str);
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
   std::string input = "";
   int data = 0;

   do
   {
      std::cout << INSERT_PROMPT << std::endl; 
      getline(std::cin, input); // User input

      data = GetNumber_From_String(input);

      if (data < 0) // negative number error case
      {
         std::cout << "You entered " << input << std::endl << std::endl;
         std::cout << ENTER_POS_NUM << std::endl;
      }
      else
      {
         Oak.InsertNode(data);
		 
         std::cout << std::endl;
         break;
      }
   } while (true);
}

////////////////////////////////////////
// In order print function
///////////////////////////////////////
void ProcessDisplay(IntTree& Oak)
{
   std::cout << "Tree In Order: ";
   Oak.DisplayInOrder();
   std::cout << std::endl << std::endl;
}

////////////////////////////////////////
// Leaf count function
///////////////////////////////////////
void ProcessLeafCount(IntTree& Oak)
{
   int leaves = Oak.CountLeafNodes();
   std::cout << "Leaf Count: " << leaves << std::endl << std::endl;
}

////////////////////////////////////////
// Tree height function
///////////////////////////////////////
void ProcessTreeHeight(IntTree& Oak)
{
   int height = Oak.DisplayTreeHeight();
   std::cout << "Tree Height: " << height << std::endl << std::endl;
}

////////////////////////////////////////
// Tree width function
///////////////////////////////////////
void ProcessMaxTreeWidth(IntTree& Oak)
{
   int width = Oak.DisplayMaxWidth();
   std::cout << "Tree Width: " << width << std::endl << std::endl;
}

////////////////////////////////////////
// Driver function
///////////////////////////////////////
int main()
{
	std::string choice_str = "";
	IntTree Oak{};
	int choice = 0;

	do
	{
		std::cout << MAIN_MENU << std::endl;
		std::cout << MENU_PROMPT;

		getline(std::cin, choice_str);
		choice = GetNumber_From_String(choice_str);

		if (choice == EXIT)
		{
			std::cout << THANK_YOU << std::endl;
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
				std::cout << INVALID_CHOICE << std::endl;
				break;
		}

	} while (true);

	return EXIT_SUCCESS;
}
