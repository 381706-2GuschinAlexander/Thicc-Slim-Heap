#include "thick_heap.h"

ThickHeap::ThickHeap() : min_key_ptr(nullptr), max_rank(0), root_count(2), count_violation(2) {}

void ThickHeap::UpdateForwardPtr(int64_t i) {
  if (root_count[i + 1].value == 2)
    root_count[i].forward = root_count[i + 1].forward;
  else
    root_count[i].forward = i + 1;
}

void ThickHeap::InsertTree(int i, FatNode* p) {
  auto p1 = root_count[i].list_ptr;
  if (root_count[i].value != 0) {
    p->right_ptr = p1;
    p1->left_ptr = p;
  }
  else
    p->right_ptr = nullptr;
  p->left_ptr = nullptr;
  p->parent_ptr = nullptr;
  root_count[i].list_ptr = p;
  root_count[i].value++;
}

void ThickHeap::DeleteTree(int i, FatNode* p) {
  auto p1 = root_count[i].list_ptr;
  if (p1 == p) root_count[i].list_ptr = p->right_ptr;
  else if (p->right_ptr != nullptr) {
    p->left_ptr->right_ptr = p->right_ptr;
    p->right_ptr->left_ptr = p->left_ptr;
  } else {
    p->left_ptr->right_ptr = nullptr;
  }
  root_count[i].value--;
}

FatNode* ThickHeap::fastening(FatNode* p1, FatNode* p2, FatNode* p3) {
  FatNode* minP = nullptr;
  if (p1->key <= p2->key &&  p1->key <= p3->key) {
      minP = p1;
      p1 = p2;
      p2 = p3;
    } else
  if (p2->key <= p1->key && p2->key <= p3->key) {
    minP = p2;
    p2 = p3;
  } else 
  if (p3->key <= p1->key && p3->key <= p2->key) {
    minP = p3;
  }

  p1->right_ptr = p2;
  p1->left_ptr = nullptr;
  p1->parent_ptr = minP;
  p2->right_ptr = minP->child_ptr;
  p2->left_ptr = p1;
  p2->parent_ptr = minP;
  if (minP->child_ptr != nullptr) minP->child_ptr->left_ptr = p2;
  minP->child_ptr = p1;
  minP->rank++;
  minP->right_ptr = nullptr;
  minP->left_ptr = nullptr;
  return minP;
}

void ThickHeap::rmFixRootCount(int i) {
  if (max_rank == i) {
    max_rank++;
    root_count.push_back(RootCountItem());
    //count_violation.push_back(CountViolatinItem());
  } else
    UpdateForwardPtr(i + 1);

  root_count[i].value -=3;
  auto p1 = root_count[i].list_ptr;
  auto p2 = p1->right_ptr;
  auto p3 = p2->right_ptr;
  root_count[i].list_ptr = p3->right_ptr;
  auto p = fastening(p1, p2, p3);
  InsertTree(i + 1, p);
}

void ThickHeap::rmIncCount(int i, FatNode* node) {
  if (root_count[i].value < 3 && root_count[root_count[i].forward].value == 3)
    rmFixRootCount(root_count[i].forward);
  if (root_count[i].value == 3) rmFixRootCount(i);
  InsertTree(i, node);
  UpdateForwardPtr(i);
  if (root_count[i].value == 3) rmFixRootCount(i);
}

RootCountItem::RootCountItem() : value(0), forward(0), list_ptr(nullptr) {}
