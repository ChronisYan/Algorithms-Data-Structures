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
  get sort() {
    const { array } = this;

    const quickSort = (arr) => {
      if (arr.length < 2) return arr;

      const pivot = arr[arr.length - 1],
        left = [],
        right = [];

      for (let i = 0; i < arr.length - 1; i++) {
        arr[i] > pivot ? right.push(arr[i]) : left.push(arr[i]);
      }

      return [...quickSort(left), pivot, ...quickSort(right)];
    };
    this.array = quickSort(array);
    return this.array;
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
    let left = 0,
      right = array.length - 1;

    while (left <= right) {
      const mid = Math.floor((right + left) / 2);
      if (array[mid] === target) return mid;
      array[mid] > target ? (right = mid - 1) : (left = mid + 1);
    }

    return -1;
  }
  // BINARY SEARCH
  /*
    RANDOM 
    if (array[mid] === target) return mid;

    FIRST 
    if (array[mid] === target) {
      while (array[mid] === target) {
        mid--;
      }
      return mid+1;
    }

    LAST 
    if (array[mid] === target) {
      while (array[mid] === target) {
        mid++;
      }
      return mid-1;
    }
*/
}

//--------------------------------------------------------

const array1 = new RandomArray();
array1.generate;

array1.sort;

console.log(array1.linearSearch(400));
console.log(array1.binarySearch(400));
