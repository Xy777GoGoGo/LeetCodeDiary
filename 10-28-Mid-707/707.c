


typedef struct MyLinkedList_t{
	int val;
	struct MyLinkedList_t *next;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	obj->val = 0;
	obj->next = NULL;
	return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
	if (index < 0 || obj->next == NULL) {
		return -1;
	}

	int now = 0;
	MyLinkedList *listNow = obj->next;
	while (now < index) {
		if (listNow == NULL) {
			return -1;
		}

		listNow = listNow->next;
		now++;
	}

	if (listNow != NULL) {
		return listNow->val;
	}

	return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	Node->val = val;
	Node->next = NULL;

	if (obj->next == NULL) {
		obj->next = Node;
		return;
	} else {
		Node->next = obj->next;
		obj->next = Node;
	}
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	Node->val = val;
	Node->next = NULL;

	MyLinkedList *nowList = obj;
	while (nowList->next != NULL) {
		nowList = nowList->next;
	}

	nowList->next = Node;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if (index <= 0) {
		myLinkedListAddAtHead(obj, val);
	}

	int now = 0;
	MyLinkedList *nowList = obj->next;
    if(!nowList)
        return;
	while (nowList->next != NULL) {
		if (now == index - 1) {
			break;
		}
		nowList = nowList->next;
		now++;
	}

	if (index - 1 != now) {
		return;
	}

	MyLinkedList *Node = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	Node->val = val;
	Node->next = nowList->next;
	nowList->next = Node;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	if (index < 0 || obj->next == NULL) {
		return;
	}

	if (index == 0) {
		obj->next = obj->next->next;
		return;
	}

	MyLinkedList *nowList = obj->next;
	int now = 0;
	while (nowList->next != NULL) {
		if (now == index - 1) {
			break;
		}
		nowList = nowList->next;
		now++;
	}

	if (now == index - 1 && nowList->next != NULL) {
		nowList->next = nowList->next->next;
	}
}

void myNodeFree(MyLinkedList* Node) {
	if (Node->next != NULL) {
		myNodeFree(Node->next);
		Node->next = NULL;
	}
	free(Node);
	
}

void myLinkedListFree(MyLinkedList* obj) {
    myNodeFree(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

