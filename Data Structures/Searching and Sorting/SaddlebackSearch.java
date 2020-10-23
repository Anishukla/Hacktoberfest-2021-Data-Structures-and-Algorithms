import java.util.Scanner;
/*
*implementation by BoaMos
*/
public class SaddlebackSearch {

    /**
     * This method performs Saddleback Search
     *
     * @param arr The **Sorted** array in which we will search the element.
     * @param row the current row.
     * @param col the current column.
     * @param key the element that we want to search for.
     * @return The index(row and column) of the element if found.
     * else returns -1 -1.
     */
    private static int[] find(int [][] arr, int row, int col, int key) {

        //array to store the answer row and column
        int ans[] = {-1, -1};
        if (row < 0 || col >= arr[row].length) {
            return ans;
        }
        if (arr[row][col] == key) {
            ans[0] = row;
            ans[1] = col;
            return ans;
        }
        //if the current element is greater than the given element then we move up
        else if (arr[row][col] > key) {
            return find(arr, row - 1, col, key);
        }
        //else we move right
        return find(arr, row, col + 1, key);
    }

    /**
     * Main method
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int [][]arr;
        int i, j, rows = sc.nextInt(), col = sc.nextInt();
        arr = new int[rows][col];
        
         for (i = 0; i < rows; i++) {
            for (j = 0; j < col; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        int key = sc.nextInt();
        //we start from bottom left corner
        int ans[] = find(arr, rows - 1, 0, key);
        System.out.println(ans[0] + " " + ans[1]);
        sc.close();
    }

}
