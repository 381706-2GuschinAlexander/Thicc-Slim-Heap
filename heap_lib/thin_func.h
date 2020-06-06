#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "thin_heap.h"

namespace thin {
ThinHeap* MakeHeap();
void Insert(ThinHeap* heap, Node* node);
bool IsThin(Node* node);
Node* GetMin(ThinHeap* heap);
ThinHeap* Merge(ThinHeap* heap_f, ThinHeap* heap_s);
Node* ExtractMin(ThinHeap*& heap);
}  // namespace thin