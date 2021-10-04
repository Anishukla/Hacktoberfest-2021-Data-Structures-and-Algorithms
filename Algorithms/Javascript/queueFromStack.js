// implement a queue data structure using two stacks
// implement functions add, remove, and peek

const Stack = require('../../Data\ Structures/Stack/stack');

class Queue {
  constructor() {
    this.stackOne = new Stack();
    this.stackTwo = new Stack();
  }

  add(value) {
    this.stackOne.push(value);
  }

  remove() {
    let returnValue;

    while (this.stackOne.peek()) {
      this.stackTwo.push(this.stackOne.pop());
    }

    if (this.stackTwo.peek()) returnValue = this.stackTwo.pop();

    while (this.stackTwo.peek()) {
      this.stackOne.push(this.stackTwo.pop());
    }

    return returnValue;
  }

  peek() {
    while (this.stackOne.peek()) {
      this.stackTwo.push(this.stackOne.pop());
    }

    const returnValue = this.stackTwo.peek();

    while (this.stackTwo.peek()) {
      this.stackOne.push(this.stackTwo.pop());
    }

    return returnValue;
  }
}

module.exports = Queue;
