#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"
   
using namespace std; 

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.

    void mergeSort();
    void selectionSort();   

private:
    void recMergeSort(nodeType<Type>* &head);
    void divideList(nodeType<Type>* first1, 
                    nodeType<Type>* &first2);
    nodeType<Type>* mergeList(nodeType<Type>* first1, 
                              nodeType<Type>* first2);

};


template<class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template<class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
   nodeType<Type> *newNode; //pointer to create the new node

   newNode = new nodeType<Type>; //create the new node

   assert(newNode != nullptr);      //if unable to allocate memory, 
                                 //terminate the program

   newNode->info = newItem; 	   //store the new item in the node
   newNode->link = first;        //insert newNode before first
   first = newNode;              //make first point to the 
                                 //actual first node
   count++; 			   //increment count

   if (last == nullptr)   //if the list was empty, newNode is also 
                      //the last node in the list
      last = newNode;
}//end insertFirst

template<class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    assert(newNode != nullptr);    //if unable to allocate memory,
                                //terminate the program

    newNode->info = newItem;   //store the new item in the node
    newNode->link = nullptr;   //set the link field of newNode
                            //to nullptr

    if (first == nullptr)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::
               divideList(nodeType<Type>* first1, 
                          nodeType<Type>* &first2)
{
    nodeType<Type>* middle;
    nodeType<Type>* current;

    if (first1 == nullptr)   //list is empty
        first2 = nullptr;
    else if (first1->link == nullptr) //list has only one node
        first2 = nullptr;
    else
    {
        middle = first1;
        current = first1->link;

        if (current != nullptr)  //list has more than two nodes
            current = current->link;
        while (current != nullptr)
        {
            middle = middle->link;
            current = current->link;
            if (current != nullptr)
                current = current->link;
        } //end while

        first2 = middle->link; //first2 points to the first 
                               //node of the second sublist
        middle->link = nullptr; //set the link of the last node
                             //of the first sublist to nullptr
    } //end else
} //end divideList

template<class Type>
nodeType<Type>* unorderedLinkedList<Type>::
                  mergeList(nodeType<Type>* first1, 
                            nodeType<Type>* first2)
{
    nodeType<Type> *lastSmall; //pointer to the last node of 
                               //the merged list
    nodeType<Type> *newHead;   //pointer to the merged list

    if (first1 == nullptr)   //the first sublist is empty
        return first2;
    else if (first2 == nullptr)  //the second sublist is empty
        return first1;
    else
    {
        if (first1->info < first2->info) //compare the 
                                         //first nodes
        {
            newHead = first1;  
            first1 = first1->link;
            lastSmall = newHead;
        }
        else
        {
            newHead = first2;
            first2 = first2->link;
            lastSmall = newHead;
        }
 
        while (first1 != nullptr && first2 != nullptr)
        {
            if (first1->info < first2->info)
            {
                lastSmall->link = first1;
                lastSmall = lastSmall->link;
                first1 = first1->link;
            }
            else
            {
                lastSmall->link = first2;
                lastSmall = lastSmall->link;
                first2 = first2->link;
            }
        } //end while

        if (first1 == nullptr) //first sublist exhausted first
            lastSmall->link = first2;
        else               //second sublist exhausted first
            lastSmall->link = first1;

        return newHead;
    } 
}//end mergeList

template<class Type>
void unorderedLinkedList<Type>::recMergeSort(
                                    nodeType<Type>* &head)
{
    nodeType<Type> *otherHead;

    if (head != nullptr)  //if the list is not empty
        if (head->link != nullptr)  //if the list has more than 
                                 //one node
        {
            divideList(head, otherHead);
            recMergeSort(head);
            recMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }
} //end recMergeSort

template<class Type>
void unorderedLinkedList<Type>::mergeSort()
{
    recMergeSort(first);

    if (first == nullptr)
        last = nullptr;
    else
    {
        last = first;
        while (last->link != nullptr)
            last = last->link;
    }
} //end mergeSort

template <class Type>
void unorderedLinkedList<Type>::selectionSort()
{
    // Empty list or single element
    if (this->first == nullptr || this->first->link == nullptr)
        return;

    nodeType<Type>* current = this->first;

    // loop through each position in the list
    while (current != nullptr)
    {
        nodeType<Type>* minNode = current;
        nodeType<Type>* scan = current->link;

        while (scan != nullptr)
        {
            if (scan->info < minNode->info)
                minNode = scan;

            scan = scan->link;
        }

        // Swap the info values of current and minNode
        if (minNode != current)
        {
            Type temp = current->info;
            current->info = minNode->info;
            minNode->info = temp;
        }

        current = current->link;
    }

    // Recompute last
    this->last = this->first;
    while (this->last != nullptr && this->last->link != nullptr)
        this->last = this->last->link;
}

#endif

