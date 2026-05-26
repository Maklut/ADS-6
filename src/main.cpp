// Copyright 2022 NNTU-CS
#include <iostream>
#include "tpqueue.h"

int main() {
  TPQueue<SYM> pqueue;

  std::cout << "=== Testing Priority Queue ===\n\n";

  pqueue.push(SYM{'a', 4});
  std::cout << "Pushed: 'a' with priority 4\n";

  pqueue.push(SYM{'b', 7});
  std::cout << "Pushed: 'b' with priority 7\n";

  pqueue.push(SYM{'c', 2});
  std::cout << "Pushed: 'c' with priority 2\n";

  pqueue.push(SYM{'d', 9});
  std::cout << "Pushed: 'd' with priority 9\n";

  pqueue.push(SYM{'e', 5});
  std::cout << "Pushed: 'e' with priority 5\n\n";

  std::cout << "Extracting elements (should be in priority order):\n";

  while (!pqueue.isEmpty()) {
    SYM item = pqueue.pop();
    std::cout << "Popped: '" << item.ch << "' with priority "
              << item.prior << "\n";
  }

  std::cout << "\n=== Test completed ===\n";

  return 0;
}
