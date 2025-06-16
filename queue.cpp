#include <iostream>
#include "queue.h"


Queue* init(void) {
    Queue* queue = new Queue;
    queue->head = nullptr;
    queue->tail = nullptr;
    return queue;
}


void release(Queue* queue) {
    if (queue == nullptr) return;

    Node* curr = queue->head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        nfree(temp);  
    }

    delete queue;  
}



Node* nalloc(Item item) {
	// Node 생성, item으로 초기화
	Node* node = new Node;
	node->item = item;
	node->next = nullptr;
	return node;
}


void nfree(Node* node) {
	delete node;
}


Node* nclone(Node* node) {
	if (node == nullptr) return nullptr;
	return nalloc(node->item);
}


Reply enqueue(Queue* queue, Item item) {
	Reply reply = { false, NULL };
	return reply;
}

Reply dequeue(Queue* queue) {
	Reply reply = { false, NULL };
	return reply;
}

Queue* range(Queue* queue, Key start, Key end) {
	return NULL;
}
