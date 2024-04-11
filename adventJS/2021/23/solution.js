function canReconfigure(from, to) {
  if (from.length != to.length)
    return false;
  let assigs = {};
  let reverse_assigs = {};
  for (let i=0 ; i<from.length; i++) {
    if (from[i] in assigs && assigs[from[i]] != to[i])
      return false;
    assigs[from[i]] = to[i];
    if (to[i] in reverse_assigs && reverse_assigs[to[i]] != from[i])
      return false;
    reverse_assigs[to[i]] = from[i];
  }
  return true;
}

let from = 'BAL'
let to   = 'LIB'
console.log(canReconfigure(from, to)); // true
/* la transformación sería así:
B -> L
A -> I
L -> B
*/

from = 'CON'
to   = 'JUU'
console.log(canReconfigure(from, to)); // false
/* no se puede hacer la transformación:
C -> J
O -> U
N -> FALLO
*/

from = 'XBOX'
to   = 'XXBO'
console.log(canReconfigure(from, to)); // false
/* no se puede hacer la transformación:
X -> X
B -> X (FALLO, no mantiene el orden de transformación y la B no puede asignarse a la X que ya se asignó a otra) 
O -> B
X -> O (FALLO, la X no puede asignarse a la O que ya se asignó a la X)
*/

from = 'XBOX'
to   = 'XOBX'
console.log(canReconfigure(from, to)); // true

from = 'MMM'
to   = 'MID'
console.log(canReconfigure(from, to)); // false
/* no se puede hacer la transformación:
M -> M (BIEN, asigna el mismo carácter a si mismo)
M -> I (FALLO, asigna el mismo carácter a dos letras distintas)
M -> D (FALLO, asigna el mismo carácter a dos letras distintas)
*/

from = 'AA'
to   = 'MID'
console.log(canReconfigure(from, to)); // false -> no tiene la misma longitud