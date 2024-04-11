function getCoins(change) {
    let coins = [1,2,5,10,20,50];
    let ret_coins = [0,0,0,0,0,0];
    let i = 5;
    while (change > 0) {
        while (change - coins[i] >= 0) {
            change -= coins[i];
            ret_coins[i] += 1; 
        }
        i -= 1;
    }
    return ret_coins;
}

console.log(getCoins(100)); // [0, 0, 0, 0, 0, 2] -> dos monedas de 50 céntimos
console.log(getCoins(51));  // [1, 0, 0, 0, 0, 1] -> una moneda de 1 céntimo y otra de 50 céntimos
console.log(getCoins(3));   // [1, 1, 0, 0, 0, 0] -> una moneda de 1 céntimo y otra de 2
console.log(getCoins(5));   // [0, 0, 1, 0, 0, 0] -> una moneda de 5 céntimos
console.log(getCoins(16));  // [1, 0, 1, 1, 0, 0] -> una moneda de 1 céntimo, una de 5 y una de 10