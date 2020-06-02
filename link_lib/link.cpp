#include "link.h"

Node::Node() {
  key = rank = -1;
  left_ptr = right_ptr = child_ptr  = nullptr;
}

Node::Node(int64_t key_v, int64_t rank_v, Node* left_p,
                   Node* right_p, Node* child_p)
    : key(key_v),
      rank(rank_v),
      left_ptr(left_p),
      right_ptr(right_p),
      child_ptr(child_p) {}

Node& Node::operator=(const Node& node) {
  key = node.key;
  rank = node.rank;
  left_ptr = node.left_ptr;
  right_ptr = node.right_ptr;
  child_ptr = node.child_ptr;
}
