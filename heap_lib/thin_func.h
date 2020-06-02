#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "thin_heap.h"

ThinHeap* MakeHeap();

void Insert(ThinHeap* heap, Node* node);

Node* GetMin(ThinHeap* heap);

ThinHeap* Merge(ThinHeap* heap_f, ThinHeap* heap_s);
