#include "link.h"

Node::Node() {
  key = -1;
  rank = 0;
  left_ptr = right_ptr = child_ptr  = nullptr;
}

Node::Node(int64_t key_v)
    : key(key_v),
      rank(0),
      left_ptr(nullptr),
      right_ptr(nullptr),
      child_ptr(nullptr) {}



Node& Node::operator=(const Node& node) {
  key = node.key;
  rank = node.rank;
  left_ptr = node.left_ptr;
  right_ptr = node.right_ptr;
  child_ptr = node.child_ptr;
  return *this;
}

FatNode::FatNode()
    : key(-1),
      rank(0),
      left_ptr(nullptr),
      right_ptr(nullptr),
      child_ptr(nullptr),
      parent_ptr(nullptr) {}

FatNode::FatNode(int64_t key_v)
    : key(key_v),
      rank(0),
      left_ptr(nullptr),
      right_ptr(nullptr),
      child_ptr(nullptr),
      parent_ptr(nullptr) {}

FatNode& FatNode::operator=(const FatNode& node) {
  key = node.key;
  rank = node.rank;
  left_ptr = node.left_ptr;
  right_ptr = node.right_ptr;
  child_ptr = node.child_ptr;
  parent_ptr = node.parent_ptr;
  return *this;
}
