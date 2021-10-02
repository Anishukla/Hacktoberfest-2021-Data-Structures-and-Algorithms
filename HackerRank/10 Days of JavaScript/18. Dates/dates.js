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

// The days of the week are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
function getDayName(dateString) {
    let dayName;
    // Write your code here
    dayName = new Date(dateString).toString().slice(0, 3);
    switch (dayName) {
        case 'Sun' :
            dayName = 'Sunday';
            break;
        case 'Mon' :
            dayName = 'Monday';
            break;
        case 'Tue' :
            dayName = 'Tuesday';
            break;
        case 'Wed' :
            dayName = 'Wednesday';
            break;
        case 'Thu' :
            dayName = 'Thursday';
            break;
        case 'Fri' :
            dayName = 'Friday';
            break;
        case 'Sat' :
            dayName = 'Saturday';
            break;
    }
    return dayName;
}


function main() {
    const d = +(readLine());

    for (let i = 0; i < d; i++) {
        const date = readLine();

        console.log(getDayName(date));
    }
}
