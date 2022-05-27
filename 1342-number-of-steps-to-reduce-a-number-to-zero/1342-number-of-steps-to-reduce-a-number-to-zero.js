/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function(num) {
    let ans = 0;
    
    while (num > 0) {
        if (num & 1) {
            num--;
        }
        else {
            num >>= 1;
        }
        
        ans++;
    }
    
    return ans;
};

/*
    14
    7
    6
    3
    2
    1
    0
    
    
*/