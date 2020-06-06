#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "link.h"

struct RootCountItem {
  int64_t value;
  int64_t forward;
  FatNode* list_ptr;

  RootCountItem();
};

struct ThickHeap {
  std::vector<RootCountItem> root_count;
  std::vector<int64_t> count_violation;
  FatNode* pointer;
  int64_t max_rank;

  ThickHeap();
  void UpdateForwardPtr(int64_t i);
};
