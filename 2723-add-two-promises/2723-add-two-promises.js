var addTwoPromises = async function(promise1, promise2) {
    const [num1, num2] = await Promise.all([promise1, promise2]);
    return num1 + num2;
};
