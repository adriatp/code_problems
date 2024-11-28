function createMagicPotion(potions, target) {
  let result = undefined;
  for (let i=potions.length - 1; i>0; i--) {
    for (let j=i-1; j>=0; j--) {
      if (potions[i] + potions[j] == target) {
        result = [i,j].sort();
      }
    }
  }
  return result
}

let potions = [4, 5, 6, 2]
let goal = 8
let result = createMagicPotion(potions, goal)
console.log(`${result}`)

potions = [1, 2, 3, 4]
goal = 9
result = createMagicPotion(potions, goal)
console.log(`${result}`)

potions = [1, 2, 3, 4]
goal = 5
result = createMagicPotion(potions, goal)
console.log(`${result}`)

potions = [1, -2, 3, -4, 5]
goal = -1
result = createMagicPotion(potions, goal)
console.log(`${result}`)

potions = [10, 20, 30, 40]
goal = 50
result = createMagicPotion(potions, goal)
console.log(`${result}`)

potions = [10, 5, 2, 3, 7, 5]
goal = 10
result = createMagicPotion(potions, goal)
console.log(`${result}`)