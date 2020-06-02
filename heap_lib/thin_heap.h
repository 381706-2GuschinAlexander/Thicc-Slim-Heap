#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "link.h"

class ThinHeap {
 protected:
  Node* start;
  Node* end;

 public:
  ThinHeap();

  ThinHeap* MakeHeap();

  void Test();
};
