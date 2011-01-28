#ifndef RCD_BOUNDEDQUEUE_H
#define RCD_BOUNDEDQUEUE_H

#include <cstddef>
#include <queue>
#include <stdexcept>

namespace rcd {

/*
 * This is a queue that enforces a maximum number of elements.
 */
template <typename T> class BoundedQueue {
     typedef typename std::queue<T>::size_type size_type;
public:
     BoundedQueue<T>(size_type max) : max_elems(max) { }

     const T& back() const {
          return b_queue.back();
     }

     T& back() {
          return b_queue.back();
     }

     const T& front() const {
          return b_queue.front();
     }

     T& front() {
          return b_queue.front();
     }

     bool empty() const {
          return b_queue.empty();
     }

     bool full() const {
          return b_queue.size() >= max_elems;
     }

     size_type size() const {
          return b_queue.size();
     }
     size_type get_max_elems() const {
          return max_elems;
     }

     void pop() {
          b_queue.pop();
     }

     void push(const T& item) {
          if (full()) {
               throw std::out_of_range("Queue is full.");
          } else {
               b_queue.push(item);
          }
     }

private:
     size_type max_elems;
     std::queue<T> b_queue;
};

}

#endif /* RCD_BOUNDEDQUEUE_H */

