"use strict";

// GENERATE RANDOM ARRAY
class RandomArray {
  constructor() {
    this.array = [];
  }
  generate() {
    for (let i = 0; i < 1000; i++) {
      const num = Math.floor(Math.random() * 501);
      this.array.push(num);
    }
  }
  suffle() {
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
}
const array1 = new RandomArray();
array1.generate();

//--------------------------------------------------------

// BUBBLE SORT
RandomArray.prototype.bubbleSort = function () {
  const { array } = this;
  // IMPLEMENTATION
  let temp,
    swap = false;
  do {
    swap = false;
    for (let i = 0; i < array.length; i++) {
      if (array[i] > array[i + 1]) {
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swap = true;
      }
    }
  } while (swap);

  this.display; // display sorted array
};
// array1.bubbleSort()

array1.suffle(); //re-suffle array

//--------------------------------------------------------

// INSERTION SORT
RandomArray.prototype.insertionSort = function () {
  const { array } = this;

  //IMPLEMENTATION
  for (let i = 1; i < array.length; i++) {
    for (let j = 0; j < i; j++) {
      if (array[i] < array[j]) {
        const temp = array.splice(i, 1);
        array.splice(j, 0, temp[0]); //temp is an array with lenght = 1
        break;
      }
    }
  }

  this.display; // display sorted array
};
// array1.insertionSort()

array1.suffle(); //re-suffle array

//--------------------------------------------------------

// MERGE SORT
RandomArray.prototype.mergeSort = function () {
  const { array } = this;

  // //IMPLEMENTATION
  const mergeSort = (arr) => {
    if (arr.length < 2) return arr;

    const mid = Math.floor(arr.length / 2);
    const left = arr.slice(0, mid);
    const right = arr.slice(mid);

    return merge(mergeSort(left), mergeSort(right));
  };
  const merge = (left, right) => {
    const result = [];

    while (left.length && right.length) {
      if (left[0] < right[0]) {
        result.push(left.shift());
      } else {
        result.push(right.shift());
      }
    }

    return result.concat(left, right);
  };

  this.array = mergeSort(array);
  this.display; // display sorted array
};
// array1.mergeSort()

array1.suffle(); //re-suffle array

//--------------------------------------------------------

// QUICK SORT

RandomArray.prototype.quickSort = function () {
  const { array } = this;

  const quickSort = (arr) => {
    if (arr.length < 2) return arr;

    const pivot = arr[arr.length - 1],
      left = [],
      right = [];

    for (let i = 0; i < arr.length - 1; i++) {
      arr[i] < pivot ? left.push(arr[i]) : right.push(arr[i]);
    }

    return quickSort(left).concat(pivot, quickSort(right));
  };

  this.array = quickSort(array);
  this.display; // display sorted array
};

array1.quickSort();
