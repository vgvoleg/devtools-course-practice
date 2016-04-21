// Copyright 2016 Litsov Alex

#ifndef MODULES_LITSOV_ALEX_BINARY_TREE_H_
#define MODULES_LITSOV_ALEX_BINARY_TREE_H_

#include <string>

class Element
{
    Element* parent;
    Element *right;
    Element *left;
    int key;
    std::string value;
public:
    Element(int _key = 0, std::string _value = "", Element* _parent = 0, Element* _right = 0, Element* _left = 0);
    Element(const Element& tmp);
    ~Element();
    int getKey();
    void setKey(const int& _key);
    std::string getValue();
    void setValue(const std::string& _value);
    void setRight(Element* _right);
    void setLeft(Element *_left);
    void setParent(Element *_parent);
    Element* getRight();
    Element* getLeft();
    Element* getParent();
};
class BinaryTree
{
    Element* root;
private:
    Element* CopyTree(Element* tmp, Element* parent = 0);
    void _getKeysOrderInSubtree(Element* start, std::string& order);
    void _getValuesOrderInSubtree(Element* start, std::string& order);
    void DeleteSubtree(Element* tmp);
public:
    BinaryTree(Element* _root = 0);
    Element* getRoot() const;
    BinaryTree(const BinaryTree& tmp);
    BinaryTree& operator=(BinaryTree& tmp);
    ~BinaryTree();
    void insertElem(Element* input);
    Element* searchByKeyInSubtree(const int& key, Element* start);
    Element* searchByValueInSubtree(const std::string& value, Element* start);
    Element* searchByKey(const int& key);
    Element* searchByValue(const std::string& value);
    Element* getMinByKeyInSubtree(Element* start);
    Element* getMinByKey();
    Element* getMaxByKeyInSubtree(Element* start);
    Element* getMaxByKey();
    Element* getSuccessor(Element* tmp);
    Element* getPredecessor(Element* tmp);
    std::string getKeysOrder();
    std::string getValuesOrderByKeys();
    std::string getKeysOrderInSubtree(Element* start);
    std::string getValuesOrderInSubtree(Element* start);
};

#endif  // MODULES_LITSOV_ALEX_BINARY_TREE_H_
