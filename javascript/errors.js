try {
    let x = y;
} catch (error) {
    console.error("An error occurred: " + error.message);
} finally {
    console.log("The 'try catch' is finished. Cleaning Up...");
}