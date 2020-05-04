#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

template <class T>
class CoreNode {
 protected:
  int64_t key;
  CoreNode* parent;
  CoreNode* left;
  CoreNode* right;
  CoreNode* child;

 public:
  CoreNode();
};


