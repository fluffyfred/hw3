#ifndef LLREC_H
#define LLREC_H
#ifndef NULL
#define NULL 0
#endif

/**
 * Node struct for both problems
 */
struct Node
{
    int val;
    Node *next;

    Node(int v, Node* n) : val(v), next(n) {}
};


/**
 * Given a linked list pointed to by head, creates two lists
 * where all values less than or equal to the pivot value are
 * placed in a linked list whose head will be pointed to by
 * smaller and all values greater than the pivot
 * value are placed in a linked list whose head will be pointed to
 * by larger.  The input list pointed to by head should be empty
 * upon return and head set to NULL (i.e. we are not making copies)
 * in the smaller and larger lists but simply moving Nodes out of
 * the input list and into the two other lists.
 * 
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @pre: smaller and larger may containing garbage (do NOT have
 *       to be NULL)
 *
 * @param[inout] head
 *   Reference to the head pointer to the input list.
 *   Should be set to NULL upon return
 * @param[out] smaller
 *   Reference to a head pointer for the list of nodes with values
 *   less than or equal to the pivot
 * @param[out] larger
 *   Reference to a head pointer for the list of nodes with values
 *   greater than the pivot
 * @param[in] pivot
 *   Pivot value
 *
 */
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot);

/**
 * Given a linked list pointed to by head, removes (filters out) nodes
 * whose value does not meet the criteria given by the predicate
 * function object, pred (i.e. pred should be a function object that implements
 * `bool operator()(int value)` and returns *true* for items that should
 * be *removed/filtered*.  Removed items should be deallocated.
 *
 * ==============================================================
 * MUST RUN IN O(n) where n is the number of nodes in the input list
 * ==============================================================
 *
 * @param[in] head
 *   Reference to the head pointer to the input list.
 * @param[in] pred
 *   Predicate object implementing: `bool operator()(int value)` that
 *   returns true if a node (based on its value) should be removed.
 * @return a head pointer to the resulting list (since the head pointer
 *   may change [i.e. be filtered])
 *
 */
template <typename Comp>
Node* llfilter(Node* head, Comp pred);

// helper function prototypes
template <typename Comp>
void llfilter_helper(Node* shead, Comp pred);

void llpivot_helper(Node *&shead, Node *&ssmaller, Node *&slarger, int spivot);
//*****************************************************************************
// Since template implementations should be in a header file, we will
// implement the above function now.
//*****************************************************************************

template <typename Comp>
Node* llfilter(Node* head, Comp pred) 
{
	if(head == NULL) {
		return NULL;
	}
	else {
		Node* nextValid = llfilter(head->next, pred);
		if(pred(head->val)) {
			delete head;
			return nextValid;
		}
		else {
			head->next = nextValid;
			return head;
		}
	}
}
// template <typename Comp>
// Node* llfilter(Node* head, Comp pred)
// {
// 	// if we use tail recursion then we need to find the first element in head that can stay
// 	if(head == NULL) {
// 		return NULL;
// 	}
// 	else {
// 						Node* temp = head;
// 						// find the first element that can stay by a while loop
// 						while(pred(temp->val)) {
// 							Node* temp1 = temp;
// 							temp = temp->next;
// 							delete temp1;
// 							if(temp == NULL) {break;}
// 						}
// 						if(temp == NULL) {
// 							// if temp is NULL then all the elements in head are filtered 
// 							return NULL;
// 						}
// 						else {
// 							// call helper function
// 							Node* temp2 = temp;
// 							llfilter_helper(temp2, pred);
// 							return temp;
// 						}
// 	}
// }

// // helper function implementation
// template <typename Comp>
// void llfilter_helper(Node* shead, Comp pred)
// {
// 	// s stands for substitute
// 	if(shead == NULL) {
// 		return;
// 	}
// 	else if(pred(shead->val)) {
// 		// we should delete this
// 		Node* temp3 = shead;
// 		shead = shead->next;
// 		delete temp3;
// 		llfilter_helper(shead, pred);
// 	}
// 	else {
// 		// move on to the next element
// 		shead = shead->next;
// 		llfilter_helper(shead, pred);
// 	}
// }

#endif
