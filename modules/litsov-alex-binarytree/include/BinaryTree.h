// Copyright 2016 Litsov Alex

#ifndef MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
#define MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_

#include <string>
using std::string;

class Element {
    Element* parent;
    Element *right;
    Element *left;
    int key;
    string value;
 public:
    explicit Element(int _key = 0, string _value = "",
        Element* _parent = 0, Element* _right = 0, Element* _left = 0);
    Element(const Element& tmp);
    ~Element();
    int getKey() const;
    void setKey(const int& _key);
    string getValue() const;
    void setValue(const string& _value);
    void setRight(Element* _right);
    void setLeft(Element *_left);
    void setParent(Element *_parent);
    Element* getRight() const;
    Element* getLeft() const;
    Element* getParent() const;
};
class BinaryTree {
    Element* root;

 private:
    Element* CopyTree(Element* tmp, Element* parent = 0) const;
    void _getKeysOrderInSubtree(Element* start, string* order) const;
    void _getValuesOrderInSubtree(Element* start, string* order) const;
    void DeleteSubtree(Element* tmp);

 public:
    explicit BinaryTree(Element* _root = 0);
    Element* getRoot() const;
    BinaryTree(const BinaryTree& tmp);
    BinaryTree& operator=(const BinaryTree& tmp);
    ~BinaryTree();
    void insertElem(Element* input);
    Element* searchByKeyInSubtree(const int& key, Element* start) const;
    Element* searchByValueInSubtree(const string& value, Element* start) const;
    Element* searchByKey(const int& key) const;
    Element* searchByValue(const string& value) const;
    Element* getMinByKeyInSubtree(Element* start) const;
    Element* getMinByKey() const;
    Element* getMaxByKeyInSubtree(Element* start) const;
    Element* getMaxByKey() const;
    Element* getSuccessor(Element* tmp) const;
    Element* getPredecessor(Element* tmp) const;
    string getKeysOrder() const;
    string getValuesOrderByKeys() const;
    string getKeysOrderInSubtree(Element* start) const;
    string getValuesOrderInSubtree(Element* start) const;
};

#endif  // MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
