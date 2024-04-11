function countPackagesRec(carriers, carrierID) {
  let sum = carriers[carrierID][0];
  for (let i=0; i<carriers[carrierID][1].length; i++) {
    sum += countPackagesRec(carriers,carriers[carrierID][1][i]);
  }
  return sum;
}

function countPackages(carriers, carrierID) {
  let carriers_obj = {};
  for (let i=0; i<carriers.length; i++) {
    carriers_obj[carriers[i][0]] = [
      carriers[i][1],
      carriers[i][2]
    ]
  }
  return countPackagesRec(carriers_obj, carrierID);
}

const carriers = [
  ['dapelu', 5, ['midu', 'jelowing']],
  ['midu', 2, []],
  ['jelowing', 2, []]
]

console.log(countPackages(carriers, 'dapelu')); // 9
// 5 de dapelu, 2 de midu y 2 de jelowing = 9

const carriers2 = [
  ['lolivier', 8, ['camila', 'jesuspoleo']],
  ['camila', 5, ['sergiomartinez', 'conchaasensio']],
  ['jesuspoleo', 4, []],
  ['sergiomartinez', 4, []],
  ['conchaasensio', 3, ['facundocapua', 'faviola']],
  ['facundocapua', 2, []],
  ['faviola', 1, []]
]

console.log(countPackages(carriers2, 'camila')); // 15