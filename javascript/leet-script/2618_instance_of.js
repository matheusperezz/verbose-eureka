/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    while(obj!=null){
        if(obj.constructor === classFunction){
            return true;
        }
        obj = Object.getPrototypeOf(obj);
    }
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */

let test1 = checkIfInstanceOf(new Date(), Date); // true
let test2 = checkIfInstanceOf(5, Number); // true
let test3 = checkIfInstanceOf(5n, Object); // true

console.log(test3);