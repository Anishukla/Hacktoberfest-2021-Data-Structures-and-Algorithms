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
     * It must match a string that starts and ends with the same vowel (i.e., {a, e, i, o, u})
     */
     var re = /^(a|e|i|o|u).*\1$/;

    /*
     * Do not remove the return statement
     */
    return re;
}


function main() {
    let i;
    let n = readLine();
    for(i = 0; i < n; i++) {
        const re = regexVar();
        const s = readLine();
        console.log(re.test(s));
    }
}
