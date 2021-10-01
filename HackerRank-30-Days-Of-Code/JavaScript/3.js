const N = parseInt(readLine(), 10);
if (N % 2 == 0){
    if (N >= 2 && N < 6){
        console.log("Not Weird")
    }
    if (N >= 6 && N < 21){
        console.log("Weird");
    }
    if(N>20) {
        console.log("Not Weird");
    }
}else {
    console.log("Weird");
}