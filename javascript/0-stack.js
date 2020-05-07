class Stack {
  constructor() {
    this.stack = [];
  }
  push(data) {
    this.stack.push(data);
  }
  pop() {
    this.stack.pop();
  }
  viewStack() {
    let str = "";
    const { stack } = this;
    for (let i = stack.length - 1; i >= 0; i--) {
      str += stack[i] + "\n";
    }
    return str;
  }
}

const myStack = new Stack();

myStack.push(8);
myStack.push(10);
myStack.push(3);
myStack.push(5);

console.log(myStack.viewStack());

myStack.pop();
console.log(myStack.viewStack());

myStack.pop();
console.log(myStack.viewStack());
