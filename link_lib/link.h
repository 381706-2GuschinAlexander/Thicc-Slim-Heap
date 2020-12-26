#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int64_t key;
  int64_t rank;
  Node* left_ptr;
  Node* right_ptr;
  Node* child_ptr;

  Node();
  Node(int64_t key_v);

  Node& operator=(const Node& node);
};

struct FatNode {
  int64_t key;
  int64_t rank;
  FatNode* left_ptr;
  FatNode* right_ptr;
  FatNode* child_ptr;
  FatNode* parent_ptr;

  FatNode();
  FatNode(int64_t key_v);

  FatNode& operator=(const FatNode& node);
};
