// Copyright 2016 Orlov Georgy

#include "include/huffman_alg.h"
#include <vector>
#include <map>
#include <string>

bool operator==(const Huff::Node& l, const Huff::Node& r) {
    if (l.number != r.number)
        return false;
    else if (l.symbol != r.symbol)
        return false;
    else
        return true;
}

list<Huff::Node*> Huff::GetNodeList() {
    return nodeList;
}

Huff::Node* Huff::getRoot() {
    return nodeList.front();
}

TableMap Huff::GetTable() {
    return table;
}

map<char, int> Huff::ReadString(string str) {
    map<char, int> m;

    for (unsigned int i = 0; i < str.length(); i++) {
        char symb = str[i];
        m[symb]++;
    }

    return m;
}

void Huff::FillNodeList(FreqMap m) {
    map<char, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        Node *p = new Node;
        p->symbol = itr->first;
        p->number = itr->second;
        nodeList.push_back(p);
    }
}

void Huff::CreateTree() {
    while (nodeList.size() != 1) {
        nodeList.sort(Compare());

        Node *SonL = nodeList.front();
        nodeList.pop_front();
        Node *SonR = nodeList.front();
        nodeList.pop_front();

        Node *parent = new Node(SonL, SonR);
        nodeList.push_back(parent);
    }
}

void Huff::BuildTable(Huff::Node* root) {
    if (root->left != NULL) {
        code.push_back(0);
        BuildTable(root->left);
    }

    if (root->right != NULL) {
        code.push_back(1);
        BuildTable(root->right);
    }

    if (root->left == NULL && root->right == NULL)
        table[root->symbol] = code;

    if (code.size() != 0)
        code.pop_back();
}

string Huff::GetStringFromTable(TableMap Tbl, string str) {
    string result;
    vector<bool> buf;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1')
            buf.push_back(1);
        else
            buf.push_back(0);
        for (auto& itr: Tbl)
            if (itr.second == buf) {
                result += itr.first;
                buf.clear();
            }
    }
    return result;
}
