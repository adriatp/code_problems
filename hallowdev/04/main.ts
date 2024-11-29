function findTheKiller(whisper, suspects) {
  const regex = new RegExp("^" + whisper.replaceAll("~", "."));
  return suspects.filter(s => regex.test(s.toLowerCase())).join(',');
}

const whisper = 'd~~~~~a';
const suspects = ['Dracula', 'Freddy Krueger', 'Jason Voorhees', 'Michael Myers'];
let result = findTheKiller(whisper, suspects); // -> 'Dracula'
console.log(`${result}`)

const whisper2 = '~r~dd~';
const suspects2 = ['Freddy', 'Freddier', 'Fredderic']
result = findTheKiller(whisper2, suspects2); // -> 'Freddy,Freddier,Fredderic'
console.log(`${result}`)

const whisper3 = '~r~dd$';
const suspects3 = ['Freddy', 'Freddier', 'Fredderic']
result = findTheKiller(whisper3, suspects3); // -> ''
console.log(`${result}`)

const whisper4 = 'mi~~def';
const suspects4 = ['Midudev', 'Midu', 'Madeval']
result = findTheKiller(whisper4, suspects4); // -> ''
console.log(`${result}`)