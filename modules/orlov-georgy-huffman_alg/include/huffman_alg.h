// Copyright 2016 Orlov Georgy

#ifndef MODULES_ORLOV_GEORGY_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_
#define MODULES_ORLOV_GEORGY_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <fstream>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::vector;
using std::ostream;
using std::string;

class Huff {
 public:
    struct Node {
        int number;
        char symbol;
        Node *left, *right;

        Node() { left = right = NULL; }

        Node(Node *L, Node *R) {
            left = L;
            right = R;
            number = L->number + R->number;
        }
    };

    struct Compare {
        bool operator()(const Node* l, const Node* r) const {
            return l->number < r->number;
        }
    };

    map<char, int> ReadString(string);
    void FillNodeList(map<char, int>);
    void CreateTree();
//  void PrintTree(Node*, unsigned int);
    void BuildTable(Node* root);

    list<Node*> GetNodeList() { return nodeList; }
    Node* getRoot() { return nodeList.front(); }
    map<char, vector<bool> > GetTable() { return table; }

 private:
    vector<bool> code;
    list<Node*> nodeList;
    map<char, vector<bool> > table;

    friend ostream& operator<<(ostream& os, map<char, int>& m);
    friend ostream& operator<<(ostream& os, map<char, vector<bool> >& t);
    friend bool operator==(const Node&, const Node&);
};

#endif  // MODULES_ORLOV_GEORGY_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_
