type Shoe = {
  type: 'I' | 'R'
  size: number
}

// function organizeShoes(shoes: Shoe[]): number[] {
//   const left = shoes.filter(a => a.type == 'I').map(a => a.size).sort();
//   const right = shoes.filter(a => a.type == 'R').map(a => a.size).sort();
//   let i=0, j=0;
//   const result = [];
//   while (i<left.length && j<right.length) {
//     if (left[i] == right[j]) {
//       result.push(left[i]);
//       i++; j++;
//     } else if (left[i] < right[j])
//       i++;
//     else j++;
//   }
//   return result;
// }

function organizeShoes(shoes: Shoe[]): number[] {
  const leftSizes = new Set(shoes.filter(s => s.type === 'I').map(s => s.size));
  return Array.from(shoes.filter(s => s.type === 'R' && leftSizes.has(s.size)).map(s => s.size)).sort((a, b) => a - b);
}



const shoes = [
  { type: 'I', size: 38 },
  { type: 'R', size: 38 },
  { type: 'R', size: 42 },
  { type: 'I', size: 41 },
  { type: 'I', size: 42 }
]

let a = organizeShoes(shoes);
console.log(a);
// [38, 42]

const shoes2 = [
  { type: 'I', size: 38 },
  { type: 'R', size: 38 },
  { type: 'I', size: 38 },
  { type: 'I', size: 38 },
  { type: 'R', size: 38 }
]

a = organizeShoes(shoes2);
console.log(a);
// [38, 38]

const shoes3 = [
  { type: 'I', size: 38 },
  { type: 'R', size: 36 },
  { type: 'R', size: 42 },
  { type: 'I', size: 41 },
  { type: 'I', size: 43 }
]

a = organizeShoes(shoes3);
console.log(a);
// []
