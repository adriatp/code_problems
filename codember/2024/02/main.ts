
const readLines = async (filePath: string): Promise<string[]> => {
  const decoder = new TextDecoder("utf-8");
  const data = await Deno.readFile(filePath);
  return decoder.decode(data).split("\n").map(line => line.trim());
};

const countJumps = (instructions: string): number => {
  const intructions: number[] = instructions.split(" ").map(Number);
  let position = 0, jumps = 0;
  while (position >= 0 && position < intructions.length) {
    console.log(intructions)
    intructions[position]++;
    position += intructions[position] - 1;
    jumps++;
  }
  return jumps;
};

const main = async () => {
  const lines = await readLines("./log.txt");
  let totalJumps = 0;
  let lastJump = null;
  for (let i=0; i<lines.length; i++) {
    lastJump = countJumps(lines[i]);
    totalJumps += lastJump;
  }
  console.log(`${totalJumps}-${lastJump}`)
};


main();