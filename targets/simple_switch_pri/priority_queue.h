/* Copyright 2013-present Barefoot Networks, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Antonin Bas (antonin@barefootnetworks.com)
 *
 */

#ifndef _BM_PRIORITY_QUEUE_H_
#define _BM_PRIORITY_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>

/* TODO: implement non blocking behavior */

template <typename T, typename Comp>
class PriorityQueue {
public:
  enum WriteBehavior { WriteBlock, WriteReturn };
  enum ReadBehavior { ReadBlock, ReadReturn };

public:
 PriorityQueue()
   : capacity(1024), wb(WriteBlock), rb(ReadBlock) { }

  PriorityQueue(size_t capacity,
	WriteBehavior wb = WriteBlock, ReadBehavior rb = ReadBlock)
    : capacity(capacity), wb(wb), rb(rb) {}

  void push(const T &item) {
    std::unique_lock<std::mutex> lock(q_mutex);
    while(!is_not_full()) {
      if(wb == WriteReturn) return;
      q_not_full.wait(lock);
    }
    queue.push(item);
    lock.unlock();
    q_not_empty.notify_one();
  }

  void push(T &&item) {
    std::unique_lock<std::mutex> lock(q_mutex);
    while(!is_not_full()) {
      if(wb == WriteReturn) return;
      q_not_full.wait(lock);
    }
    queue.push(std::move(item));
    lock.unlock();
    q_not_empty.notify_one();
  }

  void pop(T* pItem) {
    std::unique_lock<std::mutex> lock(q_mutex);
    while(!is_not_empty())
      q_not_empty.wait(lock);
    // TODO: improve / document this
    // http://stackoverflow.com/questions/20149471/move-out-element-of-std-priority-queue-in-c11
    *pItem = std::move(const_cast<T &>(queue.top()));
    queue.pop();
    lock.unlock();
    q_not_full.notify_one();
  }

  size_t size() {
    std::unique_lock<std::mutex> lock(q_mutex);
    return queue.size();
  }

  void set_capacity(const size_t c) {
    // change capacity but does not discard elements
    std::unique_lock<std::mutex> lock(q_mutex);
    capacity = c;
  }

  PriorityQueue(const PriorityQueue &) = delete;
  PriorityQueue &operator =(const PriorityQueue &) = delete;

private:
  bool is_not_empty() const { return queue.size() > 0; }
  bool is_not_full() const { return queue.size() < capacity; }

  size_t capacity;
  std::priority_queue<T, std::vector<T>, Comp> queue;
  WriteBehavior wb;
  ReadBehavior rb;

  std::mutex q_mutex;
  std::condition_variable q_not_empty;
  std::condition_variable q_not_full;
};

#endif
