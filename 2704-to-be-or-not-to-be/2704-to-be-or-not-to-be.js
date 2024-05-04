var expect = function(val) {
    const toBe = (num) => {
        if(val === num)
            return true
        throw "Not Equal"
    }
    
    const notToBe = (num) => {
        if(val !== num)
            return true
        throw "Equal"
    }
    
    return {
        toBe, 
        notToBe
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */