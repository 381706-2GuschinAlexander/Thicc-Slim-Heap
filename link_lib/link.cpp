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

void Node::SetKey(int64_t value) { key = value; }

void Node::SetRank(int64_t value) { rank = value; }

void Node::SetLeft(Node* pointer) { left_ptr = pointer; }

void Node::SetRight(Node* pointer) { right_ptr = pointer; }

void Node::SetChild(Node* pointer) { child_ptr = pointer; }

int64_t Node::GetKey() { return key; }

int64_t Node::GetRank() { return rank; }

Node* Node::GetLeft() { return left_ptr; }

Node* Node::GetRight() { return right_ptr; }

Node* Node::GetChild() { return child_ptr; }

