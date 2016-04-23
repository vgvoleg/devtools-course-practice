// Copyright 2016 Sirotkin_Nikita
#ifndef MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_LIST_H_
#define MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_LIST_H_
template<class ELEMENTS_TYPE>
class node
{
 private:
  ELEMENTS_TYPE value;
  node<ELEMENTS_TYPE> *next;
 public:
  node(ELEMENTS_TYPE _value);
  void setNext(node<ELEMENTS_TYPE> *_next);
  void setValue(ELEMENTS_TYPE _value);
  ELEMENTS_TYPE getValue();
  node<ELEMENTS_TYPE> *getNext();
};
template<class ELEMENTS_TYPE>
class list
{
 private:
  node<ELEMENTS_TYPE> *head;
  node<ELEMENTS_TYPE> *last;
  node<ELEMENTS_TYPE> *current;
 public:
  list();
  ~list();
  void addElement(ELEMENTS_TYPE value);
  bool operator++();
  ELEMENTS_TYPE getValue() const;
  void reset();
  bool isEmpty();
  void sort();
  list(const list<ELEMENTS_TYPE> &copy) = delete;
  void operator=(const list<ELEMENTS_TYPE> &copy) = delete;
};

//node
template<class ELEMENTS_TYPE>
node<ELEMENTS_TYPE>::node(ELEMENTS_TYPE _value): value(_value), next(nullptr) {
}

template<class ELEMENTS_TYPE>
ELEMENTS_TYPE node<ELEMENTS_TYPE>::getValue() {
  return value;
}

template<class ELEMENTS_TYPE>
node<ELEMENTS_TYPE> *node<ELEMENTS_TYPE>::getNext() {
  return next;
}

template<class ELEMENTS_TYPE>
void node<ELEMENTS_TYPE>::setNext(node<ELEMENTS_TYPE> *_next) {
  next = _next;
}

template<class ELEMENTS_TYPE>
void node<ELEMENTS_TYPE>::setValue(ELEMENTS_TYPE _value) {
  value = _value;
}

//list
template<class ELEMENTS_TYPE>
list<ELEMENTS_TYPE>::list(): head(nullptr), last(nullptr), current(nullptr) {
}

template<class ELEMENTS_TYPE>
list<ELEMENTS_TYPE>::~list() {
  node<ELEMENTS_TYPE> *deleting;
  node<ELEMENTS_TYPE> *next_deleting;
  deleting = head;
  while (deleting != nullptr) {
    next_deleting = deleting->getNext();
    delete deleting;
    deleting = next_deleting;
  }
}

template<class ELEMENTS_TYPE>
void list<ELEMENTS_TYPE>::addElement(ELEMENTS_TYPE value) {
  node<ELEMENTS_TYPE> *added = new node<ELEMENTS_TYPE>(value);
  if (last == nullptr) {
    head = added;
    current = head;
  }	else
    last->setNext(added);
  last = added;
}

template<class ELEMENTS_TYPE>
bool list<ELEMENTS_TYPE>::operator++() {
  if (current != nullptr) {
    current = current->getNext();
    if (current != nullptr)	return true;
    else {
      current = head;
      return false;
    }
  }	else return false;
}

template<class ELEMENTS_TYPE>
ELEMENTS_TYPE list<ELEMENTS_TYPE>::getValue() const {
  return current->getValue();
}

template<class ELEMENTS_TYPE>
void list<ELEMENTS_TYPE>::reset() {
  current = head;
}

template<class ELEMENTS_TYPE>
bool list<ELEMENTS_TYPE>::isEmpty() {
  return (head == nullptr);
}

template<class ELEMENTS_TYPE>
void list<ELEMENTS_TYPE>::sort() {
  if (head != nullptr) {
    node<ELEMENTS_TYPE> *first = head;
    node<ELEMENTS_TYPE> *second;
    ELEMENTS_TYPE for_swap = head->getValue();
    while (first != nullptr) {
      second = first->getNext();
      while (second != nullptr) {
        if (first->getValue() > second->getValue()) {
          for_swap = second->getValue();
          second->setValue(first->getValue());
          first->setValue(for_swap);
        }
        second = second->getNext();
      }
      first = first->getNext();
    }
  }
}

#endif //MODULES_SIROTKIN_NIKITA_FINANCE_NOTEPAD_INCLUDE_LIST_H_
