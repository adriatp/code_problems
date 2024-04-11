function getMinJump(obstacles) {
    let i = 1;
    while (true) {
      let k = 0;
      while (k < obstacles.length && obstacles[k] % i != 0)
          k+=1;
      if (k == obstacles.length) 
          return i;
      i += 1;
    } 
}

const obstacles = [2, 4, 6, 8, 10]
console.log(getMinJump(obstacles)); // -> 7

/* Así quedaría la representación:
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
.  .  X  .  X  .  X  .  X  .  X 
S--------------------S---------
*/

// Longitudes de salto:
// 1 caería en el 2
// 2 caería en el 2
// 3 caería en el 6
// 4 caería en el 4
// 5 caería en el 10
// 6 caería en el 6
// 7 es el ideal!!! ✅

console.log(getMinJump([1, 2, 3, 5])); // -> 4
console.log(getMinJump([3, 7, 5])); // -> 2
console.log(getMinJump([9, 5, 1])); // -> 2

