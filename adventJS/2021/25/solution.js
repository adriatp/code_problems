function canMouseEat(direction, game) {
  let m_i, m_j;
  for (let k=0; k<game.length; k++) {
    for (let kk=0; kk<game[k].length; kk++) {
      if (game[k][kk] == 'm') {
        m_i = k;
        m_j = kk;
        break;
      }
    }
  }
  if (direction === 'up')     m_i -=1;
  if (direction === 'down')   m_i +=1;
  if (direction === 'right')  m_j +=1;
  if (direction === 'left')   m_j -= 1;
  
  if (m_i < 0 || m_i >= game.length)      return false;
  if (m_j < 0 || m_j >= game[m_i].length) return false;
  return game[m_i][m_j] == '*';
}

const room = [
  [' ', ' ', ' '],
  [' ', ' ', 'm'],
  [' ', ' ', '*']
]

console.log(canMouseEat('up',    room));   // false
console.log(canMouseEat('down',  room));   // true
console.log(canMouseEat('right', room));   // false
console.log(canMouseEat('left',  room));   // false

const room2 = [
  ['*', ' ', ' ', ' '],
  [' ', 'm', '*', ' '],
  [' ', ' ', ' ', ' '],
  [' ', ' ', ' ', '*']
]

console.log(canMouseEat('up',    room2));   // false
console.log(canMouseEat('down',  room2));   // false
console.log(canMouseEat('right', room2));   // true
console.log(canMouseEat('left',  room2));   // false