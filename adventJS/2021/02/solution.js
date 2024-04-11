export default function listGifts(letter) {
    letter = letter.trim().split(' ').filter(function (item) {
      return item[0] != '_';
    });
    function freq(letter) {
      return letter.reduce((acc, curr) => {
        acc[curr] = -~acc[curr];
        return acc;
      }, {});
    }
    return freq(letter);
  }
  