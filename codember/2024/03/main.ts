const loadJson = async (filePath: string): Promise<[number, number][]> => {
  const data = await Deno.readTextFile(filePath);
  return JSON.parse(data) as [number, number][];
};

const connectedGroups = (pairs: [number, number][]): number[][] => {
  const groups : number[][] = [];
  for (let i=0; i<pairs.length; i++) {
    console.log(groups);
    let group_first = -1, group_second = -1;
    let j = 0;
    while ((group_first == -1 || group_second == -1) && j < groups.length) {
      if (groups[j].indexOf(pairs[i][0]) > -1)
        group_first = j;
      if (groups[j].indexOf(pairs[i][1]) > -1)
        group_second = j;
      j++;
    }
    if (group_first == -1 && group_second == -1) {
      groups.push([...new Set([...pairs[i]])]);
    } else if (group_first > -1 && group_second == -1) {
      groups[group_first] = [...new Set([...groups[group_first], ...pairs[i]])];
    } else if (group_second > -1 && group_first == -1) {
      groups[group_second] = [...new Set([...groups[group_second], ...pairs[i]])];
    } else {
      groups[group_first] = [...new Set([...groups[group_first], ...groups[group_second]])];
      groups.splice(group_second, 1);
    }
  }
  console.log(groups);
  return groups;
};

const main = async () => {
  const nodes = await loadJson("./log.txt");
  const groups = connectedGroups(nodes);
  const safe : number[] = [];
  for (let i=0; i<groups.length; i++) {
    if (groups[i].length < 3) 
      safe.push(...groups[i]);
  }
  console.log(`Elements: ${safe.length}\n${safe}`);
};

main();