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
  get copy() {
    const { array } = this;
    return array.slice();
  }
  get display() {
    console.log(this.array);
  }

  //#######################################################
  // BUBBLE SORT
  bubbleSort() {
    const { array } = this;
    let swap = false,
      unsorted = array.length;

    do {
      swap = false;
      for (let i = 0; i < unsorted; i++) {
        if (array[i] > array[i + 1]) {
          const temp = array[i];
          array[i] = array[i + 1];
          array[i + 1] = temp;
          swap = true;
        }
      }
      unsorted--;
    } while (swap);
  }

  //#######################################################
  //INSERTION SORT
  insertionSort() {
    const { array } = this;

    for (let i = 1; i < array.length; i++) {
      let cur = array[i],
        j = i - 1;
      while (j >= 0 && cur < array[j]) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = cur;
    }
  }

  //#######################################################
  //SELECTION SORT
  selectionSort() {
    const { array } = this;
    let unsorted = 0;

    while (unsorted < array.length) {
      let min = unsorted;
      for (let i = unsorted; i < array.length; i++) {
        if (array[i] < array[min]) min = i;
      }
      if (array[min] !== array[unsorted]) {
        const temp = array[unsorted];
        array[unsorted] = array[min];
        array[min] = temp;
      }
      unsorted++;
    }
  }
  //#######################################################
  // MERGE SORT
  mergeSort() {
    const { array } = this;

    const mergeSort = (arr) => {
      if (arr.length < 2) return arr;

      const mid = Math.floor(arr.length / 2);
      const left = arr.slice(0, mid);
      const right = arr.slice(mid);

      return merge(mergeSort(left), mergeSort(right));
    };
    const merge = (left, right) => {
      const result = [];
      let i = 0,
        j = 0;
      while (i < left.length && j < right.length) {
        if (left[i] < right[j]) {
          result.push(left[i]);
          i++;
        } else {
          result.push(right[j]);
          j++;
        }
      }

      return result.concat(left.slice(i), right.slice(j));
    };
    this.array = mergeSort(array);
  }
  //#######################################################
  // QUICK SORT
  quickSort() {
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
  }
}

//-------------------------------------------

const myArray = new RandomArray();
myArray.generate;

myArray.mergeSort();
myArray.display;

// // TEST
// myArray.mergeSort();
// const arr1 = myArray.copy;
// myArray.suffle;
// myArray.quickSort();
// const arr2 = myArray.copy;

// console.log(arr1.every((item, index) => item === arr2[index]));
