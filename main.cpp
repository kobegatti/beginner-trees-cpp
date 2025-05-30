#include <iostream>
#include <sstream>

#include "intTree.h"


////////////////////////////////////////
// global constants
///////////////////////////////////////
const short Insert = 1;
const short InOrder = 2;
const short LeafCount = 3;
const short TreeHeight = 4;
const short TreeWidth = 5;
const short Exit = 6;

const std::string MENU_PROMPT = "Select an option: ";
const std::string INSERT_PROMPT = "Enter node value (int): ";
const std::string INVALID_CHOICE = "Invalid choice: ";

void printMainMenu()
{
	std::cout << "1. Insert Node\n";
	std::cout << "2. In Order Print\n";
	std::cout << "3. Leaf Count\n";
	std::cout << "4. Tree Height\n";
	std::cout << "5. Tree Width\n";
	std::cout << "6. Exit\n";
	std::cout << std::endl;
}

////////////////////////////////////////
// string to long long int function
///////////////////////////////////////
long long int stringToInt(std::string str)
{
    if (str.empty())
    {
        return LLONG_MIN; // empty string error 
    }

    if (1 == str.size() && str.at(0) == '0')
    {
        return 0;
    }

    std::stringstream ss(str);
    long long int num = 0;

    ss >> num; // string to num

    if (0 == num) // char input error
    {
        return LLONG_MIN;
    }

    return num;
}

////////////////////////////////////////
// Insert Function
///////////////////////////////////////
void ProcessInsert(IntTree& Oak)
{
    std::string input = "";
    long long int data = 0;

    do
    {
        std::cout << INSERT_PROMPT; 
        getline(std::cin, input);

        data = stringToInt(input);

        if (data < INT_MIN || data > INT_MAX)
        {
            std::cout << "Entered: " << input << std::endl;
			std::cout << INT_MIN << " <= valid input <= " << INT_MAX;
			std::cout << std::endl;
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

int main()
{
    std::string choiceStr = "";
    IntTree Oak{};
    int choice = 0;

    do
    {
		printMainMenu();
        std::cout << MENU_PROMPT;

        getline(std::cin, choiceStr);
        choice = stringToInt(choiceStr);

        if (choice == Exit) { break; }

        switch (choice)
        {
            case Insert:
                ProcessInsert(Oak);
                break;
            case InOrder:
                ProcessDisplay(Oak);
                break;
            case LeafCount:
                ProcessLeafCount(Oak);
                break;
            case TreeHeight:
                ProcessTreeHeight(Oak);
                break;
            case TreeWidth:
                ProcessMaxTreeWidth(Oak);
                break;
            default:
                std::cout << INVALID_CHOICE << choice;
				std::cout << std::endl << std::endl;
                break;
        }

    } while (true);

    return EXIT_SUCCESS;
}
