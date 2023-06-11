import * as fs from 'fs';
import * as path from 'path';

function main() {
    let file = fs.readFileSync('./input.txt', 'utf-8');
    let groups = file.split('\n\r');
    console.log(groups);
}

main();



