// Fractional Knapsack Problem -- Maximization Problem
const items = [
  "apple",
  "orange",
  "pineapple",
  "peach",
  "mango",
  "coconut",
  "strawberry",
  "apricot",
  "pear",
  "blueberry"
];
const value = [10, 5, 15, 7, 6, 18, 3, 8, 14, 17];
const weight = [2, 3, 5, 7, 1, 4, 3, 2, 6, 3];

buildCatalog = (name, value, weight) => {
  const result = [];
  if (name.length === value.length && value.length === weight.length) {
    for (let i = 0; i < name.length; i++) {
      result.push([name[i], value[i], weight[i]]);
    }
  }
  return result;
};

catalog = buildCatalog(items, value, weight);

// sortingFun will determined what is the "best" item we want to include first
const fractionalGreedy = (array, maxWeight, sortingFun) => {
  itemsCopy = [...array];
  // sort the catalog on value/weight for optimal picking
  itemsCopy.sort(sortingFun);
  Finalresult = [];
  profit = 0;
  const quantity = [];
  let currentWeight = 0;

  // loop over the catalog and push the amount of each item we going to take in a quantity array
  for (let i = 0; i < itemsCopy.length; i++) {
    if (
      currentWeight < maxWeight &&
      itemsCopy[i][2] <= maxWeight - currentWeight
    ) {
      currentWeight += itemsCopy[i][2];
      quantity.push(1);
    } else if (
      currentWeight < maxWeight &&
      itemsCopy[i][2] > maxWeight - currentWeight
    ) {
      quantity.push((maxWeight - currentWeight) / itemsCopy[i][2]);
      currentWeight += maxWeight - currentWeight;
    } else {
      quantity.push(0);
    }
  }
  //based on the quantity array calculate the amount of each item we took & the total profit quantity*value
  for (let i = 0; i < quantity.length; i++) {
    if (quantity[i] !== 0) {
      Finalresult.push([itemsCopy[i][0], itemsCopy[i][2] * quantity[i]]);
      profit += itemsCopy[i][1] * quantity[i];
    }
  }
  Finalresult.push(["Total Profit", profit]);
  return Finalresult;
};

console.log(fractionalGreedy(catalog, 15, (a, b) => b[1] / b[2] - a[1] / a[2]));

//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################

// Job Sequencing with dead lines -- Maximization problem
// You have a list of job offers with their coresponding value, and max time they are willing to wait
// If you can do only one job at the time what is the maximum profit you can achieve?

const JobOffer = function(name, value, item) {
  this.name = name;
  this.profit = value;
  this.deadline = item;
};

const jobs = ["j1", "j2", "j3", "j4", "j5", "j6", "j7"];
const profit = [25, 12, 35, 30, 5, 20, 15];
const deadline = [1, 1, 3, 4, 2, 1, 3];

const buildCatalog = (name, value, time) => {
  const catalog = [];
  if (name.length === value.length && value.length === time.length) {
    for (let i = 0; i < name.length; i++) {
      const job = new JobOffer(name[i], value[i], time[i]);
      catalog.push(job);
    }
  }
  return catalog;
};

const myJobs = buildCatalog(jobs, profit, deadline);

// Greedy Algorithm Implementation
const greedyAlgo = (items, timeMax) => {
  const itemsCopy = [...items];
  const slots = Array(timeMax).fill(0); // create an array with empty slots with length === max deadline
  // sort items based on profit
  itemsCopy.sort((a, b) => b.profit - a.profit);
  let counter = 0;
  // loop over items if there are no more open slots break
  for (let i = 0; i < items.length; i++) {
    if (counter === timeMax) {
      break;
    }
    // place the highest paying jobs to their max deadline if occupied place them any time earlier
    let availableSlot = itemsCopy[i].deadline - 1;
    while (availableSlot >= 0) {
      if (slots[availableSlot] === 0) {
        slots[availableSlot] = itemsCopy[i];
        counter++;
        break;
      } else {
        availableSlot--;
      }
    }
  }
  return slots;
};

const result = greedyAlgo(myJobs, Math.max(...deadline));
console.log(result);


//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################
//####################################################################################

// 0-1 Knapsack Problem

const names = [
  "wine",
  "beer",
  "pizza",
  "burger",
  "fries",
  "cola",
  "apple",
  "donut",
  "cake"
];
const values = [89, 90, 95, 100, 90, 79, 50, 10];
const calories = [123, 154, 258, 354, 365, 150, 95, 195];
