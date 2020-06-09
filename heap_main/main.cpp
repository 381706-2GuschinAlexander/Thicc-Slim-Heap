#include <chrono>
#include <iostream>
#include <vector>
#include "link.h"
#include "thick_func.h"
#include "thin_func.h"
#include "d-heap.h"


// 200'000'000 + pow(i,2)*i
int main() {
  size_t max_size = 50'000'000;
  std::cout << "size: " << max_size << std::endl;
  std::vector<Node *> vec(max_size, nullptr);
  for (int i = 0; i < max_size; i++)
    vec[i] = new Node(2 * max_size + pow(-1, i) * i);
  auto a = thin::MakeHeap();
  auto start = std::chrono::system_clock::now();
  for (int i = 0; i < max_size; i++)
    thin::Insert(a, vec[i]);

  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < max_size; i++) {
    thin::ExtractMin(a);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> time(end - start);
  std::cout << "thin heap required time: " << time.count() / 1000 << std::endl;

  for (int i = 0; i < max_size; i++) delete vec[i];
  vec.clear();
  //
  //
  //
  //
  auto b = thick::MakeHeap();
  std::vector<FatNode *> vec2(max_size, nullptr);
  for (int i = 0; i < max_size; i++)
    vec2[i] = new FatNode(max_size + pow(-1, i) * i);
  start = std::chrono::system_clock::now();
  for (int i = 0; i < max_size; i++)
    thick::Insert(b, vec2[i]);

  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < max_size; i++) {
    thick::ExtractMin(b);
  }
  end = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> time2(end - start);
  std::cout << "thick heap required time: " << time2.count() / 1000 << std::endl;

  for (int i = 0; i < max_size; i++) delete vec2[i];
  vec2.clear();
  //
  //
  //
  //
  d_heap heap(4, max_size);
  std::vector<int> vec3(max_size);
  for (int i = 0; i < max_size; i++)
    vec3[i] = max_size + pow(-1, i) * i;
  start = std::chrono::system_clock::now();

  for (int i = 0; i < max_size; i++) heap.insert(vec3[i]);

  start = std::chrono::system_clock::now();
  for (size_t i = 0; i < max_size; i++) {
    heap.del(0);
  }

  end = std::chrono::system_clock::now();
  std::chrono::duration<double, std::milli> time3(end - start);
  std::cout << "d-heap required time: " << time3.count() / 1000 << std::endl;

  vec3.clear();

  return 0;
}