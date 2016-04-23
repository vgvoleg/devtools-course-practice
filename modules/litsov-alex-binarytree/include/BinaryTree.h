// Copyright 2016 Litsov Alex
#ifndef MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
#define MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_

#include "Element.h"
#include <string>
using std::string;

class BinaryTree {
 public:
    explicit BinaryTree(Element* const init_root = 0);
    Element* GetRoot() const;
    BinaryTree(const BinaryTree& init_tree);
    BinaryTree& operator=(const BinaryTree& assigned_tree);
    ~BinaryTree();
    void InsertElem(Element* const input_element);
    Element* SearchByKeyInSubtree(const int& key, Element* start_element) const;
    Element* SearchByValueInSubtree(const string& value,
        Element* const start_element) const;
    Element* SearchByKey(const int& key) const;
    Element* SearchByValue(const string& value) const;
    Element* GetMinByKey() const;
    Element* GetMaxByKey() const;
    Element* GetSuccessor(Element* const specified_element) const;
    Element* GetPredecessor(Element* const specified_element) const;
    string GetKeysOrder() const;
    string GetValuesOrderByKeys() const;
    string GetKeysOrderInSubtree(Element* const start_element) const;
    string GetValuesOrderInSubtree(Element* const start_element) const;

 private:
    Element* CopySubtree(Element* subtree_root,
        Element* roots_parent = 0) const;
    Element* GetMinByKeyInSubtree(Element* const start_element) const;
    Element* GetMaxByKeyInSubtree(Element* const start_element) const;
    void GetKeysOrderInSubtreeRecurse(Element* start_element,
        string* order) const;
    void GetValuesOrderInSubtreeRecurse(Element* start_element,
        string* order) const;
    void DeleteSubtree(Element* subtree_root);

    Element* root_;
};

#endif  // MODULES_LITSOV_ALEX_BINARYTREE_INCLUDE_BINARYTREE_H_
