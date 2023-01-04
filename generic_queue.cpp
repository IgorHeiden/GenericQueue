/**
 * @file generic_queue.cpp
 * @author Igor Becker
 * @brief This file implements a generic array-based queue in C++,
 * any arbitrary struct will work as the array building block.
 */

#include "generic_queue.h"

using namespace std;

/**
 * @brief Verify if the queue is full
 * @author Igor Becker
 * @retval True if full, false otherwiswe
 */
template <typename Type>
bool Queue<Type>::queue_full() {return num_entries==this->size? true : false;}

/**
 * @brief Verify if the queue is empty
 * @author Igor Becker
 * @retval True if empty, false otherwiswe
 */
template <typename Type>
bool Queue<Type>::queue_empty() {return num_entries==0? true : false;}

/**
 * @brief Class constructor. Initializes private members and allocate memory for the queue array of the template type.
 * @author Igor Becker
 */
template <typename Type>
Queue<Type>::Queue(uint8_t sz) {
    this->head=0;
    this->tail=0xFF;
    this->num_entries=0;
    this->size=sz;
    this->data=new Type[sz];   
    memset(this->data,0,sizeof(Type)*sz);
}

/**
 * @brief Class destructor. Deallocate the memory of the queue array.
 * @author Igor Becker
 */
template <typename Type>
Queue<Type>::~Queue() {
    delete[] this->data;
}

/**
 * @brief Number of entries getter.
 * @author Igor Becker
 * @retval Number of enqueued itens
 */
template <typename Type>
uint8_t Queue<Type>::NumEntries() {
    return this->num_entries;
}

/**
 * @brief Enqueue data structure entry in the queue
 * @author Igor Becker
 * @param entry: data structure to be enqueued
 * @retval True if enqueue operation was successfull, false otherwiswe
 */
template <typename Type>
bool Queue<Type>::Enqueue(Type entry) {
    if(queue_full()) {
        return false;
    }

    if(this->tail == this->size-1) this->tail=0xFF;

    this->tail++;
    this->data[this->tail] = entry;
    this->num_entries++;

    return true;
}

/**
 * @brief Dequeue data structure from the queue to the entry pointer
 * @author Igor Becker
 * @param entry: pointer to a receiving "Type" data structure
 * @retval True if dequeue operation was successfull, false otherwiswe
 */
template <typename Type>
bool Queue<Type>::Dequeue(Type* entry) {
    if(queue_empty()) {
        return false;
    }

    *entry = this->data[this->head];
    this->head++;
    this->num_entries--;

    if(this->head==this->size) this->head=0;

    return true;
}

/**
 * @brief Peek the entry in the queue head
 * @author Igor Becker
 * @param entry: pointer to a receiving "Type" data structure
 * @retval True if peek operation was successfull, false otherwiswe
 */
template <typename Type>
bool Queue<Type>::Peek(Type* entry) {
    if(queue_empty()) {
        return false;
    }

    *entry = this->data[this->head];
    
    return true;
}

/*Templated classes declarations, used for linking phase... throws linking error if not declared here...
Example bellow:
template class Queue<My_Struct_Name>;*/