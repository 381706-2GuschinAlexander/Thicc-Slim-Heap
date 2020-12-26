#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "link.h"

struct ThinHeap {
  Node* start;
  Node* end;

  int64_t max_rank;
  ThinHeap();
};
