
const input = async (prompt: string): Promise<string> => {
    Deno.stdout.write(new TextEncoder().encode(prompt));
    const buf = new Uint8Array(1024);
    const n = await Deno.stdin.read(buf);
    return new TextDecoder().decode(buf.subarray(0, n)).trim();
};

const get_code = (firstInput: string, secondInput: string): string => {
  const firstInputArray = firstInput.split('');
  let position = 0;
  for (let i = 0; i < secondInput.length; i++) {
    if (secondInput[i] == 'U') {
      firstInputArray[position] = String((Number(firstInputArray[position]) + 1) % 10);
    }
    else if (secondInput[i] == 'D') {
      if (firstInputArray[position] == '0') {
        firstInputArray[position] = '9';
      } else {  
        firstInputArray[position] = String((Number(firstInputArray[position]) - 1));
      }
    }
    else if (secondInput[i] == 'L') {
      if (position == 0) {
        position = firstInputArray.length - 1;
      } else {
        position--;
      }
    }
    else if (secondInput[i] == 'R') {
      position = (position + 1) % firstInputArray.length
    }
  }
  return firstInputArray.join('');
}

const main = async () => {
  const firstInput = await input("Enter the first value: ");
  const secondInput = await input("Enter the second value: ");
  const result = get_code(firstInput, secondInput);
  console.log(`The code is: ${result}`);
};


main();