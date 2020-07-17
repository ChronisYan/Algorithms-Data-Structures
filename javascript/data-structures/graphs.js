// DATA
const airports = 'PHX BKK OKC JFK LAX MEX EZE HEL LOS LAP LIM'.split(' ');

const routes = [
	['PHX', 'LAX'],
	['PHX', 'JFK'],
	['JFK', 'OKC'],
	['JFK', 'HEL'],
	['JFK', 'LOS'],
	['MEX', 'LAX'],
	['MEX', 'BKK'],
	['MEX', 'LIM'],
	['MEX', 'EZE'],
	['LIM', 'BKK']
];

// GRAPH
const adjecencyList = new Map();

const addNode = (airport) => {
	adjecencyList.set(airport, []);
}

// Add edge (undirected)
const addEdge = (origin, destination) => {
	adjecencyList.get(origin).push(destination);
	adjecencyList.get(destination).push(origin);
}

// Create Graph
airports.forEach(addNode);
routes.forEach(route => addEdge(...route));

// SEARCH / TRAVERSAL 	

// 1. Breadth First Search (BFS)
console.log('--------BFS--------')
const bfs = (start, target) =>{
	const visited = new Set();
	const queue = [start];

	while(queue.length > 0){
		const airport = queue.shift();
		const destinations = adjecencyList.get(airport);

		destinations.forEach(destination =>{

			if(destination === target){
				console.log(`found ${target}!`);
			}	

			if(!visited.has(destination)){
				visited.add(destination);
				queue.push(destination);
				console.log(destination);
			}
		})
	}
} 

bfs('PHX', 'BKK');

// 2. Depth  First Search (DFS)
console.log('--------DFS--------')
const dfs = (start, target, visited = new Set()) => {
	console.log(start);

	visited.add(start);

	const destinations = adjecencyList.get(start);

	for (const destination of destinations){
		if(destination === target){
			console.log(`Found ${target}`);
			return; 		
		}

		if(!visited.has(destination)){
			dfs(destination, target, visited);	
		}
	}
}

dfs('PHX', 'BKK');
