#ifndef MODULES_BINARYTREE_INCLUDE_BINARYTREE_H_
#define MODULES_BINARYTREE_INCLUDE_BINARYTREE_H_

#include <string>
using std::string;

class Element {
 public:
    explicit Element(const int& init_key = 0, const string& init_value = "",
        Element* const init_parent = 0, Element* const init_right = 0, Element* const init_left = 0);
    Element(const Element& init_element);
    ~Element();
    int GetKey() const;
    void SetKey(const int& assigned_key);
    string GetValue() const;
    void SetValue(const string& assigned_value);
    void SetRight(Element* const  assigned_right);
    void SetLeft(Element* const assigned_left);
    void SetParent(Element* const assigned_parent);
    Element* GetRight() const;
    Element* GetLeft() const;
    Element* GetParent() const;

 private:
    Element* parent_;
    Element *right_;
    Element *left_;
    int key_;
    string value_;
};
class BinaryTree {
 public:
    explicit BinaryTree(Element* const init_root = 0);
    Element* GetRoot() const;
    BinaryTree(const BinaryTree& init_tree);
    BinaryTree& operator=(const BinaryTree& assigned_tree);
    ~BinaryTree();
    void InsertElem(Element* const input_element);
    Element* SearchByKeyInSubtree(const int& key, Element* start_element) const;
    Element* SearchByValueInSubtree(const string& value, Element* const start_element) const;
    Element* SearchByKey(const int& key) const;
    Element* SearchByValue(const string& value) const;
    Element* GetMinByKeyInSubtree(Element* const start_element) const;
    Element* GetMinByKey() const;
    Element* GetMaxByKeyInSubtree(Element* const start_element) const;
    Element* GetMaxByKey() const;
    Element* GetSuccessor(Element* const specified_element) const;
    Element* GetPredecessor(Element* const specified_element) const;
    string GetKeysOrder() const;
    string GetValuesOrderByKeys() const;
    string GetKeysOrderInSubtree(Element* const start_element) const;
    string GetValuesOrderInSubtree(Element* const start_element) const;

 private:
    Element* CopySubtree(Element* subtree_root, Element* roots_parent = 0) const;
    void GetKeysOrderInSubtreeRecurse(Element* start_element, string* order) const;
    void GetValuesOrderInSubtreeRecurse(Element* start_element, string* order) const;
    void DeleteSubtree(Element* subtree_root);

    Element* root_;
};

#endif  // MODULES_BINARYTREE_INCLUDE_BINARYTREE_H_