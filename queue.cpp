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
    Reply reply = { false, item };

    if (queue == nullptr) return reply;

    Node* new_node = nalloc(item);
    if (new_node == nullptr) return reply;

    
    if (queue->head == nullptr) {
        queue->head = queue->tail = new_node;
        reply.success = true;
        return reply;
    }

    
    if (item.key > queue->head->item.key) {
        new_node->next = queue->head;
        queue->head = new_node;
        reply.success = true;
        return reply;
    }

   
    Node* prev = queue->head;
    Node* curr = queue->head->next;

    while (curr != nullptr && item.key <= curr->item.key) {
        prev = curr;
        curr = curr->next;
    }

    new_node->next = curr;
    prev->next = new_node;

    if (curr == nullptr)
        queue->tail = new_node;  // 포인터가 아니라 값을 복사


    reply.success = true;
    return reply;
}

Reply dequeue(Queue* queue) {
	Reply reply = { false, NULL };
	return reply;
}

Queue* range(Queue* queue, Key start, Key end) {
	return NULL;
}
