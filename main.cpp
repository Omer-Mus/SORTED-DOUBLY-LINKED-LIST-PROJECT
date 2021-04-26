#include "Dlist.cpp"
/******************************************************
Programmer: Omer Mustel                 
Date:   Oct 31th, 2020                                
 Purpose: Test the doubly list class using a menu driveen 
 program  
Input: user’s choice to perform an operation           
 Output: menu of choices and results of user’s operations.        ***************************************************************/

// printMenu displays a menu of choices and returns the user's choice
 
int printMenu();

// InsertList inserts an item into the list parameter

void insertListItem ( Dlist<int> & );

// deleteList deletes an item from the list parameter

void deleteListItem ( Dlist<int> & );

// searchItem searches for an item in the list parameter

void searchListItem ( Dlist<int>  ); 

// print list using Iterator class

void printUsingIterator(Dlist<int> & );

// reversed print list using iterator class

void reversedPrintUsingIterator(Dlist<int> & );

//********** main program **********

int main()
{
  
  Dlist<int> l;
  int choice;
   
  cout << "\nOperations allowed on the unsorted list of integers are below."
      << "\nPlease enter the number of your choice and press return.\n\n"; 

  choice = printMenu();

  while ( choice != 8 )
  {

       switch ( choice )
      {
   
         case 1 : insertListItem( l );
                  break;
    
         case 2 : deleteListItem ( l );
                  break;

         case 3 : cout << "Print list using print method: ";
                  l.printList(); //test next links
                  cout << endl;
                  cout << "Print list using Iterator class: ";
                   //test Iterator class
                  printUsingIterator(l);
                  cout << endl;
                  break;

         case 4 : cout << "Reversed print list using print method: ";
                  l.printReversedList(); //test prev links
                  cout << endl;
                  cout << "Reversed print list using Iterator class: ";
                  //test Iterator class
                  reversedPrintUsingIterator(l);
                  cout << endl;
                  break;             

         case 5 : searchListItem ( l );
                  break;
                     
         case 6 : cout << "\nThe list contains "<<l.getLength()
                      << " items\n\n";
                  break; 
          case 7 : l.emptyTheList();
                   break;
                 
         default :cout << "\nNumber is not correct. Please look at "
                      << "choices and reenter\n\n";
                 break;
      }

      choice = printMenu();
  }

  Dlist<int> l2; 

  l2 = l;

  if(!l2.isEmpty())
  {
    cout << "\nPrinting a new list with the same values as the old list \n";
   
    l2.printList(); //test for next connections

    cout << "\nPrint the new list backwards:\n";
    l2.printReversedList(); //test for prev connections
  }
  else
    cout << "\nNew list is empty.\n";
   
  cout << "\nProgram terminated\n\n";
   
   return 0;
}

//***********functions implementation***********//

/*******************************************************/
//printMenu
//Prints the menu for the program.
//No input, no output.
/*******************************************************/
int printMenu ()
{
   int c;

   cout << "\n1: Add an item to the list.";
   cout << "\n2: Delete an item from the list.";
   cout << "\n3: Print the list.";
   cout << "\n4: Print list in reverse.";
   cout << "\n5: Search the list for a given item";
   cout << "\n6: Return the number of items in the list";
   cout << "\n7: Empty the list";
   cout << "\n8: Quit.\n\n";
   cin >> c;

   return c;
}
/*******************************************************/
//insertListItem
//Calls the class isert function
//Input - reference object parameter.
//No output
/*******************************************************/
void insertListItem ( Dlist<int> &l )
{
   int num;  
  
   
      cout << "\nEnter the number to insert : ";
      cin >> num;
      l.insertItem(num);
      cout << "\nThe number has been inserted\n";
   
    
}
/*******************************************************/
//deleteListItem
//Calls the class delete function
//Input - reference object parameter.
//Output - confirm if item is been deleted or 
//         not in the list.
/*******************************************************/
void deleteListItem ( Dlist<int> &l )
{

   int num;

   cout << "\nEnter the number to delete : ";
   cin >> num;
   
   if ( l.searchItem (num))
   { 
      l.deleteItem(num);
      cout << "\nThe number has been deleted\n\n";
   }
   else  cout << "\nThe number is NOT in the list\n\n";
 
       
}
/*******************************************************/
//deleteListItem
//Calls the class delete function
//Input - object parameter.
//Output - Confirmation if item exist in the list by 
//         using the class's search function 
/*******************************************************/
void searchListItem ( Dlist<int> l )
{

   int num;

   cout << "\nEnter the number to search for : ";
   cin >> num;
       
   if ( l.searchItem (num))
   
       cout << "\nThe number is in the list\n\n";
   
   else  cout << "\nThe number is NOT in the list\n\n";
          
}

void printUsingIterator(Dlist<int> & l)
{
  Dlist<int>::Iterator list = l.begin();
  while (list != l.NullIteration())
  {
    cout << *list << " ";
    list++;
  }
  cout << endl;
}

void reversedPrintUsingIterator(Dlist<int> & l)
{
  Dlist<int>::Iterator list = l.end();
  while (list != l.NullIteration())
  {
    cout << *list << " ";
    list--;
  }
  cout << endl;
}
