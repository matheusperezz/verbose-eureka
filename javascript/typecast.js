let num = 123;
let bool = true;
let obj = { key: "value" };

let numStr = String(num);
let boolStr = String(bool);
let objStr = String(obj);

console.log(numStr);
console.log(boolStr);
console.log(objStr);

let numToStr = num.toString();
let boolToStr = bool.toString();

let intNum = parseInt(numStr);

// For arrays
let str = "hello";
let set = new Set([1, 2, 3, 3])

let arrFromStr = Array.from(str);
let arrFromSet = Array.from(set);

console.log(arrFromStr)
console.log(arrFromSet)
