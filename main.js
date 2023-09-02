function isPrime(n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return false;
    }
    for (var i = 2; i <= Math.floor(Math.sqrt(n)); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
function printIsPrime(n) {
    if (isPrime(n)) {
        console.log("".concat(n, " is Prime!"));
    }
    else {
        console.log("".concat(n, " not Prime :("));
    }
}
// Test examples
var nums = [1, 3, 8, 13, 3.1415, 89, 100, 17, 24, 42];
nums.forEach(function (value) {
    printIsPrime(value);
});
