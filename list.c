#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	//temporary variable that will  store the last element smaller than new_element                                                                                                               
      	struct list_t *temp = head;
      	//If new element is smaller than the head, insert at front                                                                                                                                    
      	if(temp->index > new_element->index){
        	new_element->next = temp;
        	head = new_element;
        	return head;
      	}
      	//Move pointer to the position to insert the new elt.                                                                                                                                         
      	while(temp->next != NULL && temp->next->index < new_element->index){
        	temp = temp->next;
      	}
      	new_element->next = temp->next;
      	temp->next = new_element;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	//temporary variable pointing the next element in original list.                                                                                                                            
        struct list_t *temp = head;
        //head pointer to the new list                                                                                                                                                              
        struct list_t *newl = head;
        //pointer to the next element in the new list.                                                                                                                                              
        struct list_t *newnext = NULL;

        while(temp->next != NULL){
          newl = temp;
          newl->next = newnext;
          temp = temp->next;
          newnext = newl;
        }
        head = newl;
        
	return head;
}

