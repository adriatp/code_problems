export default function sumPairs(numbers, result) {
    for (let k=0; k<numbers.length-1; k++) {
        for (let kk=k+1; kk<numbers.length; kk++) {
            if (numbers[k] + numbers[kk] == result)
                return [numbers[k], numbers[kk]];
        }
    } 
    return null;
}