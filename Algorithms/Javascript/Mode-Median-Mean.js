let data = [2, 5, 6, 4, 4];
function mean(arr) {
  let temp = 0;
  for (let i = 0; i < arr.length; i++) {
    temp += arr[i];
  }
  let avg = temp / arr.length;
  console.log(avg);
}
function median(arr) {
  let num, center;
  arr.sort(function (a, b) {
    return a - b;
  });
  if (arr.length % 2 == 0) {
    num = arr.length / 2;
    center = (arr[num - 1] + arr[num]) / 2;
  } else {
    num = Math.floor(arr.length / 2) + 1;
    center = arr[num];
  }
  console.log(center);
}
function mode(arr) {
  let mod = [],
    count = [],
    i,
    number,
    maxIndex = 0;
  for (i = 0; i < arr.length; i += 1) {
    number = arr[i];
    count[number] = (count[number] || 0) + 1;
    if (count[number] > maxIndex) {
      maxIndex = count[number];
    }
  }
  for (i in count)
    if (count.hasOwnProperty(i)) {
      if (count[i] === maxIndex) {
        mod.push(Number(i));
      }
    }
  console.log(mod);
}
mean(data);
median(data);
mode(data);
