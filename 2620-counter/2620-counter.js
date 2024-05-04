
let count = 0;
var createCounter = function(n) {
    count = n;
    return () => count++;
    
};
