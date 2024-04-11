export default function contarOvejas(ovejas) {
    ovejas = ovejas.filter(function(item) {
        return item.color === 'rojo' && (item.name.includes('n') || item.name.includes('N')) && (item.name.includes('a') || item.name.includes('A'))
    });
    return ovejas
  }
  