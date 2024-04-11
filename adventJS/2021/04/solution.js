export default function createXmasTree(height) {
    let ret_str = ''
    let width = height - 1;
    let total_width = width*2 + 1;
    for (let i=0; i<height; i++) {
      for (let j=0; j<width; j++) ret_str += '_';
      for (let j=0; j<total_width-2*width; j++) ret_str += '*'
      for (let j=0; j<width; j++) ret_str += '_';
      width -= 1;
      ret_str += '\n';
    }
    width = height - 1;
    for (let i=0; i<width; i++)   ret_str += '_';
    ret_str += '#';
    for (let i=0; i<width; i++)   ret_str += '_';
    ret_str += '\n';
    for (let i=0; i<width; i++)   ret_str += '_';
    ret_str += '#';
    for (let i=0; i<width; i++)   ret_str += '_';
    return ret_str;
  }