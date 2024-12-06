function inBox(box: string[]): boolean {
  const size = box[0].length;
  if (!box.every(row => row.length === size)) return false;
  if ((box[0] + box[box.length-1]).split('').some(char => char !== '#'))
    return false;
  let found: boolean = false;
  for (let i=1; i<box.length-1; i++) {
    if ((box[i][0] + box[i][size-1]) != '##')
      return false;
    for (let j=1; j<size-1; j++) {
      if (box[i][j] != ' ') {
        if (!found && box[i][j] == '*')
          found = true;
        else
          return false;
      }
    }
  }
  return found;
}

let a = inBox([
  "###",
  "#*#",
  "###"
]) // ➞ true

console.log(a);

a = inBox([
  "####",
  "#* #",
  "#  #",
  "####"
]) // ➞ true

console.log(a);

a = inBox([
  "#####",
  "#   #",
  "#  #*",
  "#####"
]) // ➞ false

console.log(a);

a = inBox([
  "#####",
  "#   #",
  "#   #",
  "#   #",
  "#####"
]) // ➞ false

console.log(a);

a = inBox([
  "#####",
  "#   #",
  "#   #",
  "#   #",
  "#####"
]) // ➞ false

console.log(a);

a = inBox([
  "#####",
  "# * #",
  "#   #",
  "#####"
]) // ➞ true

console.log(a);

a = inBox([
  "#####",
  "#*  #",
  "#   #",
  "#   #",
  "#   #",
  "#   #",
  "#####"
]) // ➞ true

console.log(a);