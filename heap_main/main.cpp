#include <random>
#include <ctime>
#include <vector>
#include "thin_func.h"
#include "link.h"
#include "thick_func.h"
#include <iostream>



int main() { 
  auto a = thin::MakeHeap();

  for (size_t size = 2; size < 100; ++size) {
    for (int i = 0; i < size; i++) thin::Insert(a, new Node(i));
    //std::cout << size << std::endl;
    std::vector<int> vec(size, 0);
    for (size_t i = 0; i < size; i++) {
      auto tmp =  thin::ExtractMin(a);
      vec[i]= tmp->key;
      delete tmp;
      //std::cout << vec[i] << std::endl;
    }
    for (size_t i = 1; i < size; i++)
      if (vec[i] != vec[i - 1] + 1) return 2;
  }


  auto b = thick::MakeHeap();
  for (size_t size = 2; size < 100; ++size) {
    for (int i = 0; i < size; i++) 
      thick::Insert(b, new FatNode(i));
     std::cout << size << std::endl;
    std::vector<int> vec(size, 0);
    for (size_t i = 0; i < size; i++) {
      auto tmp = thick::ExtractMin(b);
      vec[i] = tmp->key;
      delete tmp;
      // std::cout << vec[i] << std::endl;
    }
    for (size_t i = 1; i < size; i++)
      if (vec[i] != vec[i - 1] + 1) return 2;
  }

  auto c = thick::MakeHeap();
  thick::Insert(c, new FatNode(24));
  thick::Insert(c, new FatNode(22354));
  thick::Insert(c, new FatNode(2234));
  thick::Insert(c, new FatNode(2234));
  auto tmp = thick::ExtractMin(c);
  thick::Insert(c, new FatNode(234));
  thick::Insert(c, new FatNode(274));
  tmp = thick::ExtractMin(c);

  return 0;
}