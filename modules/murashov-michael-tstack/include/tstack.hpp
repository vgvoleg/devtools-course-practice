// Copyright 2016 Murashov Michael

#ifndef MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_
#define MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_

#include <iostream>

typedef unsigned int size_type;

template <class T>
class tstack {
 public:
    tstack();
    explicit tstack(const tstack<T>&);
    ~tstack();

    void push(const T&);
    void pop(void);
    T top(void) const;

    size_type get_size(void) const;
    bool empty(void) const;

    bool operator==(const tstack<T>&) const;
    bool operator!=(const tstack<T>&) const;
    bool operator<=(const tstack<T>&) const;
    bool operator>=(const tstack<T>&) const;
    bool operator<(const tstack<T>&) const;
    bool operator>(const tstack<T>&) const;
    tstack<T>& operator=(const tstack<T>&);
    tstack<T>& operator+(const tstack<T>&);

    template<class V>
    friend void swap_st(tstack<V>*, tstack<V>*);

 protected:
    struct NODE {
        T* data;
        NODE* next;
    };

    size_type size;
    NODE* _top;

    // utility methods
    NODE* create_node(const T& data);
    void del_node(NODE* elem);
};

template<class T>
typename tstack<T>::NODE* tstack<T>::create_node(const T& data) {
    NODE* temp = new NODE;
    temp->data = new T;
    *temp->data = data;
    temp->next = nullptr;

    return temp;
}

template<class T>
void tstack<T>::del_node(NODE* elem) {
    if (elem != nullptr) {
        if (elem->data != nullptr)
            delete elem->data;

        delete elem;
    }
}

template<class T>
tstack<T>::tstack() : size(0), _top(nullptr) { }

template<class T>
tstack<T>::tstack(const tstack<T>& st) {
    size = 0;

    tstack<T> temp;
    NODE* elem = st._top;
    for (size_type i = 0; i < st.size; i++) {
        temp.push(*elem->data);
        elem = elem->next;
    }

    elem = temp._top;
    for (size_type i = 0; i < temp.size; i++) {
        push(*elem->data);
        elem = elem->next;
    }
}

template<class T>
tstack<T>::~tstack() {
    NODE* temp;
    while (_top != nullptr) {
        temp = _top->next;
        del_node(_top);
        _top = temp;
    }
    size = 0;
}

template<class T>
void tstack<T>::push(const T& data) {
    if (!empty()) {
        NODE* temp = create_node(data);

        temp->next = _top;
        _top = temp;
        size++;
    } else {
        _top = create_node(data);
        size = 1;
    }
}

template<class T>
void tstack<T>::pop(void) {
    if (!empty()) {
        NODE* temp = _top;
        _top = _top->next;
        del_node(temp);
        size--;
    }
}

template<class T>
T tstack<T>::top(void) const {
    T temp = (T)0;
    if (!empty())
        temp = *_top->data;

    return temp;
}

template<class T>
size_type tstack<T>::get_size(void) const {
    return size;
}

template<class T>
bool tstack<T>::empty(void) const {
    return (size == 0);
}

template<class T>
bool tstack<T>::operator==(const tstack<T>& st) const {
    if (size != st.size) {
        return false;
    } else {
        NODE* temp = _top;
        NODE* temp_st = st._top;

        for (size_type i = 0; i < size; i++) {
            if (*temp->data != *temp_st->data)
                return false;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return true;
}

template<class T>
bool tstack<T>::operator!=(const tstack<T>& st) const {
    return (!operator==(st));
}

template<class T>
bool tstack<T>::operator<=(const tstack<T>& st) const {
    return (operator<(st) || operator==(st));
}

template<class T>
bool tstack<T>::operator>=(const tstack<T>& st) const {
    return (operator>(st) || operator==(st));
}

template<class T>
bool tstack<T>::operator<(const tstack<T>& st) const {
    if (size < st.size) {
        return true;
    } else {
        NODE* temp = _top;
        NODE* temp_st = st._top;

        for (size_type i = 0; i < size; i++) {
            if (*temp->data < *temp_st->data)
                return true;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return false;
}

template<class T>
bool tstack<T>::operator>(const tstack<T>& st) const {
    if (size > st.size) {
        return true;
    } else {
        NODE* temp = _top;
        NODE* temp_st = st._top;

        for (size_type i = 0; i < size; i++) {
            if (*temp->data > *temp_st->data)
                return true;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return false;
}

template<class T>
tstack<T>& tstack<T>::operator=(const tstack<T>& st) {
    if (this != &st) {
        this->~tstack();

        tstack<T> temp;
        NODE* elem = st._top;
        for (size_type i = 0; i < st.size; i++) {
            temp.push(*elem->data);
            elem = elem->next;
        }

        elem = temp._top;
        for (size_type i = 0; i < temp.size; i++) {
            push(*elem->data);
            elem = elem->next;
        }
    }

    return *this;
}

template<class T>
tstack<T>& tstack<T>::operator+(const tstack<T>& st) {
    if (!st.empty()) {
        tstack<T> temp;
        NODE* elem = st._top;
        for (size_type i = 0; i < st.size; i++) {
            temp.push(*elem->data);
            elem = elem->next;
        }

        elem = temp._top;
        for (size_type i = 0; i < temp.size; i++) {
            push(*elem->data);
            elem = elem->next;
        }
    }

    return *this;
}

template<class V>
void swap_st(tstack<V>* st_1, tstack<V>* st_2) {
    if (st_1 != st_2) {
        tstack<V> temp(*st_1);
        *st_1 = *st_2;
        *st_2 = temp;
    }
}

#endif  // MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_
