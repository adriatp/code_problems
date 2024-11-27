
const readLines = async (filePath: string): Promise<string[]> => {
  const decoder = new TextDecoder("utf-8");
  const data = await Deno.readFile(filePath);
  return decoder.decode(data).split("\n").map(line => line.trim());
};

const errorLine = (input: string) => {
  const allowedChars = "0123456789qwertyuiopasdfghjklzxcvbnm";
  if ([...input].some(char => !allowedChars.includes(char))) 
    return false;
  for (let i = 0; i < input.length - 1; i++) {
    if (input[i] > input[i+1])
      return false;
  }
  return true;
}

const detectError = (lines: string[]) => {
  let errors = 0;
  for (let i = 0; i < lines.length; i++) {
    if (errorLine(lines[i]))
      errors++;
  }
  console.log(`${errors}true${lines.length - errors}false`);
};

const main = async () => {
  const lines = await readLines("./log.txt");
  detectError(lines);
};


main();