var once = function(fn) {
    let hasBeenCalled = false;
    let ans;
    return function(...args){
       if(!hasBeenCalled){
           ans = fn(...args);
           hasBeenCalled = true;
           return ans;
       } else {
           return undefined;
        }
    }
};
