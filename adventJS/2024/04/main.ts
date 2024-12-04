function createXmasTree(height, ornament) {
  let air = '_'.repeat(height-1);
  let orns = '#';
  let ret = air + '#' + air + '\n' + air + '#' + air;
  for (let i=0; i<height; i++) {
    air = '_'.repeat(i);
    orns = ornament.repeat(height-i-1);
    ret = air + orns + ornament + orns + air + '\n' + ret;
  }
  return ret;
}

const tree = createXmasTree(5, '*')
console.log(tree)
/*
____*____
___***___
__*****__
_*******_
*********
____#____
____#____
*/

const tree2 = createXmasTree(3, '+')
console.log(tree2)
/*
__+__
_+++_
+++++
__#__
__#__
*/

const tree3 = createXmasTree(6, '@')
console.log(tree3)
/*
_____@_____
____@@@____
___@@@@@___
__@@@@@@@__
_@@@@@@@@@_
@@@@@@@@@@@
_____#_____
_____#_____
*/