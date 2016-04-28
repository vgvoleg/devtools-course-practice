// Copyright 2016 Murashov Michael

#ifndef MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_
#define MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_

#include <iostream>

typedef unsigned int SizeType;

template <class T>
class TStack {
 public:
    TStack();
    explicit TStack(const TStack<T>&);
    ~TStack();

    void push(const T&);
    void pop(void);
    T top(void) const;

    SizeType getSize(void) const;
    bool empty(void) const;

    bool        operator==  (const TStack<T>&) const;
    bool        operator!=  (const TStack<T>&) const;
    bool        operator<=  (const TStack<T>&) const;
    bool        operator>=  (const TStack<T>&) const;
    bool        operator<   (const TStack<T>&) const;
    bool        operator>   (const TStack<T>&) const;
    TStack<T>&  operator=   (const TStack<T>&);
    TStack<T>&  operator+   (const TStack<T>&);

    template<class V>
    friend void swap_st(TStack<V>*, TStack<V>*);

 protected:
    struct NODE {
        T* data;
        NODE* next;
    };

    SizeType size_;
    NODE* top_;

    // utility methods
    NODE* create_node(const T& data);
    void del_node(NODE* elem);
};



template<class T>
typename TStack<T>::NODE* TStack<T>::create_node(const T& data) {
    NODE* temp = new NODE;
    temp->data = new T;
    *temp->data = data;
    temp->next = nullptr;

    return temp;
}



template<class T>
void TStack<T>::del_node(NODE* elem) {
    if (elem != nullptr) {
        if (elem->data != nullptr)
            delete elem->data;

        delete elem;
    }
}



template<class T>
TStack<T>::TStack() : size_(0), top_(nullptr) { }



template<class T>
TStack<T>::TStack(const TStack<T>& st) {
    size_ = 0;

    TStack<T> temp;
    NODE* elem = st.top_;
    for (SizeType i = 0; i < st.size_; i++) {
        temp.push(*elem->data);
        elem = elem->next;
    }

    elem = temp.top_;
    for (SizeType i = 0; i < temp.size_; i++) {
        push(*elem->data);
        elem = elem->next;
    }
}



template<class T>
TStack<T>::~TStack() {
    NODE* temp;
    while (top_ != nullptr) {
        temp = top_->next;
        del_node(top_);
        top_ = temp;
    }
    size_ = 0;
}



template<class T>
void TStack<T>::push(const T& data) {
    if (!empty()) {
        NODE* temp = create_node(data);

        temp->next = top_;
        top_ = temp;
        size_++;
    } else {
        top_ = create_node(data);
        size_ = 1;
    }
}



template<class T>
void TStack<T>::pop(void) {
    if (!empty()) {
        NODE* temp = top_;
        top_ = top_->next;
        del_node(temp);
        size_--;
    }
}



template<class T>
T TStack<T>::top(void) const {
    T temp = (T)0;
    if (!empty())
        temp = *top_->data;

    return temp;
}



template<class T>
SizeType TStack<T>::getSize(void) const {
    return size_;
}



template<class T>
bool TStack<T>::empty(void) const {
    return (size_ == 0);
}



template<class T>
bool TStack<T>::operator==(const TStack<T>& st) const {
    if (size_ != st.size_) {
        return false;
    } else {
        NODE* temp = top_;
        NODE* temp_st = st.top_;

        for (SizeType i = 0; i < size_; i++) {
            if (*temp->data != *temp_st->data)
                return false;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return true;
}



template<class T>
bool TStack<T>::operator!=(const TStack<T>& st) const {
    return (!operator==(st));
}



template<class T>
bool TStack<T>::operator<=(const TStack<T>& st) const {
    return (operator<(st) || operator==(st));
}



template<class T>
bool TStack<T>::operator>=(const TStack<T>& st) const {
    return (operator>(st) || operator==(st));
}



template<class T>
bool TStack<T>::operator<(const TStack<T>& st) const {
    if (size_ < st.size_) {
        return true;
    } else {
        NODE* temp = top_;
        NODE* temp_st = st.top_;

        for (SizeType i = 0; i < size_; i++) {
            if (*temp->data < *temp_st->data)
                return true;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return false;
}



template<class T>
bool TStack<T>::operator>(const TStack<T>& st) const {
    if (size_ > st.size_) {
        return true;
    } else {
        NODE* temp = top_;
        NODE* temp_st = st.top_;

        for (SizeType i = 0; i < size_; i++) {
            if (*temp->data > *temp_st->data)
                return true;

            temp = temp->next;
            temp_st = temp_st->next;
        }
    }

    return false;
}



template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st) {
    if (this != &st) {
        this->~TStack();

        TStack<T> temp;
        NODE* elem = st.top_;
        for (SizeType i = 0; i < st.size_; i++) {
            temp.push(*elem->data);
            elem = elem->next;
        }

        elem = temp.top_;
        for (SizeType i = 0; i < temp.size_; i++) {
            push(*elem->data);
            elem = elem->next;
        }
    }

    return *this;
}



template<class T>
TStack<T>& TStack<T>::operator+(const TStack<T>& st) {
    if (!st.empty()) {
        TStack<T> temp;
        NODE* elem = st.top_;
        for (SizeType i = 0; i < st.size_; i++) {
            temp.push(*elem->data);
            elem = elem->next;
        }

        elem = temp.top_;
        for (SizeType i = 0; i < temp.size_; i++) {
            push(*elem->data);
            elem = elem->next;
        }
    }

    return *this;
}



template<class V>
void swap_st(TStack<V>* st_1, TStack<V>* st_2) {
    if (st_1 != st_2) {
        TStack<V> temp(*st_1);
        *st_1 = *st_2;
        *st_2 = temp;
    }
}

#endif  // MODULES_MURASHOV_MICHAEL_TSTACK_INCLUDE_TSTACK_H_
