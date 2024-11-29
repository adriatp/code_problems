function escapePyramidHead(room) {
  const visited = Array.from({ length: room.length }, () => Array(room[0].length).fill(false));
  let pyramid = [];
  for (let i = 0; i < room.length; i++) {
    for (let j = 0; j < room[i].length; j++) {
      if (room[i][j] === '▲') {
        pyramid = [i, j];
        break;
      }
    }
    if (pyramid.length > 0) break;
  }
  visited[pyramid[0]][pyramid[1]] = true;
  let steps = 1;
  const movs = [[1,0],[-1,0],[0,1],[0,-1]];
  let availablePositions = [[pyramid[0], pyramid[1]]];
  while (availablePositions.length > 0) {
    const newPositions = [];
    for (let j=0; j<availablePositions.length; j++) {
      const checkedPosition = availablePositions[j];
      for (let k=0; k<movs.length; k++) {
        const nextPos = [
          checkedPosition[0] + movs[k][0],
          checkedPosition[1] + movs[k][1]
        ]
        if (nextPos[0] >= 0 && nextPos[0] < room.length && nextPos[1] >= 0 && nextPos[1] < room[0].length) {
          if (room[nextPos[0]][nextPos[1]] == 'T') return steps;
          else if (room[nextPos[0]][nextPos[1]] == '.' && !visited[nextPos[0]][nextPos[1]]) {
            newPositions.push([nextPos[0], nextPos[1]]);
            visited[nextPos[0]][nextPos[1]] = true;
          }
        }
      }
    }
    availablePositions = newPositions;
    steps++;
  }
  return -1;
}

const room = [
  ['.', '.', '#', '.', '▲'],
  ['#', '.', '#', '.', '#'],
  ['.', '.', '.', '.', '.'],
  ['#', '#', '#', '.', '#'],
  ['T', '.', '.', '.', '.'],
]
console.log(`${escapePyramidHead(room)}`) // -> 8

const room2 = [
  ['T', '.', '#', '.'],
  ['.', '.', '.', '.'],
  ['▲', '.', '.', '#'],
  ['.', '#', '#', '#'],
]
console.log(`${escapePyramidHead(room2)}`) // -> 2

const room3 = [
  ['#', '#', '#'],
  ['▲', '.', '#'],
  ['.', '#', 'T'],
]
console.log(`${escapePyramidHead(room3)}`) // -> null