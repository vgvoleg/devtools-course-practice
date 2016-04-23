// Copyright Kulish_Sem 2016

#include <string>

using std::string;
#ifndef MODULES_KULISH_SEM_DEQUE_INCLUDE_TDEQUE_H_
#define MODULES_KULISH_SEM_DEQUE_INCLUDE_TDEQUE_H_


template<class ValType>
class TDeque {
 public:
  TDeque();
  explicit TDeque(const ValType& data);
  ~TDeque();

  void addTail(const ValType&);
  void addHead(const ValType&);

  ValType getTail();
  ValType getHead();
  void emplace_Head(ValType);
  void emplace_Tail(ValType);
  ValType operator[](const int& value);

  bool isEmpty();
  int dequeSize();
  bool isExist(const ValType&)const;
  void erase(ValType, unsigned);

 private:
  unsigned int size;

  struct ITEM {
    ValType *data;
    ITEM *next;
    ITEM *previous;
  };

  ITEM *head;
  ITEM *tail;
  ITEM *create(const ValType& data) {
    ITEM *item = new ITEM;
    item->data = new ValType;

    *item->data = data;
    item->next = 0;
    item->previous = 0;

    return item;
  }
  void delData(ITEM* item);
};

template<class ValType>
TDeque<ValType>::TDeque() : size(0), head(0), tail(0) {}

template<class ValType>
TDeque<ValType>::TDeque(const ValType& data) {
  head = create(data);
  tail = head;
  size = 1;
}

template<class ValType>
TDeque<ValType>::~TDeque() {
  ITEM* item = tail;

  while (item != head) {
    ITEM* temp = item->previous;

    delete item->data;
    delete item;

    item = temp;
  }
  size = 0;
}

template<class ValType>
void TDeque<ValType>::delData(ITEM* item) {
  delete item->data;
  delete item;
}

template<class ValType>
ValType TDeque<ValType>::operator[](const int &value) {
  unsigned counter = 1;
  ValType result = 0;
  ITEM* item = tail;

  if (value > size || value < 0) {
    result = value;
  } else {
    while (counter <= value) {
      if (counter == value) {
        result = *item->data;
        break;
      } else {
        item = item->previous;
        counter++;
      }
    }
  }
  return result;
}

template<class ValType>
void TDeque<ValType>::addTail(const ValType& data) {
  if (head && tail) {
    ITEM *tmp = create(data);
    tmp->previous = tail;
    tail->next = tmp;
    tail = tmp;
  } else {
    head = create(data);
    tail = head;
  }
  size++;
}

template<class ValType>
void TDeque<ValType>::addHead(const ValType& data) {
  if (head && tail) {
    ITEM *tmp = create(data);
    tmp->next = head;
    head->previous = tmp;
    head = tmp;
  } else {
    head = create(data);
    tail = head;
  }
  size++;
}

template<class ValType>
ValType TDeque<ValType>::getTail() {
  if (head != tail) {
    ValType data = *tail->data;
    ITEM *tmp = tail;

    tail = tail->previous;
    tail->next = 0;
    delData(tmp);

    return data;
  } else {
    ValType data = *head->data;

    head = 0;
    tail = 0;

    return data;
  }
  size--;
}

template<class ValType>
ValType TDeque<ValType>::getHead() {
  if (head != tail) {
    ValType data = *head->data;
    ITEM *tmp = head;

    head = head->next;
    head->previous = 0;
    delData(tmp);

    return data;
  } else {
    ValType data = *head->data;

    head = 0;
    tail = 0;

    return data;
  }
  size--;
}

template<class ValType>
void TDeque<ValType>::emplace_Head(ValType data) {
  *head->data = data;
}

template<class ValType>
void TDeque<ValType>::emplace_Tail(ValType data) {
  *tail->data = data;
}

template<class ValType>
bool TDeque<ValType>::isEmpty() {
  return size == 0 ? true : false;
}

template<class ValType>
int TDeque<ValType>::dequeSize() {
  return size;
}

template<class ValType>
bool TDeque<ValType>::isExist(const ValType& data) const {
  ITEM* tmp = head;

  while (tmp) {
    if (*tmp->data == data)
      return true;

    tmp = tmp->next;
  }
  return false;
}


template<class ValType>
void TDeque<ValType>::erase(ValType data, const unsigned position) {
  ITEM* item = tail;
  ITEM* tmp;
  unsigned counter = 0;

  while (item) {
    if (*item->data == data && position <= counter) {
      if (item == tail) {
        tail = tail->previous;
        tail->next = nullptr;
        delData(item);
        item = tail;
      } else {
        if (item == head) {
          head = head->next;
          head->previous = nullptr;
          delData(item);
          item = head->previous;
        } else {
          tmp = item;
          item->next->previous = item->previous;
          item->previous->next = item->next;
          item = item->previous;
          delData(tmp);
        }
      }
    } else {
      counter++;
      item = item->previous;
    }
  }
}
#endif  // MODULES_KULISH_SEM_DEQUE_INCLUDE_TDEQUE_H_
