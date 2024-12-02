function createFrame(names: string[]): string {
  let ret: string = '*';
  if (names.length > 0) {
    const horizontal = Math.max(...names.map(s => s.length)) + 4;
    ret = '*'.repeat(horizontal) + '\n';
    for (let i=0; i<names.length; i++) {
      ret += ('* ' + names[i] + ' '.repeat(horizontal-names[i].length - 3) + '*\n')
    }
    ret += '*'.repeat(horizontal);
  }
  return ret;
}

console.log(createFrame(['midu', 'madeval', 'educalvolpz']));

console.log(createFrame(['midu']));

console.log(createFrame(['a', 'bb', 'ccc']));

console.log(createFrame(['a', 'bb', 'ccc', 'dddd']));