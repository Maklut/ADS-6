// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cstddef>

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& value) : data(value), next(nullptr) {}
  };

  Node* head_;

 public:
  TPQueue() : head_(nullptr) {}

  ~TPQueue() {
    while (!isEmpty()) {
      pop();
    }
  }

  void push(const T& item) {
    Node* newNode = new Node(item);

    if (isEmpty() || item.prior > head_->data.prior) {
      newNode->next = head_;
      head_ = newNode;
      return;
    }

    Node* current = head_;
    while (current->next != nullptr &&
           current->next->data.prior >= item.prior) {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }

  T pop() {
    if (isEmpty()) {
      return T{};
    }

    Node* temp = head_;
    T result = head_->data;
    head_ = head_->next;
    delete temp;
    return result;
  }

  bool isEmpty() const {
    return head_ == nullptr;
  }
};

#endif
