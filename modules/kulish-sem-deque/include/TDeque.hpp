// Copyright Kulish_Sem 2016

#include <string>
#include <initializer_list>

using std::string;
using std::initializer_list;
#ifndef MODULES_KULISH_SEM_DEQUE_INCLUDE_TDEQUE_H_
#define MODULES_KULISH_SEM_DEQUE_INCLUDE_TDEQUE_H_


template<class V>
class TDeque {
 public:
  TDeque();
  explicit TDeque(const V& data);
  explicit TDeque(const initializer_list<V>&);
  ~TDeque();

  void push_Tail(const V&);
  void push_Head(const V&);

  V pop_Tail();
  V pop_Head();
  void emplace_Head(const V);
  void emplace_Tail(const V);
  V operator[](const int& value)const;

  bool is_Empty()const;
  unsigned deque_Size()const;
  bool is_Exist(const V&)const;
  void erase(V, int);

 private:
  unsigned size;

  struct ITEM {
    V *data;
    ITEM *next;
    ITEM *previous;
  };

  ITEM *head;
  ITEM *tail;

  ITEM *create(const V& data);
  void delData(ITEM* item)const;
};

template<class V>
TDeque<V>::TDeque() : size(0), head(nullptr), tail(nullptr) {}

template<class V>
TDeque<V>::TDeque(const V& data):TDeque() {
  push_Head(data);
}

template<class V>
TDeque<V>::TDeque(const initializer_list<V>& list) :TDeque() {
  for (const V& elem : list)
    push_Tail(elem);
}

template<class V>
TDeque<V>::~TDeque() {
  ITEM* item = tail;

  while (item != head) {
    ITEM* temp = item->previous;

    delData(item);

    item = temp;
  }
  size = 0;
}

template<class V>
typename TDeque<V>::ITEM * TDeque<V>::create(const V & data) {
  ITEM *item = new ITEM;
  item->data = new V;

  *item->data = data;
  item->next = nullptr;
  item->previous = nullptr;

  return item;
}

template<class V>
void TDeque<V>::delData(ITEM* item)const {
  delete item->data;
  delete item;
}

template<class V>
V TDeque<V>::operator[](const int &positon)const {
  int counter = 1;
  V result = 0;
  ITEM* item = tail;

  if (positon > size || positon < 0) {
    result = positon;
  } else {
    while (counter <= positon) {
      if (counter == positon) {
        result = *item->data;
        return result;
      } else {
        item = item->previous;
        counter++;
      }
    }
  }
  return 0;
}

template<class V>
void TDeque<V>::push_Tail(const V& data) {
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

template<class V>
void TDeque<V>::push_Head(const V& data) {
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

template<class V>
V TDeque<V>::pop_Tail() {
  if (head != tail) {
    V data = *tail->data;
    ITEM *tmp = tail;

    tail = tail->previous;
    tail->next = nullptr;
    delData(tmp);

  } else {
    V data = *head->data;

    head = nullptr;
    tail = nullptr;
  }
  size--;
  return data;
}

template<class V>
V TDeque<V>::pop_Head() {
  if (head != tail) {
    V data = *head->data;
    ITEM *tmp = head;

    head = head->next;
    head->previous = nullptr;
    delData(tmp);

  } else {
    V data = *head->data;

    head = nullptr;
    tail = nullptr;

  }
  size--;
  return data;
}

template<class V>
void TDeque<V>::emplace_Head(const V data) {
  *head->data = data;
}

template<class V>
void TDeque<V>::emplace_Tail(const V data) {
  *tail->data = data;
}

template<class V>
bool TDeque<V>::is_Empty()const {
  return size == 0;
}

template<class V>
unsigned TDeque<V>::deque_Size()const {
  return size;
}

template<class V>
bool TDeque<V>::is_Exist(const V& data) const {
  ITEM* tmp = head;

  while (tmp) {
    if (*tmp->data == data)
      return true;

    tmp = tmp->next;
  }
  return false;
}


template<class V>
void TDeque<V>::erase(V data, const int position) {
  ITEM* item = tail;
  ITEM* tmp;
  int counter = 0;

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
