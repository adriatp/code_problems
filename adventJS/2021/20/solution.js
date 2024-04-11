function pangram(letter) {
  letter = letter.toLowerCase();
  letter = letter.replaceAll('à', 'a').replaceAll('á', 'a').replaceAll('ä', 'a');
  letter = letter.replaceAll('è', 'e').replaceAll('é', 'e').replaceAll('ë', 'e');
  letter = letter.replaceAll('ì', 'i').replaceAll('í', 'i').replaceAll('ï', 'i');
  letter = letter.replaceAll('ò', 'o').replaceAll('ó', 'o').replaceAll('ö', 'o');
  letter = letter.replaceAll('ù', 'u').replaceAll('ú', 'u').replaceAll('ü', 'u');
  let abc = 'abcdefghijklmnñopqrstuvwxyz'
  for (let i=0; i<abc.length; i++) 
    if (!letter.includes(abc[i]))
      return false;
  return true;
}

console.log(pangram('Extraño pan de col y kiwi se quemó bajo fugaz vaho') );// true
console.log(pangram('Jovencillo emponzoñado y con walkman: ¡qué figurota exhibes!') );// true
console.log(pangram('Esto es una frase larga pero no tiene todas las letras del abecedario') );// false
console.log(pangram('De la a a la z, nos faltan letras') );// false
