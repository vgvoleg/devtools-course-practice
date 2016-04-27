// Copyright 2016 Orlov Georgy

#include <sstream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include "gtest/gtest.h"
#include "include/huffman_alg.h"

TEST(huffman_alg, Can_Creade_Node) {
    // Arrange
    Huff::Node *node;

    // Act
    node = new Huff::Node;

    // Assert
    EXPECT_NE(nullptr, node);
}

TEST(huffman_alg, Can_Creade_Node_From_Two_Other_Nodes) {
    // Arrange
    Huff::Node *parent;
    Huff::Node *leftSon;
    Huff::Node *rightSon;

    // Act
    leftSon = new Huff::Node;
    rightSon = new Huff::Node;
    parent = new Huff::Node(leftSon, rightSon);

    // Assert
    EXPECT_NE(nullptr, parent);
}

TEST(huffman_alg, Parent_Node_Number_Is_Sum_Of_Sons_Nodes_Numbers) {
    // Arrange
    Huff::Node *parent;
    Huff::Node *leftSon;
    Huff::Node *rightSon;

    // Act
    leftSon = new Huff::Node;
    leftSon->number = 5;
    rightSon = new Huff::Node;
    rightSon->number = 10;
    parent = new Huff::Node(leftSon, rightSon);

    // Assert
    EXPECT_EQ(15, parent->number);
}

TEST(huffman_alg, Compare_Method_Is_Work) {
    // Arrange
    Huff::Node *first;
    Huff::Node *second;
    list<Huff::Node*> l;

    // Act
    second = new Huff::Node;
    second->number = 5;
    l.push_back(second);
    first = new Huff::Node;
    first->number = 3;
    l.push_back(first);
    l.sort(Huff::Compare());

    // Assert
    EXPECT_EQ(first, l.front());
}

TEST(huffman_alg, Can_Right_Read_String) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap expected_m;
    FreqMap test_m;

    // Act
    expected_m['t'] = 2;
    expected_m['e'] = 1;
    expected_m['s'] = 1;
    test_m = huf.ReadString(str);

    // Assert
    EXPECT_EQ(expected_m, test_m);
}

TEST(huffman_alg, Can_Right_Display_The_Map_Char_Int) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap test_m;

    // Act
    std::ostringstream stream;
    test_m = huf.ReadString(str);
    for (auto& itr : test_m)
        stream << itr.first << ": " << itr.second << endl;

    // Assert
    const std::string expected_str = "e: 1\ns: 1\nt: 2\n";
    EXPECT_EQ(expected_str, stream.str());
}

TEST(huffman_alg, Can_Right_Display_The_Map_Like_Table) {
    // Arrange
    Huff huf;
    vector<bool> test_vect;
    TableMap test_m;

    // Act
    test_vect.push_back(0);
    test_vect.push_back(1);

    std::ostringstream stream;
    test_m['s'] = test_vect;
    for (auto& itr : test_m) {
        stream << itr.first << ": ";
        std::copy(itr.second.begin(), itr.second.end(),
            std::ostream_iterator<bool>(stream, ""));
        stream << endl;
    }

    // Assert
    const std::string expected_str = "s: 01\n";
    EXPECT_EQ(expected_str, stream.str());
}

TEST(huffman_alg, Can_Fill_Node_List) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap m;
    list<Huff::Node*> l;

    // Act
    m = huf.ReadString(str);
    huf.FillNodeList(m);

    // Assert
    const int expected_list_size = 3;
    EXPECT_EQ(expected_list_size, huf.GetNodeList().size());
}

TEST(huffman_alg, Nodes_Compare_Operator_True_Right) {
    // Arrange
    Huff::Node *node_1, *node_2;

    // Act
    node_1 = new Huff::Node;
    node_2 = new Huff::Node;
    node_1->symbol = node_2->symbol = 's';
    node_1->number = node_2->number = 2;

    // Assert
    EXPECT_TRUE(*node_1 == *node_2);
}

TEST(huffman_alg, Nodes_Compare_Operator_Symbol_False_Right) {
    // Arrange
    Huff::Node *node_1, *node_2;

    // Act
    node_1 = new Huff::Node;
    node_1->symbol = 'r';
    node_1->number = 2;
    node_2 = new Huff::Node;
    node_2->symbol = 's';
    node_2->number = 2;

    // Assert
    EXPECT_FALSE(*node_1 == *node_2);
}

TEST(huffman_alg, Nodes_Compare_Operator_Number_False_Right) {
    // Arrange
    Huff::Node *node_1, *node_2;

    // Act
    node_1 = new Huff::Node;
    node_1->symbol = 's';
    node_1->number = 3;
    node_2 = new Huff::Node;
    node_2->symbol = 's';
    node_2->number = 2;

    // Assert
    EXPECT_FALSE(*node_1 == *node_2);
}

TEST(huffman_alg, Fill_Node_List_Right) {
    // Arrange
    Huff huf;
    string str = "ttt";
    FreqMap m;
    list<Huff::Node*> l;

    // Act
    Huff::Node *node = new Huff::Node;
    node->number = 3;
    node->symbol = 't';
    l.push_back(node);

    m = huf.ReadString(str);
    huf.FillNodeList(m);

    // Assert
    EXPECT_TRUE(*l.front() == *huf.GetNodeList().front());
}

TEST(huffman_alg, Can_Create_Tree) {
    // Arrange
    Huff huf;
    string str = "test that horrible algorithm";
    FreqMap m;

    // Act
    m = huf.ReadString(str);
    huf.FillNodeList(m);
    huf.CreateTree();

    // Assert
    unsigned int expected_node_list_size = 1;
    EXPECT_TRUE(expected_node_list_size == huf.GetNodeList().size());
}

TEST(huffman_alg, Can_Build_Table_Right) {
    // Arrange
    Huff huf;
    string str = "test";
    FreqMap m;

    // Act
    m = huf.ReadString(str);
    huf.FillNodeList(m);
    huf.CreateTree();
    Huff::Node* root = huf.getRoot();
    huf.BuildTable(root);

    std::ostringstream stream;
    for (auto& itr : huf.GetTable()) {
        stream << itr.first << ": ";
        for (auto& vitr : itr.second)
            stream << vitr;
        stream << endl;
    }

    // Assert
    const std::string expected_str = "e: 10\ns: 11\nt: 0\n";
    EXPECT_EQ(expected_str, stream.str());
}
