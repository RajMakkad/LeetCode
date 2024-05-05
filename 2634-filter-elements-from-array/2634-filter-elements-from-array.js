var filter = function(arr, fn) {
    return arr.filter((element, index) => fn(element, index)); 
};