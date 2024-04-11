function fixFiles(files) {
  let reps = {}
  for (let k=0; k<files.length; k++) {
    if (!(files[k] in reps))  reps[files[k]] = 0;
    else                      reps[files[k]] += 1;
    if (reps[files[k]] > 0)   files[k] = files[k] + '(' + reps[files[k]] + ')'
  }
  return files;
}

const files = ['photo', 'postcard', 'photo', 'photo', 'video']
console.log(fixFiles(files)); // ['photo', 'postcard', 'photo(1)', 'photo(2)', 'video']

const files2 = ['file', 'file', 'file', 'game', 'game']
console.log(fixFiles(files2)); // ['file', 'file(1)', 'file(2)', 'game', 'game(1)']

// ojo que los elfos ya tenían archivos con (1)... ¡y pueden estar repetidos!
const files3 = ['file', 'file(1)', 'icon', 'icon(1)', 'icon(1)']
console.log(fixFiles(files3)); // ['file', 'file(1)', 'icon', 'icon(1)', 'icon(1)(1)']

