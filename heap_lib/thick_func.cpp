#include "thick_func.h"
namespace thick {
ThickHeap* MakeHeap() { return new ThickHeap; }

void Insert(ThickHeap* heap, FatNode* node) {
  heap->InsertTree(0, node);
  if (heap->min_key_ptr == nullptr || node->key < heap->min_key_ptr->key) heap->min_key_ptr = node;
}

FatNode* GetMin(ThickHeap* heap) { return heap->min_key_ptr; }

// ThickHeap* Merge(ThickHeap* heap_f, ThickHeap* heap_s) {
//  if (heap_f->start == nullptr) return heap_s;
//  if (heap_s->start == nullptr) return heap_f;
//  if (heap_f->start->key < heap_s->start->key) {
//    heap_f->end->right_ptr = heap_s->start;
//    heap_f->end = heap_s->end;
//    delete heap_s;
//    return heap_f;
//  } else {
//    heap_s->end->right_ptr = heap_f->start;
//    heap_s->end = heap_f->end;
//    delete heap_f;
//    return heap_s;
//  }
//}

FatNode* ExtractMin(ThickHeap*& heap) {
  auto tmp = GetMin(heap);

  auto iter = tmp->child_ptr;
  auto tmp_rank = tmp->rank;
  while (iter != nullptr) {
    heap->InsertTree(tmp_rank - 1, iter);
    iter = iter->right_ptr;
  }
  heap->DeleteTree(tmp_rank, tmp);

  int i = 0, j = heap->max_rank;
  while (i < j) {
    if (heap->root_count[i].value >= 3)
      ;
  }

  return tmp;
}
}  // namespace thick