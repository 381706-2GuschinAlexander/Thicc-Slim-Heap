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
  Node(int64_t key_v, int64_t rank_v, Node* left_p, Node* right_p,
           Node* child_p);

  Node& operator=(const Node& node);

};


