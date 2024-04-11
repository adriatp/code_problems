export default function isValid(letter) {
  let open_par = ['(','{','['];
  let close_par = [')','}',']'];
  let list_par = [];
  let dist = 0;
  for (let i=0; i<letter.length; i++) {
    if (open_par.includes(letter[i])) {
      list_par.push(letter[i]);
      dist = 0;
    }
    else if (close_par.includes(letter[i])) {
      if (list_par.length == 0 || dist == 0) return false;
      let idx = close_par.indexOf(letter[i]);
      if (list_par[list_par.length-1] === open_par[idx])
        list_par.pop();
      else return false;
    }
    else dist++;
  }
  return (list_par.length === 0);
}