function checkSledJump(heights) {
    let i=0;
    let up=false
    let down=false;
    while (i < heights.length && heights[i] < heights[i+1]) {
        up = true;
        i+=1;
    }
    while (i < heights.length && heights[i] > heights[i+1]) {
        down = true;
        i+=1;
    }
    return up && down && i == heights.length - 1;
}

console.log(checkSledJump([1, 2, 3, 2, 1])); // true: sube y baja de forma estricta
console.log(checkSledJump([0, 1, 0])); // -> true: sube y baja de forma estricta
console.log(checkSledJump([0, 3, 2, 1])); // -> true: sube y baja de forma estricta
console.log(checkSledJump([0, 1000, 1])); // -> true: sube y baja de forma estricta
console.log(checkSledJump([2, 4, 4, 6, 2])); // false: no sube de forma estricta
console.log(checkSledJump([1, 2, 3])); // false: sólo sube
console.log(checkSledJump([1, 2, 3, 2, 1, 2, 3])); // false: sube y baja y sube... ¡no vale!