
function smallestPositiveNumber(arr) {
    let obj = new Map();
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > 0) {
            // obj[arr[i]]++;
            if (obj.has(arr[i])) {
                obj.set(arr[i], obj.get(arr[i]) + 1)
            } else {
                obj.set(arr[i], 1)
            }
        }
    }
    let index = 1;
    while (true) {
        if (!obj.has(index)) {
            return index;
        }

        index++;
    }
}

console.log(smallestPositiveNumber([0, 1, 2, 3, 4, 5]));
