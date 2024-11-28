function battleHorde(zombies, humans) {
  let position = 0;
  let count = 0;
  while (position < humans.length) {
    count += humans[position] - zombies[position];
    position++;
  }
  if (count > 0)      return count.toString() + 'h'
  else if (count < 0) return (-1 * count).toString() + 'z'
  return 'x'
}

let zombies = '242';
let humans = '334';
let result = battleHorde(zombies, humans);  // -> "2h"
// first round: zombie 2 vs human 3 -> human wins (+1)
// second round: zombie 4 vs human 3+1 -> tie
// third round: zombie 2 vs human 4 -> human wins (+2)
// result: "2h"
console.log(`${result}`)

zombies = '444';
humans = '282';
result = battleHorde(zombies, humans);  // -> "x"
// first round: zombie 4 vs human 2 -> zombie wins (+2)
// second round: zombie 4+2 vs human 8 -> human wins (+2)
// third round: zombie 4 vs human 2+2 -> tie
// result: "x"
console.log(`${result}`)