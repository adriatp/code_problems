function fitsInOneBox(boxes) {
  let act = boxes[0];
  for (let i=1; i<boxes.length; i++) {
    console.log(act);
    if (act.l < boxes[i].l && act.w < boxes[i].w && act.h < boxes[i].h)
      act = boxes[i];
    else if (!(act.l > boxes[i].l && act.w > boxes[i].w && act.h > boxes[i].h))
      return false;
  }
  console.log(act);
  return true;
}

let boxes = [
  { l: 1, w: 1, h: 10 },
  { l: 3, w: 3, h: 12 },
  { l: 2, w: 2, h: 1 },
]; 

console.log(fitsInOneBox(boxes));

boxes = [
  { l: 1, w: 1, h: 1 },
  { l: 3, w: 3, h: 3 },
  { l: 2, w: 2, h: 2 }
]

console.log(fitsInOneBox(boxes));