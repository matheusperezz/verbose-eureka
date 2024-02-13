/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    return new Promise( resolver => {
        setTimeout(() => {
            resolver(millis);
        }, millis)
    });
}

/**
 * Performance function
 */
async function sleepPerformance(millis) {
    return new Promise((resolve) => 
        setTimeout(resolve, millis)
    )
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */

let t = Date.now();
sleep(100).then(() => {
  console.log(Date.now() - t); // 100
});
console.log("Funcionou");