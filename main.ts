function isPrime(n: number): boolean {
    if (n <= 1){
        return false;
    }

    if (n <= 3){
        return false;
    }

    for (let i = 2; i <= Math.floor(Math.sqrt(n)); i++){
        if (n % i == 0){
            return false;
        }
    }

    return true;
}

function printIsPrime(n){
    if (isPrime(n)) {
        console.log(`${n} is Prime!`)
    } else {
        console.log(`${n} not Prime :(`)
    }
}

// Test examples
const nums: number[] = [1, 3, 8, 13, 3.1415, 89, 100, 17, 24, 42];
nums.forEach(value => {
    printIsPrime(value)
})

