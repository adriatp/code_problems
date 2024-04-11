function contains(store, product) {
    for (let key in store) {
      if (typeof store[key] === 'object') {
        if (contains(store[key],product))
          return true;
      }
      else if (store[key] === product)
        return true;
    }
    return false;
}

const otroAlmacen = {
    'baul': {
      'fondo': {
        'objeto': 'cd-rom',
        'otro-objeto': 'disquette',
        'otra-cosa': 'mando'
      }
    }
}
    
console.log(contains(otroAlmacen, 'gameboy'));
console.log(contains(otroAlmacen, 'otra-cosa'));
console.log(contains(otroAlmacen, 'mando'));