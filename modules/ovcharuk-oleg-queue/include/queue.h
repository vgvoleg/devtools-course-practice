// Copyright 2016 Ovcharuk Oleg
#ifndef MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#include <iostream>

#define EmptyQueue -100
#define FullQueue -101
#define MemSize 10
#define DataOK 0

typedef int dataValue;

struct Node {
    dataValue value;
    int priority;
    Node* next;
    Node* prev;
};

class Queue {
 private:
    Node* head;
    Node* tail;
    int DataCountMax;
    int DataCount;
    bool isEmpty(void);
    bool isFull(void);
 public:
    Queue(int DataCountM = MemSize) {
        if (DataCountM <= 0) {
            throw "Incorrect size";
        }
        else {
            DataCountMax = DataCountM;
            head = NULL;
            tail = NULL;
            DataCount = 0;
        }
    };
    ~Queue();
    int put(dataValue val, int pr);
    dataValue get(void);
    dataValue findMaxElem(void);
    dataValue findMinElem(void);
    dataValue findMaxElemHiPrior(void);
    dataValue findMinElemHiPrior(void);
    dataValue findMaxElemSetPrior(int pr = 1);
    dataValue findMinElemSetPrior(int pr = 1);
};

#endif  // MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
