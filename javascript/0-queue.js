const { performance } = require("perf_hooks");

/**************** NOTE ON DEQUEUE *********************
 dequeue is a slow process since it is basically an array shift()
 By implemented a queue in a way that the dequeue shifting happens only after a specific 
 amount of elements have been dequeued, we can speed up dequeueing
**************** NOTE ON DEQUEUE *********************/

class Queue {
  constructor(MEMORY_MAX = 100) {
    this.first = 0;
    this.last = -1;
    this.queue = [];
    this.MEMORY_MAX = MEMORY_MAX;
  }
  enqueue(data) {
    this.last++;
    this.queue[this.last] = data;
  }
  dequeue() {
    if (this.first > this.last) return null;

    const element = this.queue[this.first];
    this.first++;

    if (this.first === this.MEMORY_MAX) {
      for (let i = this.MEMORY_MAX; i <= this.last; i++) {
        this.queue[i - this.MEMORY_MAX] = this.queue[i];
      }
      this.last -= this.MEMORY_MAX;
      this.queue.length -= this.MEMORY_MAX;
      this.first = 0;
    }

    return element;
  }
  peek() {
    return this.queue[this.last];
  }
  isEmpty() {
    return this.last === -1;
  }
  get length() {
    return this.last + 1;
  }
}

class Queue101 {
  constructor() {
    this.queue = [];
  }

  get length() {
    return this.queue.length;
  }

  enqueue(item) {
    this.queue.push(item);
  }

  dequeue() {
    return this.queue.shift();
  }

  peek() {
    return this.queue[0];
  }

  isEmpty() {
    return this.length === 0;
  }
}

const queue1 = new Queue101();
const queue2 = new Queue();

const Ntest = 100000;
console.log("-----------NORMAL DEQUEUE------------");
const t1 = performance.now();
for (let i = 0; i < Ntest; i++) {
  queue1.enqueue(i);
}
for (let i = 0; i < Ntest; i++) {
  queue1.dequeue();
}
const t2 = performance.now();

console.log(`Time ${(t2 - t1) / 1000} seconds`);

console.log("-----------LAZY DEQUEUE------------");
const t3 = performance.now();
for (let i = 0; i < Ntest; i++) {
  queue2.enqueue(i);
}
for (let i = 0; i < Ntest; i++) {
  queue2.dequeue();
}
const t4 = performance.now();

console.log(`Time ${(t4 - t3) / 1000} seconds`);
