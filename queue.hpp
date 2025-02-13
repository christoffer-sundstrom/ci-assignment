#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

template <typename T> class circular_queue_t {
  struct node_t {
    T value;
    node_t* next;
  };

  node_t* head = nullptr;
  node_t* tail = nullptr;
  size_t count{0};
  size_t size;

public:
  circular_queue_t(const circular_queue_t&) = delete;
  circular_queue_t& operator=(const circular_queue_t&) = delete;
  circular_queue_t(size_t _size) : size(_size) {}
  circular_queue_t(circular_queue_t&& that) noexcept;
  circular_queue_t& operator=(circular_queue_t&& that) noexcept {
    if (this != &that) {
      clear();
      head = that.head;
      tail = that.tail;
      count = that.count;
      that.head = nullptr;
      that.tail = nullptr;
      that.count = 0;
    }
    return *this;
  }

  bool enqueue(const T& item) { return true; }
  bool dequeue(T& item) { return true; }
  size_t get_size(void) const { return size; }
  size_t get_count(void) const { return count; }
  void clear(void) {
    while (head) {
      node_t* temp = head;
      head = head->next;
      delete temp;
    }
    tail = nullptr;
    count = 0;
  }
  ~circular_queue_t() { clear(); }
};

#endif // QUEUE_H
