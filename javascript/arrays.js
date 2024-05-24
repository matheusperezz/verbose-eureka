let fruits = ['Apple', 'Mango', 'Banana'];

// Lenght
console.log(fruits.length); // 3

// Iterating over an array
for (let i = 0; i < fruits.length; i++) {
    console.log(fruits[i]);
}

// Iterating over an array using forEach
fruits.forEach(fruit => {
    console.log(fruit);
});

// Shift and Unshift
fruits.shift(); // Removes the first element and returns it
console.log(fruits); // ['Mango', 'Banana']

// Map -> This method returns a new array of the returned value from executing a function on every array item. 
const numbers = [1, 2, 3, 4, 5];
const squaredNumbers = numbers.map(number => number * number);
console.log(squaredNumbers); // [1, 4, 9, 16, 25]

// Filter -> This method returns a new array containing the items for which the function returned true. 
const evenNumbers = numbers.filter(number => number % 2 === 0);
console.log(evenNumbers); // [2, 4]

// Typed array -> Cannot add new elements using methods
let typedNums = new Uint16Array([1, 2, 3]);

// Reduce -> Reduce to a unique value like the example bellow
const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
console.log(sum); // 15