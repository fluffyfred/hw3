#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	// if(head != NULL) {// 	if(head->val > pivot) {// 		Node l = Node(head->val, NULL);// 		larger = &l;// 		llpivot(head->next, smaller, l.next, pivot);// 	}// 	else {// 		Node s = Node(head->val, NULL);// 		smaller = &s;// 		llpivot(head->next, s.next, larger, pivot);// 	}// }// return; 
	// if we use tail recursion then a helper function is needed, since head has to be empty upon return
	smaller = NULL;
	larger = NULL;
	if(head == NULL) {
		return;
	}
	else {
		Node* temp = head;
		head = NULL; // head has to be empty upon return
		llpivot_helper(temp, smaller, larger, pivot);
	}
}

// helper function implementation
void llpivot_helper(Node *&shead, Node *&ssmaller, Node *&slarger, int spivot)
{
	// s stands for substitute
	if(shead == NULL) {
		ssmaller = NULL;
		slarger = NULL;
		return;
	}
	else if(shead->val <= spivot) {
		ssmaller = shead;
		llpivot_helper(shead->next, ssmaller->next, slarger, spivot);
	}
	else {
		slarger = shead;
		llpivot_helper(shead->next, ssmaller, slarger->next, spivot);
	}
}