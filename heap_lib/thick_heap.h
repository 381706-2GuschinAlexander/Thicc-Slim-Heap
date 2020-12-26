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
  FatNode* min_key_ptr;
  int64_t max_rank;

  ThickHeap();
  void UpdateForwardPtr(int64_t i);
  void InsertTree(int i, FatNode* p);
  void DeleteTree(int i, FatNode* p);
  FatNode* fastening(FatNode* p1, FatNode* p2, FatNode* p3);
  void rmFixRootCount(int i);
  void rmIncCount(int i, FatNode* node);
};
