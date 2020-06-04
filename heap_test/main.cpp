#include <random>
#include <ctime>
#include <vector>
#include "thin_func.h"
#include "link.h"
#include <iostream>

int main() { 
  auto a = MakeHeap();
  int size = 2;
  for (size; size < 250; ++size) {
    for (int i = 0; i < size; i++) Insert(a, new Node(i));
    std::cout << size << std::endl;
    std::vector<int> vec(size, 0);
    for (int i = 0; i < size; i++) {
      vec[i] = ExtractMin(a)->key;
      //std::cout << vec[i] << std::endl;
    }
    for (int i = 1; i < size; i++)
      if (vec[i] != vec[i - 1] + 1) throw;
  }

  //auto b = new Node(1);
  //b->right_ptr = new Node(2);
  //b->right_ptr->right_ptr = new Node(3);

  //auto b1 =  b++;
  //auto b2 = b++;
  //auto b3 = b++;

  return 0;
}