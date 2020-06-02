#include "link.h"

CoreNode::CoreNode() {
  key = rank = -1;
  left = right = child  = nullptr;
}

CoreNode::CoreNode(int64_t key_v, int64_t rank_v, CoreNode* left_p,
                   CoreNode* right_p, CoreNode* child_p)
    : key(key_v), rank(rank_v), left(left_p), right(right_p), child(child_p) {}
