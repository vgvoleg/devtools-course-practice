#include "include/BinaryTree.h"

#include <stdlib.h>
#include <string>

Element::Element(int _key, std::string _value, Element* _parent,
                 Element* _right, Element* _left) {
    key = _key;
    right = _right;
    left = _left;
    parent = _parent;
    value = _value;
}
Element::Element(const Element& tmp) {
    key = tmp.key;
    value = tmp.value;
    left = 0;
    right = 0;
    parent = 0;
}
Element::~Element() {
}
int Element::getKey() {
    return key;
}
void Element::setKey(const int& _key) {
    key = _key;
}
std::string Element::getValue() {
    return value;
}
void Element::setValue(const std::string& _value) {
    value = _value;
}
void Element::setRight(Element* _right) {
    right = _right;
}
void Element::setLeft(Element *_left) {
    left = _left;
}
void Element::setParent(Element *_parent) {
    parent = _parent;
}
Element* Element::getRight() {
    return right;
}
Element* Element::getLeft() {
    return left;
}
Element* Element::getParent() {
    return parent;
}

Element* BinaryTree::CopyTree(Element* tmp, Element* parent) {
    if (tmp == 0)
        return 0;
    Element *NewElement = new Element(tmp->getKey(),
        tmp->getValue(), tmp->getParent() );
    NewElement->setParent(parent);
    NewElement->setLeft(CopyTree(tmp->getLeft(), NewElement));
    NewElement->setRight(CopyTree(tmp->getRight(), NewElement));
    return NewElement;
}
void BinaryTree::_getKeysOrderInSubtree(Element* start, std::string* order) {
    if (start != 0) {
        _getKeysOrderInSubtree(start->getLeft(), order);
        *order += std::to_string(start->getKey()) + " ";
        _getKeysOrderInSubtree(start->getRight(), order);
    }
}
void BinaryTree::_getValuesOrderInSubtree(Element* start, std::string* order) {
    if (start != 0) {
        _getValuesOrderInSubtree(start->getLeft(), order);
        *order += start->getValue() + " ";
        _getValuesOrderInSubtree(start->getRight(), order);
    }
}
void BinaryTree::DeleteSubtree(Element* tmp) {
    if(tmp->getLeft() != 0)
        DeleteSubtree(tmp->getLeft());
    if(tmp->getRight() != 0)
        DeleteSubtree(tmp->getRight());
    delete tmp;
}
BinaryTree::BinaryTree(Element* _root) {
    root = _root;
}
Element* BinaryTree::getRoot() const {
    return root;
}
BinaryTree::BinaryTree(const BinaryTree& tmp) {
    root = this->CopyTree(tmp.getRoot());
}
BinaryTree& BinaryTree::operator=(const BinaryTree& tmp) {
    this->root = tmp.CopyTree(tmp.getRoot());
    return *this;
}
BinaryTree::~BinaryTree() {
    if (root != 0)
        DeleteSubtree(root);
}
void BinaryTree::insertElem(Element* input) {
    Element* tmp = new Element(*input);
    Element* y = 0;
    Element* x = root;
    while (x != 0) {
        y = x;
        if (tmp->getKey() < x->getKey())
            x = x->getLeft();
        else
            x = x->getRight();
    }
    tmp->setParent(y);
    if (y == 0)
        root = tmp;
    else
        if (tmp->getKey() < y->getKey())
            y->setLeft(tmp);
        else
            y->setRight(tmp);
}
Element* BinaryTree::searchByKeyInSubtree(const int& key, Element* start) {
    if (start == 0 || start->getKey() == key)
        return start;
    if (key < start->getKey())
        return searchByKeyInSubtree(key ,start->getLeft());
    else
        return searchByKeyInSubtree(key, start->getRight());
}
Element* BinaryTree::searchByValueInSubtree(const std::string& value, Element* start) {
    if(start == 0 || start->getValue() == value)
        return start;
    if(value < start->getValue())
        return searchByValueInSubtree(value ,start->getLeft());
    else
        return searchByValueInSubtree(value, start->getRight());
}
Element* BinaryTree::searchByKey(const int& key) {
    return searchByKeyInSubtree(key, root);
}
Element* BinaryTree::searchByValue(const std::string& value) {
    return searchByValueInSubtree(value, root);
}
Element* BinaryTree::getMinByKeyInSubtree(Element* start) {
    Element* tmp = start;
    while(tmp->getLeft() != 0)
        tmp = tmp->getLeft();
    return tmp;
}
Element* BinaryTree::getMinByKey() {
    return getMinByKeyInSubtree(root);
}
Element* BinaryTree::getMaxByKeyInSubtree(Element* start) {
    Element* tmp = start;
    while (tmp->getRight() != 0)
        tmp = tmp->getRight();
    return tmp;
}
Element* BinaryTree::getMaxByKey() {
    return getMaxByKeyInSubtree(root);
}
Element* BinaryTree::getSuccessor(Element* tmp) {
    if (tmp->getRight() != 0)
        return getMinByKeyInSubtree(tmp->getRight());
    Element* x = tmp;
    Element* y = x->getParent();
    while (y != 0 && x == y->getRight()) {
        x = y;
        y = y->getParent();
    }
    return y;
}
Element* BinaryTree::getPredecessor(Element* tmp) {
    if(tmp->getLeft() != 0)
        return getMaxByKeyInSubtree(tmp->getLeft());
    Element* x = tmp;
    Element* y = x->getParent();
    while(y != 0 && x == y->getLeft())
    {
        x = y;
        y = y->getParent();
    }
    return y;
}
std::string BinaryTree::getKeysOrder() {
    std::string res = "";
    _getKeysOrderInSubtree(root, &res);
    res = res.substr(0, res.length()-1);
    return res;
}
std::string BinaryTree::getValuesOrderByKeys() {
    std::string res = "";
    _getValuesOrderInSubtree(root, &res);
    res = res.substr(0, res.length()-1);
    return res;
}
std::string BinaryTree::getKeysOrderInSubtree(Element* start) {
    std::string res = "";
    _getKeysOrderInSubtree(start, &res);
    res = res.substr(0, res.length()-1);
    return res;
}
std::string BinaryTree::getValuesOrderInSubtree(Element* start) {
    std::string res = "";
    _getValuesOrderInSubtree(start, &res);
    res = res.substr(0, res.length()-1);
    return res;
}

