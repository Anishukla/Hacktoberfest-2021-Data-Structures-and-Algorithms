'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function regexVar() {
    /*
     * Declare a RegExp object variable named 're'
     * It must match ALL occurrences of numbers in a string.
     */
    var re = new RegExp('\\d+', 'g');

    /*
     * Do not remove the return statement
     */
    return re;
}


function main() {
    var t = readLine();
    for(let i = 0; i < t; i++) {
        const re = regexVar();
        const s = readLine();

        const r = s.match(re);

        for (const e of r) {
            console.log(e);
        }
        console.log();
    }
}
