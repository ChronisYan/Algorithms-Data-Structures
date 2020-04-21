"use strict";

// GENERATE RANDOM ARRAY
class RandomArray {
  constructor() {
    this.array = [];
  }
  get generate() {
    for (let i = 0; i < 1000; i++) {
      const num = Math.floor(Math.random() * 501);
      this.array.push(num);
    }
  }
  get suffle() {
    const { array } = this;
    let newPos, temp;
    for (let i = array.length - 1; i > 0; i--) {
      newPos = Math.floor(Math.random() * (i + 1));
      temp = array[i];
      array[i] = array[newPos];
      array[newPos] = temp;
    }
  }
  get display() {
    console.log(this.array);
  }
  //##########################################################
  // LINEAR SEARCH
  linearSearch(target) {
    if (target === undefined) return -1;

    const { array } = this;

    for (let i = 0; i < array.length; i++) {
      if (array[i] === target) return i;
    }

    return -1;
  }
  //##########################################################
  // BINARY SEARCH
  binarySearch(target) {
    if (target === undefined) return -1;

    const { array } = this;
  }
}

//--------------------------------------------------------

const array1 = new RandomArray();
array1.generate;

console.log(array1.linearSearch(5));
