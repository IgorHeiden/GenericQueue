/** //TODO: RELOCAR PARA OUTRA PASTA
 * @file data_structures.h
 * @author Igor Becker
 * @brief This file declares a generic queue and acquired data classes and the main data structures to handle the
 *  incoming data from the controller and the telemetry data acquired by this device.
 */

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdint>
#include <stdbool>

/**
 * GENERIC QUEUE CLASS
*/
template<typename Type>
class Queue {
    private:
       uint8_t num_entries;
       uint8_t head;
       uint8_t tail;
       uint8_t size;
       Type *data;       
    public:
        Queue(uint8_t sz);
        ~Queue();
        bool queue_full(void);
        bool queue_empty(void);
        uint8_t NumEntries(void);
        bool Enqueue(Type entry);
        bool Dequeue(Type* entry);
        bool Peek(Type* entry);
};

#endif