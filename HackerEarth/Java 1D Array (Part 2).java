import java.util.*;

public class Solution {

    public static boolean canWin(int leap, int[] game) {
    VirtualPlayer v = new VirtualPlayer(leap, game);
    v.tick();
    return v.winnable;

}
static class VirtualPlayer {
    private int pos = 0; //pos-ition
    private int lp; //lp means leap
    private int[] map;
    boolean winnable = false;
    public VirtualPlayer(int lp, int[] map) {
        this.lp = lp; //gets the values from the canWin function
        this.map = map;

    }
    private void moveup() {
        if (map[pos + 1] == 0) {
            pos++;
            tick();
        }

    }

    private void movedown() {
        if ((pos - 1) >= 0 && map[pos - 1] == 0) {
            map[pos] = 1;
            pos--;
            tick();
        }

    }

    private void jump() {
        if ((pos + lp) < map.length) {
            if (map[pos + lp] == 0) {
                int posold = pos;
                pos = pos + lp;
                tick();
                pos = posold;
            }
        }

    }
    void tick() {
        //System.out.println("im at:"+pos);
        if (pos == (map.length - 1) || ((pos + lp) >= map.length)) {
            winnable = true;
        }
        else {
            this.moveup();
            if (lp != 0) {
                this.jump();
            } //cant jump 0 steps!
            this.movedown();
        }

    }

}

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}