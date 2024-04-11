function shouldBuyFidelity(times) {
    let price_1 = times * 12;
    let price_2 = 250;
    let act_price = 12;
    for (let i=0; i<times; i++) {
        act_price *= 0.75;
        price_2 += act_price;
    }
    return price_1 > price_2;
}

console.log(shouldBuyFidelity(1)); // false -> Mejor comprar tickets de un sólo uso
console.log(shouldBuyFidelity(100)); // true -> Mejor comprar tarjeta fidelidad