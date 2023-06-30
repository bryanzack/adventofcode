import fs from 'fs';

function main() {
    const file = fs.readFileSync('./input.txt', 'utf8');  
    const arr = file.split('\r\n\r\n').map(l => l.split('\r\n'));
    const max = Math.max(...arr.map(line => line.reduce((acc, cur) => acc+ +cur, 0)));
    console.log(`max: ${max}`); 
}

main();
