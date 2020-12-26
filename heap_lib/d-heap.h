#pragma once
#include <stdint.h>
#include <new>
#include <algorithm>
#include <iostream>

class d_heap {
 protected:
    uint8_t d;
    size_t size;
    size_t count;
    size_t* keys;

 public:
    d_heap();
    d_heap(const uint8_t d, const size_t size);
    d_heap(const d_heap& copy);
    ~d_heap();
    uint8_t getD() const;
    size_t getCount() const;
    size_t getSize() const;
    size_t operator[](const size_t iter);
    size_t minChild(const size_t iter);
    size_t firstChild(const size_t iter);
    size_t lastChild(const size_t iter);
    size_t father(const size_t iter);
    size_t getInd(const size_t key);
    void ascent(const size_t iter);
    void dive(const size_t iter);
    void insert(const size_t key);
    void del(const size_t iter);
};

