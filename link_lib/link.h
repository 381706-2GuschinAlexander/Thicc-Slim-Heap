#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

class Node {
 protected:
  int64_t key;
  int64_t rank;
  Node* left_ptr;
  Node* right_ptr;
  Node* child_ptr;

 public:
  Node();
  Node(int64_t key_v, int64_t rank_v, Node* left_p, Node* right_p,
           Node* child_p);
  void SetKey(int64_t value);
  void SetRank(int64_t value);
  void SetLeft(Node* pointer);
  void SetRight(Node* pointer);
  void SetChild(Node* pointer);

};


