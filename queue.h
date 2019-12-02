#ifndef __INCLUDE_QUEUE_H__
#define __INCLUDE_QUEUE_H__
#include <iostream>
#include "node.h"
typedef enum equeue_error { QUEUE_OVERFLOW = -2, QUEUE_UNDERFLOW = -1, QUEUE_SUCCESS = 0 } QUEUE_ERROR;
template <class T>
class queue {
    public:
        queue<T>(int _max_queue_depth )  {
            queue_max = _max_queue_depth;
            error_node = new node<T>(0);
            queue_head = 0;
            queue_tail = 0;
        };
       ~queue<T>() { };
        QUEUE_ERROR enqueue(node<T> * x) {
            if ((queue_head == queue_tail+1) || ((queue_head == 0) && (queue_tail == queue_max)))
                return QUEUE_OVERFLOW;
            queue_nodes[queue_tail++] = x;
            if (queue_tail == queue_max)
                queue_tail = 0;
            return QUEUE_SUCCESS;
        };

        node<T> * dequeue(QUEUE_ERROR * p_err) {
            if (queue_head == queue_tail) {
                if (p_err != NULL) 
                    *p_err = QUEUE_UNDERFLOW;
                return error_node;
            };
            node<T> * x = queue_nodes[queue_head++];
            if (queue_head == queue_max)
                queue_head = 0;
            if (p_err != NULL)
                *p_err = QUEUE_SUCCESS;
            return x;
        }
        bool is_empty(void ) {
            return (queue_head == queue_tail);
        };
    protected:
        int queue_head;
        int queue_tail;
        int queue_max;
        node<T> * queue_nodes[256];
        node<T> * error_node;
 
};
#endif // __INCLUDE_QUEUE_H__


         
