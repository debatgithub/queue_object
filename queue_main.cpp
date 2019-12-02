#include <iostream>
#include "node.h"
#include "queue.h"
int main (void );
#define QUEUE_MAX 8
int queue_vals[QUEUE_MAX+1] = { 0, 1, 2, 3, 5, 8, 13, 21, 34 };
int main (void ) 
{

    queue<int> * p_test_queue = new queue<int>(QUEUE_MAX);
    QUEUE_ERROR res = QUEUE_SUCCESS;
    node<int> * p_node = NULL;
    if (p_test_queue == NULL) {
        std::cout << "Queue constructor failed" << std::endl;
        return 1;
    }
    std::cout << "Queue constructor passed" << std::endl;
    if (p_test_queue->is_empty() != true) {
        std::cout << "Queue is_empty test failed" << std::endl;
        return 1;
    }
    std::cout << "Queue is_empty test passed" << std::endl;
 
    for (int i = 0; i < 4; i++) {
        p_node = new node<int>(queue_vals[i]);
        res = p_test_queue->enqueue(p_node);
        if (res != QUEUE_SUCCESS) {
            std::cout << "Queue normal enqueue test failed" << std::endl;
            return 1;
        }
    }
    std::cout << "Queue normal enqueue test for nodes 0-3 passed" << std::endl;
    for (int i = 0; i < 3; i++) {
        p_node = p_test_queue->dequeue(&res);
        if (res != QUEUE_SUCCESS) {
            std::cout << "Queue normal dequeue test failed" << std::endl;
            return 1;
        }
        int x = p_node->get_data();
        if (x != (queue_vals[i])) {
            std::cout << "Queue dequeue integrity test failed" << std::endl;
            std::cout << "Expected value is " << queue_vals[QUEUE_MAX -i -1] << std::endl;
            std::cout << "Actual popped value is " << x << std::endl;
        }
    }
    std::cout << "Queue normal dequeue test for nodes 0-2 passed" << std::endl;
    for (int i = 4; i < QUEUE_MAX; i++) {
        p_node = new node<int>(queue_vals[i]);
        res = p_test_queue->enqueue(p_node);
        if (res != QUEUE_SUCCESS) {
            std::cout << "Queue normal enqueue test failed" << std::endl;
            return 1;
        }
    }
    std::cout << "Queue normal enqueue test for nodes 4-8 passed" << std::endl;
    for (int i = 3; i < QUEUE_MAX; i++) {
        p_node = p_test_queue->dequeue(&res);
        if (res != QUEUE_SUCCESS) {
            std::cout << "Queue normal dequeue test failed" << std::endl;
            return 1;
        }
        int x = p_node->get_data();
        if (x != (queue_vals[i])) {
            std::cout << "Queue dequeue integrity test failed" << std::endl;
            std::cout << "Expected value is " << queue_vals[QUEUE_MAX -i -1] << std::endl;
            std::cout << "Actual popped value is " << x << std::endl;
        }
    }
    std::cout << "Queue normal dequeue test for nodes 3-8 passed" << std::endl;


    delete p_test_queue;
    return 0;

   
}


        
