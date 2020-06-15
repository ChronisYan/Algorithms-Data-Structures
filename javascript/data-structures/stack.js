class Stack {
  constructor() {
    this.top = -1;
    this.stack = [];
  }
  push(data) {
    this.top++;
    this.stack[this.top] = data;
  }
  pop() {
    if (this.top < 0) return "Underflow";
    const topElement = this.stack[this.top];
    this.top--;
    this.stack.length--;
    return topElement;
  }
  peek() {
    return this.stack[this.top];
  }
  isEmtpy() {
    return this.top === -1;
  }
  get length() {
    return this.top + 1;
  }
}

const myStack = new Stack();

myStack.push(8);
myStack.push(10);
myStack.push(3);
myStack.push(5);
