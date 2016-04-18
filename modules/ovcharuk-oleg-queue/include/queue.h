// Copyright 2016 Ovcharuk Oleg
#ifndef MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
#include <iostream>

#define EMPTY_QUEUE -100
#define FULL_QUEUE -101
#define MEM_SIZE 10
#define DATA_OK 0

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
    bool isEmpty(void) const;
    bool isFull(void) const;

 public:
    explicit Queue(int DataCountM = MEM_SIZE);
    ~Queue();
    int put(dataValue val, int pr);
    dataValue get(void);
    dataValue findMaxElem(void) const;
    dataValue findMinElem(void) const;
    dataValue findMaxElemHiPrior(void) const;
    dataValue findMinElemHiPrior(void) const;
    dataValue findMaxElemSetPrior(int pr = 1) const;
    dataValue findMinElemSetPrior(int pr = 1) const;
};

#endif  // MODULES_OVCHARUK_OLEG_QUEUE_INCLUDE_QUEUE_H_
