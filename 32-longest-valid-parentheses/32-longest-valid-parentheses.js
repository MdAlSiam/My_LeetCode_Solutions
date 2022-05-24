/**
 * @param {string} s
 * @return {number}
 */

var longestValidParentheses = function(str) {
    const stack = [-1];
    
    let max = 0;
    
    for (let i = 0; i < str.length; i++) {
        let top = stack[stack.length - 1];
        if (str[top] === '(' && str[i] === ')') {
            stack.pop();
            let prevTop = stack[stack.length - 1]
            max = Math.max(max, i-prevTop);
        }
        else {
            stack.push(i);
        }
    }
    
    return max;
};