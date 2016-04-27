// Copyright 2016 Orlov Georgy

#include  "include/huffman_alg.h"
#include <map>
#include <string>
#include <vector>

ostream& operator<<(ostream& os, map<char, int>& m) {
    map<char, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        os << itr->first << ": " << itr->second << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, map<char, vector<bool> >& t) {
    map<char, vector<bool> >::iterator itr;
    vector<bool>::iterator vitr;
    for (itr = t.begin(); itr != t.end(); ++itr) {
        os << itr->first << ": ";
        for (vitr = itr->second.begin(); vitr != itr->second.end(); ++vitr)
            os << *vitr;
        os << endl;
    }
    return os;
}

bool operator==(const Huff::Node& l, const Huff::Node& r) {
    if (l.number != r.number)
        return false;
    else if (l.symbol != r.symbol)
        return false;
    else
        return true;
}

map<char, int> Huff::ReadString(string str) {
    map<char, int> m;

    for (unsigned int i = 0; i < str.length(); i++) {
        char symb = str[i];
        m[symb]++;
    }

    return m;
}

void Huff::FillNodeList(map<char, int> m) {
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

/*void Huff::PrintTree(Huff::Node* root, unsigned int k = 0) {
    if(root != NULL) {
        PrintTree(root->left, k + 3);

        for (unsigned int i = 0; i < k; i++)
            cout << "  ";
        if (root->left == NULL && root->right == NULL)
            cout << root->number << " ("
            << root->symbol << ")" << endl;
        else
            cout << root->number << endl;
        PrintTree(root->right, k + 3);
    }
}*/

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
