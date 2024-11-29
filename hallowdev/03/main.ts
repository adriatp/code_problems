function findSafestPath(dream) {
  for (let i = 0; i < dream.length; i++) {
    for (let j = 0; j < dream[0].length; j++) {
      if (i > 0 && j > 0) {
        dream[i][j] += Math.min(dream[i - 1][j], dream[i][j - 1]);
      } else if (i > 0) {
        dream[i][j] += dream[i - 1][j];
      } else if (j > 0) {
        dream[i][j] += dream[i][j - 1];
      }
    }
  }
  return dream[dream.length - 1][dream[0].length - 1];
}

const dream = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1],
]

const bestPath = findSafestPath(dream) // Returns 7
// The safest path is:
// [0, 0] -> 1
// [0, 1] -> 3
// [0, 2] -> 1
// [1, 2] -> 1
// [2, 2] -> 1
// 1 -> 3 -> 1 -> 1 -> 1 = 7
console.log(`${bestPath}`);