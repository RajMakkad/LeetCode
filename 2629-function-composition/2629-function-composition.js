
var compose = function(functions) {
    
    return function(x) {
        const len = functions.length;
        let ans = x;
        for(let i = len - 1; i >= 0;i--){
            ans = functions[i](ans);
        }
        
        return ans;
    }
};
