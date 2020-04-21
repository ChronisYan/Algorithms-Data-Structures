class MyArray {
  constructor() {
    this.length = 0;
    this.data = {};
  }
  get(index) {
    return this.data[index];
  }
  push(item) {
    this.data[this.length] = item;
    this.length++;
    return this.data;
  }
  pop() {
    const item = this.data[this.length - 1];
    delete this.data[this.length - 1];
    this.length--;
    return item;
  }
  deleteAt(index) {
    const item = this.data[index];
    this.deleteShift(index);
    return item;
  }
  deleteShift(index) {
    for (let i = index; i < this.length - 1; i++) {
      this.data[i] = this.data[i + 1];
    }
    delete this.data[this.length - 1];
    this.length--;
  }
}

const arr = new MyArray();

arr.push("suga");
arr.push("dog");
arr.push("cooool");
console.log(arr.get(2));
arr.pop();
arr.push("oh");
arr.push("hi");
arr.push("Mark!");
console.log(arr.data, arr.length);
arr.deleteAt(2);
console.log(arr.data, arr.length);
