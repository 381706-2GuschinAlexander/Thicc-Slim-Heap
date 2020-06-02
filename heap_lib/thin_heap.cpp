#include "link.h"
#include "thin_heap.h"

ThinHeap::ThinHeap() {
  start = nullptr;
  end = nullptr;
}

ThinHeap* ThinHeap::MakeHeap() { return new ThinHeap(); }
