const loadJson = async (filePath: string): Promise<number[]> => {
  const data = await Deno.readTextFile(filePath);
  return JSON.parse(data) as number[];
};

const isPrime = (n: number): boolean => {
  if (n <= 1) return false;
  if (n === 2 || n === 3) return true;
  if (n % 2 === 0 || n % 3 === 0) return false;
  for (let i = 5; i * i <= n; i += 6) {
      if (n % i === 0 || n % (i + 2) === 0) {
          return false;
      }
  }
  return true;
}

const sumDigits = (n: number): number => {
  return String(n).split("").map(Number).reduce((sum, digit) => sum + digit, 0);
}

const main = async () => {
  const numbers = await loadJson("./log.txt");
  const satisfy : number[] = [];
  for (let i=0; i<numbers.length; i++) {
    if (isPrime(numbers[i]) && isPrime(sumDigits(numbers[i])))
      satisfy.push(numbers[i]);
  }
  const idx = satisfy.length > 2 ? 2 : satisfy.length - 1;
  console.log(`Satisfy: ${satisfy.length}\n${satisfy[idx]}`);
};

main();