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
	// Node »ý¼º, itemÀ¸·Î ÃÊ±âÈ­
	return NULL;
}


void nfree(Node* node) {
	return;
}


Node* nclone(Node* node) {
	return NULL;
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
