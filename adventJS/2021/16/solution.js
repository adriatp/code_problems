export default function decodeNumber(symbols) {
  let ret_value = 0;
  let sym_list = ['.',',',':',';','!'];
  let values = {
    '.': 1,
    ',': 5,
    ':': 10,
    ';': 50,
    '!': 100,
  };
  for (let i=0; i<symbols.length; i++) {
    if (!(sym_list.includes(symbols[i]))) 
      return NaN;
    if (i<symbols.length-1 && values[symbols[i]] < values[symbols[i+1]])
      ret_value -= values[symbols[i]];
    else
      ret_value += values[symbols[i]];
  }
  return ret_value;
}