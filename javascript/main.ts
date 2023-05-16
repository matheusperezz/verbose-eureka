function isPrime(input: number): Boolean{

    if (input <= 1 ){
        return false;
    }

    if (input > 1 && input <= 3){
        return true;
    }

    for (let i = 2; i < input; i++){
        // não existe numeros divisores maiores que a metade de um número
        if (i > input/2){
            return true;
        }

        // verificando se há divisores
        if (input%i == 0){
            return false;
        }
    }

    return true;

}

let numberArrays: number[] = []


for (let i = 0; i < 10000000; i++){
    numberArrays.push(i);
}

let primeArray: number[] = numberArrays.filter((num) => isPrime(num));

let allPrimesSum = 0;

primeArray.forEach((v) => {
    allPrimesSum += v
})