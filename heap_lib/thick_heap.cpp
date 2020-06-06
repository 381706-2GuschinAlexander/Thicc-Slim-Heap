#include "thick_heap.h"

ThickHeap::ThickHeap() : pointer(nullptr), max_rank(0) {}

void ThickHeap::UpdateForwardPtr(int64_t i) {
  if (root_count[i + 1].value == 2)
    root_count[i].forward = root_count[i + 1].forward;
  else
    root_count[i].forward = i + 1;
}

void ThickHeap::InsertTree(int i, FatNode* p) {
  auto p1 = root_count[i].list_ptr;
  if (root_count[i].value != 0)
    p->right_ptr = p1;
  else
    p->right_ptr = nullptr;
  p->left_ptr = nullptr;
  root_count[i].list_ptr = p;
}

void ThickHeap::DeleteTree(int i, FatNode* p) {
  auto p1 = root_count[i].list_ptr;
  if (p1 == p) root_count[i].list_ptr = p->right_ptr;
  int j = 1;
  while (j <= root_count[i].value && p1->right_ptr != p) {
    ++j;
    p1 = p1->right_ptr;
  }
  p1->right_ptr = p->right_ptr;
}

RootCountItem::RootCountItem() : value(0), forward(0), list_ptr(nullptr) {}
