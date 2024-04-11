function wrapGifts(gifts) {
    let ret_list = [];
    if (gifts.length == 0) return ret_list;
    let top_bot = '*'.repeat(gifts[0].length) + '**';
    ret_list.push(top_bot);
    for (let i=0; i<gifts.length; i++)
        ret_list.push('*' + gifts[i] + '*');
    ret_list.push(top_bot);
    return ret_list;
}

console.log(wrapGifts(["📷", "⚽️"]));
/* Resultado:
[ '****',
  '*📷*',
  '*⚽️*',
  '****'
]
*/

console.log(wrapGifts(["🏈🎸", "🎮🧸"]));
/* Resultado:
[ '******',
  '*🏈🎸*',
  '*🎮🧸*',
  '******'
]
*/

console.log(wrapGifts(["📷"]));
/* Resultado:
[ '****',
  '*📷*',
  '****'
]
*/