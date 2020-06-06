#include <random>
#include <ctime>
#include <vector>
#include "thin_func.h"
#include "link.h"
#include <iostream>



int main() { 
  auto a = MakeHeap();
  size_t size = 2;
  for (size; size < 10000; ++size) {
    for (int i = 0; i < size; i++) Insert(a, new Node(i));
    //std::cout << size << std::endl;
    std::vector<int> vec(size, 0);
    for (size_t i = 0; i < size; i++) {
      auto tmp =  ExtractMin(a);
      vec[i]= tmp->key;
      delete tmp;
      //std::cout << vec[i] << std::endl;
    }
    for (size_t i = 1; i < size; i++)
      if (vec[i] != vec[i - 1] + 1) return 2;
  }


  return 0;
}