#include "Dlist.h"
/******************************************************
Programmer: Omer Mustel                 
Date:   Oct 31th, 2020                                
 Purpose: Implemetation of the Dlist class.
Input: None
Output: None
***************************************************************/

/*******************************************************/
//Constrcutor
//set first and last to NULL
/*******************************************************/
template <class T>
Dlist<T> ::Dlist()
{
   first = NULL;
   last = NULL;
}
/*******************************************************/
//destructor
// call destroy to destroy and links.
/*******************************************************/
template <class T>     
Dlist<T> :: ~Dlist()
{ 
   destroy();
}
/*******************************************************/
//copy constructor
//call copy consturcor and pass the other referance parameter
/*******************************************************/
template <class T>        
Dlist<T> :: Dlist ( const Dlist<T> & other)
{
  //call copy function
  copy(other);
}
/*******************************************************/
//copy assign operation
//call destry and then copy. 
/*******************************************************/
template <class T>        
const Dlist<T> & Dlist<T> :: operator= (const Dlist<T> & other)
{
   if ( this != &other ) //check both object have different addresses
   {
       destroy();
       copy(other);
   }
  return *this;
}
/*******************************************************/
//getLength
//return the length of the list by iterating through it.
/*******************************************************/
template <class T>        
int Dlist<T> :: getLength()
{
  //if isEmpty true, return 0 length
  if(isEmpty())
    return 0;

  node<T> *p;
  int counter = 0;
   p = first;
  //increment for each node
   while ( p != NULL )
   {
      counter++;
      p = p->next;
   }
  return counter;
}
/*******************************************************/
//isEmpty check if the list is empty
/*******************************************************/ 
template <class T>        
bool Dlist<T> :: isEmpty()
{
   return first == NULL; //return true if empty
}
/*******************************************************/
//insertItem
//inserts an item to the list and position it from 
//smaller to greater values.
/*******************************************************/ 
template <class T>
void Dlist<T> :: insertItem(T item)
{
  node<T> *current; //pointer to traverse the list
  node<T> *trailCurrent; //pointer previouscurrent
  node<T> *temp; //pointer to create a node
  bool flag;
  temp = new node<T>; //create new node
  temp->data = item; //store the new item in the node
  temp->next = temp->prev = NULL; //set next & prev to NULL

  if (first == NULL) //if list is empty, temp is the only node
  {
    first = temp;
    last = temp;
  }
  else
  {
    flag = false;
    current = first;
    while (current != NULL && !flag) //search the list
      if (current->data >= item)
        flag = true;
      else
      {
        trailCurrent = current;
        current = current->next;
      }
      if (current == first) //insert temp before first
      {
        first->prev = temp;
        temp->next = first;
        first = temp;
      }
      else
      {
      //insert temp between trailCurrent and current
      if (current != NULL)
      {
        trailCurrent->next = temp;
        temp->prev = trailCurrent;
        temp->next = current;
        current->prev = temp;
      }
      else
      {
        trailCurrent->next = temp;
        temp->prev = trailCurrent;
        last = temp;
      }
    }
  }
}
/*******************************************************/
//deleteItem
//this function allows the user to choose if all 
//occurances of the item should be deleted or only the //first occurrance.
/*******************************************************/ 
template <class T>      
void Dlist<T> :: deleteItem(T item)
{
  int choice; //user choice of operation.
  cout <<"\nTo delete all occurrances of the item press 0."
       <<"\nTo delete only one occurance, press 1: ";
  cin >> choice;
  //input validation for choice deletion
  while(choice < 0 || choice > 1)
  {
    cout << "Invalid input. Please enter 1 or 0";
    cin >> choice;
  }
  node<T> *current; //pointer to traverse the list
  node<T> *trailCurrent; //pointer just before current
  bool flag;
  if (first == NULL)
    cout << "Cannot delete from an empty list." << endl;
  else if(first->data == item && first->next == NULL)
    first = last = NULL;
  else if (first->data == item) //node to be deleted is
  //the first node
  {
    if(choice == 1) //if the user wants to delete only the first occurrance of item
    {
      current = first;
      first = first->next;
      if (first != NULL)
        first->prev = NULL;
      else
        last = NULL;
      delete current;
    }
    while(first->data == item && choice == 0)
    { //if the user wants to delete all occurrences
      current = first;
      first = first->next;
      if (first != NULL)
        first->prev = NULL;
      else
        last = NULL;
      delete current;
    }
  }
  else
  {
    flag = false;
    current = first;
    while (current != NULL && !flag) //search the list
      if (current->data >= item)
        flag = true;
      else
        current = current->next;
    if (current == NULL)
      cout << "The item to be deleted is not in the list." << endl;
    else if (current->data == item) //check for equality
    {
      if(choice == 1)
      {
        trailCurrent = current->prev;        trailCurrent->next = current->next;
        if (current->next != NULL)
          current->next->prev = trailCurrent;
        if (current == last)//specila case if the item is 
                            //at last position
          last = trailCurrent;
        delete current;
      }
      else
      { //for deletion of all occurrances
        while(current->data == item && choice == 0)
        {
          node<T> *p = current;
          trailCurrent = current->prev;        trailCurrent->next = current->next;
          if(current->next != NULL)
          {
            current->next->prev = trailCurrent;
            current = current->next;//walk current
                                    //as long its not last.
            delete p;
          }
          else if(current == last)
          { //special case if the loop reaches last link.
            last = trailCurrent;
            delete p;
          }
        }
      }
    }
    else
    cout << "The item to be deleted is not in list."  << endl;
  }
}
/*******************************************************/
//searchItem
//iterate through the list and if the item exist, 
//return true
/*******************************************************/ 
template <class T>        
bool Dlist<T> :: searchItem(T item)
{
  node<T> *p;

   p = first;

   while ( p != NULL )
   {
      if ( p->data == item )
         return true;
      p = p->next;
   }
  return false;
}
 /*******************************************************/
//destroy
//A multi used function to facilitate the copy constructor
//and the assignment operator overload.
//Iterates through the link to delete each link.
/*******************************************************/ 
template <class T>
void Dlist<T> :: destroy()
{
    node<T> *temp;

    while ( first != NULL )
    {
       temp = first;
       first = first->next;
       delete temp; 
    }
    last = NULL;
}
/*******************************************************/
//printList
//printing the list in ascending order
/*******************************************************/ 
template <class T>        
void Dlist<T> :: printList()
{
  if(isEmpty())
    cout << "The list is empty.\n\n";
  else
  {
    node<T> *p = first;

    while ( p != NULL )
    {
        cout<<p->data<<" ";
        p = p->next;
    }
  }     
}
/*******************************************************/
//printList
//printing the list in descending order
/*******************************************************/ 
template <class T>        
void Dlist<T> :: printReversedList()
{
  node<T> *l = last;

  while (l != NULL)
  {
    cout << l->data << " ";
    l = l->prev;
  }
}
/*******************************************************/
//copy
//A multi used function to facilitate the copy constructor
//and the assignment operator overload.
/*******************************************************/ 
template <class T>
void Dlist<T> :: copy ( const Dlist<T> & other )
{
   if ( other.first == NULL ) //check if other is empty
      first = NULL; //return null in this case
   else 
   {
       first = new node<T>; //creating new memory.
       first->data = other.first->data;

       node<T> *p = other.first->next;
       node<T> *r = first;

       while ( p != NULL )
       {
          r->next = new node<T>;
          r = r->next;
          r->data = p->data;
          r->prev = p->prev;
          p = p->next;
       } //copy link by link
       r->next = NULL;
       last = r;
  }
}
/*******************************************************/
//emptyTheList
//Emptying the list using destroy().
/*******************************************************/ 
template <class T>
void Dlist<T> :: emptyTheList()
{
  destroy();
  cout << "\nThe list is empty\n\n";
}

/*******************************************************/
//Dlist Iterator function to return the "first index"
//of the list.
/*******************************************************/
template <class T>
typename Dlist<T> :: Iterator Dlist<T> :: begin()
{
  Iterator list(first);
  return list;
}

/*******************************************************/
//Dlist Iterator function to return the "last index"
//of the list.
/*******************************************************/
template <class T>
typename Dlist<T> :: Iterator Dlist<T> :: end()
{
  Iterator list(last);
  return list;
}

/*******************************************************/
//Dlist Iterator function that give the ending condition
//for a loop using Iterator class.
/*******************************************************/
template <class T>
typename Dlist<T> :: Iterator Dlist<T> :: NullIteration()
{
  Iterator list;
  return list;
}

/******************************************************
Iterator class Implemetation
Input: None
Output: None
***************************************************************/


/*******************************************************/
///Default constructor
/*******************************************************/ 
template <class T>
Dlist<T> :: Iterator :: Iterator()
{
  curr = NULL;
}

/*******************************************************/
///This constructor set the coming node to current
/*******************************************************/ 
template <class T>
Dlist<T> :: Iterator :: Iterator(node<T> *&p)
{
  curr = p;
}

/*******************************************************/
///Copy constructor
/*******************************************************/ 
template <class T>
Dlist<T> :: Iterator :: Iterator(Iterator & other)
{
  if(other != *this)
    curr = other.curr;
}

/*******************************************************/
///Assignmeny operator over load
/*******************************************************/ 
template <class T>
typename Dlist<T> :: Iterator & Dlist<T> :: Iterator :: operator=(Iterator & other)
{
  if (this != other)
  {
    delete curr;
    curr = other.curr;
  }
  return *this;
}

/*******************************************************/
//inequality operator overload
/*******************************************************/ 
template <class T>
bool Dlist<T> :: Iterator :: operator!=(const Iterator & other)
{
  return curr!= other.curr;
}

/*******************************************************/
//Postfix increment operator
/*******************************************************/ 
template <class T>
typename Dlist<T> :: Iterator & Dlist<T> :: Iterator :: operator++(int)
{
  Iterator *temp = this;

  if (curr)
    curr = curr->next;

  return *temp;
}

/*******************************************************/
//Postfix decrement operator
/*******************************************************/
template <class T>
typename Dlist<T> :: Iterator & Dlist<T> :: Iterator :: operator--(int)
{
  Iterator *temp = this;

  if (curr)
    curr = curr->prev;

  return *temp;
}

/*******************************************************/
//overload asterisk dereferance operator to return data.
/*******************************************************/
template <class T>
T& Dlist<T> :: Iterator :: operator*()
{
  return curr->data;
}
