function createCube(size) {
  let ret_string = '';
  for (let i=0; i<size; i++)
    ret_string += (' '.repeat(size-i-1) + '/\\'.repeat(i+1) + '_\\'.repeat(size) + '\n');
  for (let i=0; i<size; i++)
    ret_string += ' '.repeat(i) + '\\/'.repeat(size-i) + '_/'.repeat(size) + '\n';
  return ret_string.slice(0, -1);
}

for (let i=1; i<50; i++) {
console.log(createCube(i));
}
