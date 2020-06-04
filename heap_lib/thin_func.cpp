#include "thin_func.h"

ThinHeap* MakeHeap() { return new ThinHeap; }

void Insert(ThinHeap* heap, Node* node) {
  if (node->rank > heap->max_rank)
    heap->max_rank = node->rank;
  if (heap->start == nullptr) {
    heap->start = node;
    heap->end = node;
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

bool IsThin(Node* node) {
  if (node->rank == 0) return false;
  if (node->rank == 1)
    return node->child_ptr == nullptr;
  else
    return node->child_ptr->rank + 2 != node->rank;
}

Node* GetMin(ThinHeap* heap) { return heap->start; }

ThinHeap* Merge(ThinHeap* heap_f, ThinHeap* heap_s) {
  if (heap_f->start == nullptr) return heap_s;
  if (heap_s->start == nullptr) return heap_f;
  if (heap_f->start->key < heap_s->start->key) {
    heap_f->end->right_ptr = heap_s->start;
    heap_f->end = heap_s->end;
    delete heap_s;
    return heap_f;
  } else {
    heap_s->end->right_ptr = heap_f->start;
    heap_s->end = heap_f->end;
    delete heap_f;
    return heap_s;
  }
}

Node* ExtractMin(ThinHeap* & heap) {
  Node* tmp = heap->start;
  if (tmp == nullptr) return nullptr;
  heap->start = heap->start->right_ptr;
  if (heap->start == nullptr) heap->end = nullptr;

  Node* iter = tmp->child_ptr;
  while (iter != nullptr) {
    if (IsThin(iter)) iter->rank -= 1;
    iter->left_ptr = nullptr;
    Node* next = iter->right_ptr;
    iter->right_ptr = nullptr;
    Insert(heap, iter);
    iter = next;
  }

  iter = heap->start;

  int64_t max_rank = heap->max_rank;
  auto next = heap->start;
  std::vector<Node*> vec_ptr(max_rank + 1);

  iter = heap->start;
  if (iter != nullptr)
    next = iter->right_ptr;
  else
    next = nullptr;
  while (iter != nullptr) {
    Node* next = iter->right_ptr;
    while (vec_ptr[iter->rank] != nullptr) {
      
      if (vec_ptr[iter->rank]->key < iter->key)
        std::swap(vec_ptr[iter->rank], iter);
      vec_ptr[iter->rank]->right_ptr = iter->child_ptr;
      if (iter->child_ptr != nullptr)
        iter->child_ptr->left_ptr = vec_ptr[iter->rank];
      vec_ptr[iter->rank]->left_ptr = iter;
      iter->child_ptr = vec_ptr[iter->rank];
      vec_ptr[iter->rank] = nullptr;
      iter->rank += 1;
      if (iter->rank > max_rank) {
        vec_ptr.push_back(nullptr);
        max_rank = iter->rank;
      }
    }
    
    vec_ptr[iter->rank] = iter;
    vec_ptr[iter->rank]->right_ptr = nullptr;
    iter = next;
  }

  auto tmp_ptr = heap;
  heap = MakeHeap();
  delete tmp_ptr;
  for (size_t i = 0; i < vec_ptr.size(); i++) {
    if (vec_ptr[i] != nullptr) {
      Insert(heap, vec_ptr[i]);
    }
  }
  return tmp;
}
