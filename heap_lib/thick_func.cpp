#include "thick_func.h"
namespace thick {
ThickHeap* MakeHeap() { return new ThickHeap; }

void Insert(ThickHeap* heap, FatNode* node) {
  heap->rmIncCount(0, node);
  if (heap->min_key_ptr == nullptr || node->key < heap->min_key_ptr->key)
    heap->min_key_ptr = node;
}

FatNode* GetMin(ThickHeap* heap) { return heap->min_key_ptr; }

FatNode* ExtractMin(ThickHeap*& heap) {
  auto tmp = GetMin(heap);

  
  auto iter = tmp->child_ptr;
  heap->DeleteTree(tmp->rank, tmp);
  while (iter != nullptr) {
    auto iter_next = iter->right_ptr;
    heap->rmIncCount(iter->rank, iter);
    iter = iter_next;
  }

  iter = nullptr;
  heap->min_key_ptr = nullptr;
  for (int i = 0; i <= heap->max_rank; ++i) {
    iter = heap->root_count[i].list_ptr;
    while (iter != nullptr) {
      if (heap->min_key_ptr == nullptr || iter->key < heap->min_key_ptr->key)
        heap->min_key_ptr = iter;
      iter = iter->right_ptr;
    }
  }
  return tmp;
}
}  // namespace thick