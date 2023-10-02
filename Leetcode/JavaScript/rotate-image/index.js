/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

// space-complexity: o(1)
// time-complexity: o(n)

function rotate(matrix) {
    // Transpose the matrix
    for(let r = 0; r < matrix.length; r++) {
        for(let c = r; c < matrix.length; c++) {
            // Swap adjacent numbers/cells to transpose the matrix
            [matrix[r][c], matrix[c][r]] = [matrix[c][r], matrix[r][c]];
        }
    }

    // Reverse each row to complete the 90-degree clockwise rotation
    for(let row of matrix) {
        row.reverse();
    }

    // Return the final rotated matrix
    return matrix;

}

