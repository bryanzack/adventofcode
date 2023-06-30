import fs from 'fs';

function main() {
    const file = fs.readFileSync('./input.txt', 'utf8');
    const arr = file.split('\r\n\r\n').map(l => l.split('\r\n'));

    const sum_top_3 = 
        arr
        .map(line => line.reduce((acc, cur) => acc+ +cur, 0))
        .sort((a, b) => a > b ? -1 : 0)
        .slice(0,3)
        .reduce((acc, cur) => acc + cur, 0);

    console.log(sum_top_3);
}

main();
