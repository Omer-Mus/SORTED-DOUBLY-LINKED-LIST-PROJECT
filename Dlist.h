#include <iostream>
using namespace std;

/******************************************************
Programmer: Omer Mustel                 
Date:   Oct 31th, 2020                                
 Purpose: Decleration of the Dlist (Doubly Linked List)
          class.
Input: None
Output: None
***************************************************************/

#ifndef DLIST_H
#define DLIST_H

//Struct for doubly inked list nodes
template <class T>
struct node
{
   T data;
   node *next;  
   node *prev;   
};

template <class T>
class Dlist 
{
   protected:
       node<T> *first;
       node<T> *last;

   private: 
    // function to copy a list
    void copy (const Dlist<T> & other);
   public:
   //Iterator class decleration
   class Iterator;
      //Constructor : sets first to NULL
      Dlist();
      // Destructor: releases memory allocated for the array
      ~Dlist();
      //Copy constructor
     Dlist ( const Dlist<T> & other);
      //Overload the assignment operator 
      const Dlist<T> & operator= (const Dlist<T> & other);
      //Returns current length of list
      int getLength();
      // Returns true if list is full, false otherwise
      bool isEmpty();
      // Inserts parameter item 
      void insertItem(T item);
      //Remove an item from the list if exist. 
      //this function allows the user to choose 
      //if to delete similar occurrances
      void deleteItem(T item);
      //Returns true if parameter item is in the list, false otherwise
      bool searchItem(T item);
      //Print all items in the list. Print message if list is empty.
      void printList();
      //Print all items in the list in reverse. Print message if list is empty.
      void printReversedList();
      // Destroy list function
      void destroy();
      //epmty the whole list
      void emptyTheList();
      //First index of the list, return first
      Iterator begin();
      //Last index of the list, return last
      Iterator end();
      //creating an ending condition to the iteration
      //it will act as same as "while(first != NULL)"
      Iterator NullIteration();

/***********************************************/
//Iterator class: This class give the client
//The ability to iterate through the list
/***********************************************/
    class Iterator
    {
      private:
        node<T> *curr;
      public:
        // Default constructor: sets curr to NULL
        Iterator();
        // Constructor: set the value given to curr
        Iterator(node<T> *&);
        // Copy constructor
        Iterator(Iterator &);
        //Assignment operator overload
        Iterator& operator=(Iterator &);
        //Inequality operator overload
        bool operator!=(const Iterator &);
        //Postfix increment operator overload
        Iterator& operator++(int);
        //Postfix decrement operator overload
        Iterator& operator--(int);
        //Dereference operator overload to return
        //the data of the node.
        T& operator*();
    };

};


#endif

