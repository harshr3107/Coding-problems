/**
 * @param {number} n
 * @return {Function} counter
 */




var createCounter = function(n) {
   let a=0;
    return function() {
        
        
         let h =n+a;
         a++;
        return h;
         
       
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */