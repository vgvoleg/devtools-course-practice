// Copyright 2016 Ovcharuk Oleg
#ifndef QUEUE_H
#define QUEUE_H
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
    Queue(int DataCountM = MemSize);
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

#endif
