/* 
    =========== Tower of hanoi =====================

    # Problem:
    The Towers of Hanoi is a classic puzzle with 3 pegs and 
    multiple disks of different sizes.
    The goal of the puzzle is to move all the disks from the first peg 
    to the third peg according to the following rules :

    - Only one disk can be moved at a time.
    - You can only move the top disc in a stack.
    - No disk may be placed on top of a smaller disk.

    # Login:
    - Move a tower of height-1 to the buffer peg, 
        using the destination peg.
    - Move the remaining disk to the destination peg.
    - Move the tower of height-1 from the buffer peg to the destination 
        peg using the source peg.
*/

"use strict";

function stepsToSolveHanoiT(height, srcP, desP, bufferP) {
  if (height >= 1) {
    // Move a tower of height-1 to the buffer peg, using the destination peg.
    stepsToSolveHanoiT(height - 1, srcP, bufferP, desP);

    // Move the remaining disk to the destination peg.
    console.log("Move disk from Tower ", srcP, " to Tower ", desP);

    // Move the tower of `height-1` from the `buffer peg` to the `destination peg` using the `source peg`.
    stepsToSolveHanoiT(height - 1, bufferP, desP, srcP);
  }

  return;
}

stepsToSolveHanoiT(3, "A", "C", "B");

// Move disk from Tower  A  to Tower  C
// Move disk from Tower  A  to Tower  B
// Move disk from Tower  C  to Tower  B
// Move disk from Tower  A  to Tower  C
// Move disk from Tower  B  to Tower  A
// Move disk from Tower  B  to Tower  C
// Move disk from Tower  A  to Tower  C
