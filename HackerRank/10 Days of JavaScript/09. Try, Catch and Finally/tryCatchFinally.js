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

/*
 * Complete the reverseString function
 * Use console.log() to print to stdout.
 */
function reverseString(s) {
    try {
        var rev = s.split('').reverse().join('')
        console.log(rev);
    }
    catch(e) {
        console.log(e.message);
        console.log(s);
    }
}


function main() {
    var n = readLine();
    for(var i = 0; i < n; i++) {
        const s = eval(readLine());
        reverseString(s);
    }
}
