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

typedef map<char, int> FreqMap;
typedef map<char, vector<bool>> TableMap;

class Huff {
 public:
    struct Node {
        int number;
        char symbol;
        Node *left, *right;

        Node() {
            left = right = nullptr;
        }

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

    FreqMap ReadString(string);
    void FillNodeList(FreqMap);
    void CreateTree();
    void BuildTable(Node* root);
    string GetStringFromTable(TableMap, string);

    list<Node*> GetNodeList() {
        return nodeList;
    }
    Node* getRoot() {
        return nodeList.front();
    }
    TableMap GetTable() {
        return table;
    }

 private:
    vector<bool> code;
    list<Node*> nodeList;
    TableMap table;

    friend bool operator==(const Node&, const Node&);
};

#endif  // MODULES_ORLOV_GEORGY_HUFFMAN_ALG_INCLUDE_HUFFMAN_ALG_H_
