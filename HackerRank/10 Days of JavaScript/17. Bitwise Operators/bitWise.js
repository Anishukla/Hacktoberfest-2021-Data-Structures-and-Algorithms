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

function getMaxLessThanK(n, k) {
    let max_val = 0;
    for(let i = 1; i < n; i++)
        for(let j = i+1; j < n+1; j++)
            if(Number(i&j) < k)
                if(Number(i&j) > max_val)
                    max_val = i & j;
    return max_val;
}

function main() {
    var t = readLine();
    for(var i = 0; i < t; i++){
        const q = +(readLine());

        for (let i = 0; i < q; i++) {
            const [n, k] = readLine().split(' ').map(Number);

            console.log(getMaxLessThanK(n, k));
        }
        console.log();
    }
}
