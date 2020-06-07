#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "thick_heap.h"

namespace thick {
ThickHeap* MakeHeap();
void Insert(ThickHeap* heap, FatNode* node);
FatNode* GetMin(ThickHeap* heap);
ThickHeap* Merge(ThickHeap* heap_f, ThickHeap* heap_s);
FatNode* ExtractMin(ThickHeap*& heap);
}  // namespace thick