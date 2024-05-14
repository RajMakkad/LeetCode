var addTwoPromises = async function(promise1, promise2) {
    const num1 = await promise1;
    const num2 = await promise2;
    return new Promise((resolve, reject) => resolve(num1 + num2));
};
