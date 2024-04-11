function checkIsSameTree(treeA, treeB) {
  if ( treeA['value'] !==  treeB['value'])  return false;
  if (!treeA['left']   &&  treeB['left'])   return false;
  if ( treeA['left']   && !treeB['left'])   return false;
  if (!treeA['right']  &&  treeB['right'])  return false;
  if ( treeA['right']  && !treeB['right'])  return false;
  
  if (treeA['left'] && treeA['right'])
    return checkIsSameTree(treeA['left'], treeB['left']) && checkIsSameTree(treeA['right'], treeB['right']);
  else if (treeA['left'])
    return checkIsSameTree(treeA['left'], treeB['left']);
  else if (treeA['left'])
    return checkIsSameTree(treeA['right'], treeB['right']);
  
  return true;
}


const tree = {
  value: 1,
  left: { value: 2, left: null, right: null },
  right: { value: 3, left: null, right: null }
}

console.log(checkIsSameTree(tree, tree));   // true

const tree2 = {
  value: 1,
  left: { value: 3, left: { value: 2, left: null, right: null }, right: null },
  right: { value: 5, left: null, right: { value: 4, left: null, right: null } }
}

console.log(checkIsSameTree(tree, tree2));  // false
console.log(checkIsSameTree(tree2, tree2)); // true