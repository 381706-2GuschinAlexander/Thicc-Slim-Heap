#include "thin_func.h"

ThinHeap* MakeHeap() { return new ThinHeap; }

void Insert(ThinHeap* heap, Node* node) {
  if (heap->start == nullptr) {
    heap->start = node;
  } else {
    if (node->key < heap->start->key) {
      node->right_ptr = heap->start;
      heap->start = node;
    } else {
      heap->end->right_ptr = node;
      heap->end = node;
    }
  }
}

Node* GetMin(ThinHeap* heap) { return heap->start; }

ThinHeap* Merge(ThinHeap* heap_f, ThinHeap* heap_s) {
  if (heap_f->start == nullptr) return heap_s;
  if (heap_s->start == nullptr) return heap_f;
  if (heap_f->start->key < heap_s->start->key) {
    heap_f->end->right_ptr = heap_s->start;
    heap_f->end = heap_s->end;
  } else {
    heap_s->end->right_ptr = heap_f->start;
    heap_s->end = heap_f->end;
  }
  return nullptr;
}
