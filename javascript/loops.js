// For in statement -> Iter through the enumerate properties of an object
let nums = [1, 2, 3, 4, 5];
for (let i in nums) {
  console.log(nums[i]);
}

// For of statement -> Iter through the values of an iterable object
let nums2 = [1, 2, 3, 4, 5];
for (let i of nums) {
  console.log(i);
}

// Labeled statement
loop1: for (let i = 0; i < 3; i++) {
    loop2: for (let j = 0; j < 3; j++) {
        if (i === 1 && j === 1) {
            break loop1;
        }
        console.log(i, j);
    }
}

