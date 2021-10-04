// create a stack data structure
// the stack should be a class with methods push, peek and pop

class Stack {
  constructor() {
    this.arr = [];
  }

  push(value) {
    this.arr.push(value);
  }

  pop() {
    return this.arr.pop();
  }

  peek() {
    if (!this.arr.length) return null;
    return this.arr[this.arr.length - 1];
  }
}

module.exports = Stack;
