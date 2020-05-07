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
  shift() {
    const item = this.data[0];
    this._deleteShift(0);
    return item;
  }
  unshift(data) {
    this._insertShift(0, data);
    return this.data;
  }
  deleteAt(index) {
    const item = this.data[index];
    this._deleteShift(index);
    return item;
  }
  insertAt(index, data) {
    this._insertShift(index, data);
    return this.data;
  }
  // HELPER METHODS
  _deleteShift(index) {
    for (let i = index; i < this.length; i++) {
      this.data[i] = this.data[i + 1];
    }
    delete this.data[this.length - 1];
    this.length--;
  }
  _insertShift(index, data) {
    for (let i = this.length - 1; i >= index; i--) {
      this.data[i + 1] = this.data[i];
    }
    this.data[index] = data;
    this.length++;
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
console.log(arr.data);
arr.insertAt(2, "Obliteration!");
console.log(arr.data);

let cool = arr.shift();
arr.unshift("Elise");
console.log(arr.data);
