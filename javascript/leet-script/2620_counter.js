/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let s = -1;
    return function() {
        s++;
        return n+s
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

const counter = createCounter(10);
console.log(counter()) // 10
console.log(counter()) // 11
console.log(counter()) // 12
