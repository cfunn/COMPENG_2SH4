/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;

}

SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize;
	head = new SLLNode(sortedArray[0], NULL); // initialize first element
	SLLNode* lList = head;

	for (int i = 1; i < arrSize; i++) { // fill in the rest of the list one by one
		lList->next = new SLLNode(sortedArray[i], NULL);
		lList = lList->next;
	}
}

int SLLSet::getSize()
{
	return this->size; // return size of list
}

SLLSet SLLSet::copy()
{
	SLLNode* lList = this->head;

	int copyArr[this->size]; // make an array of copied values

	for (int i = 0; i < this->size; i++) { // fill in array
		copyArr[i] = lList->value;
		lList = lList->next;
	}

	return *(new SLLSet(copyArr, this->size)); // return new list made using the copied array
}

bool SLLSet::isIn(int v)
{
	SLLNode* lList = this->head;

	while (lList != NULL) { // check each value of the list and compare with v
		if (lList->value == v) {
			return true; // return true if v is in the list
		}
		lList = lList->next;
	}

	return false; // return false otherwise
}

void SLLSet::add(int v)
{
    if (!this->isIn(v)) { // first make sure v isn't already in the list
    	SLLNode* lList = this->head;
    	if (lList == NULL) { // if the list is empty
    		this->head = new SLLNode(v, NULL); // add a head
    	} else if (lList->value > v) { // if the element should be added to the beginning of the list
    		this->head = new SLLNode(v, lList); // change the head
    	} else { // if the element should be added to the middle or end of the list
    		while (lList->next != NULL) { // go through list until the correct location is reached
				if (lList->next->value > v) {
					break;
				}
				lList = lList->next;
			}
			lList->next = new SLLNode(v, lList->next); // add new node
    	}
    	this->size += 1; // increase size
    }
}

void SLLSet::remove(int v)
{
   if (this->isIn(v)) { // first make sure v is in the list
	   SLLNode* lList = this->head;
	   if (lList->value == v) { // if the element to be deleted is the first in the list
		   this->head = lList->next; // make the head the next element in the list
	   } else { // if the element to be deleted is anywhere else
		   SLLNode* prev;
		   while (lList->value != v) { // look through list until the correct value is found
			   prev = lList; // define previous list node as well
			   lList = lList->next;
		   }
		   prev->next = lList->next; // make the previous node point to the next node after the one to be deleted
	   }
	   delete lList; // delete the node
	   this->size -= 1; // decrease size
   }
}

SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLNode* thisList = this->head;
	SLLNode* sList = s.head;
	SLLSet* unionSet = new SLLSet();

	while (thisList != NULL) { // use add() method to add each element of this list
		unionSet->add(thisList->value);
		thisList = thisList->next;
	}

	while (sList != NULL) { // use add() method to add each element of s list (add automatically skips over repeat values)
		unionSet->add(sList->value);
		sList = sList->next;
	}

	return *unionSet;
}

SLLSet SLLSet::intersection(SLLSet s)
{
	SLLNode* thisList = this->head;
	SLLSet* interSet = new SLLSet();

	while (thisList != NULL) { // go through each value of this list
		if (this->isIn(thisList->value) && s.isIn(thisList->value)) { // find out if the value is shared with s list (if so, add it to the intersection list)
			interSet->add(thisList->value);
		}
		thisList = thisList->next;
	}

	return *interSet;
}

SLLSet SLLSet::difference(SLLSet s)
{
	SLLNode* thisList = this->head;
	SLLSet* diffSet = new SLLSet();
	SLLSet interSet = this->intersection(s); // get intersection (all the shared values)

	while (thisList != NULL) { // go through each value of this list
		if (!interSet.isIn(thisList->value)) { // if the value is not in the intersection, it should be in the difference
			diffSet->add(thisList->value);
		}
		thisList = thisList->next;
	}

	return *diffSet;
}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet unionSet = sArray[0]; // define union list, assign it to the first set in the array

	for (int i = 1; i < size; i++) { // then go through and get the union with each set in the array
		unionSet = unionSet.setUnion(sArray[i]);
	}

	return unionSet;
}

string SLLSet::toString()
{
	string set;
	SLLNode* lList = this->head;

	for (int i = 0; i < this->size; i++) { // convert list values to string
		set += std::to_string(lList->value);
		set += (i == this->size-1 ? "" : ", ");
		lList = lList->next;
	}

    return set;
}

