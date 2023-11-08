import java.util.*;
public class WordPlayer {
    private static boolean matchSpecial(String src, String tgt) {
        boolean status = false;
        int matchCount = 0;
        src = src.toLowerCase();
        tgt = tgt.toLowerCase();
        if(src.length() == tgt.length()) {
            for(int i = 0; i < src.length(); i++) {
                int countSrc = 1;
                for(int j = 0; j < src.length(); j++) {
                    if(src.charAt(i) == src.charAt(j) && j != i) {
                        countSrc += 1;
                    }
                }
                int countTgt = 0;
                for(int j = 0; j < tgt.length(); j++) {
                    if(src.charAt(i) == tgt.charAt(j)) {
                        countTgt += 1;
                    }
                }
                if(countSrc == countTgt) {
                    matchCount += 1;
                }
                else {
                    break;
                }
            }
            if(matchCount == src.length()) {
                status = true;
            }
        }
        return status;
    }

    public static void main(String[] args) {
        int count = 0;
        String out = "";
        Scanner in = new Scanner(System.in);
        int h = in.nextInt();
        String str = in.nextLine();
        String arr[] = str.split(" ");
        int ar[] = new int[arr.length];

        for(int k = 0; k < arr.length; k++) {
            ar[k] = 1;
        }
        for(int j = 0; j < arr.length - 1; j++) {
            count = 1;
            for(int k = j + 1; k < arr.length; k++) {
                if((arr[j] != null && arr[k] != null) && (arr[j].equalsIgnoreCase(arr[k]) || matchSpecial(arr[j], arr[k]))) {
                    count += 1;
                    arr[k] = null;
                    ar[j] = count;
                    ar[k] = -1;
                }
            }
        }
        int max = ar[0];
        for(int j = 1; j < ar.length; j++) {
            if(ar[j] > max) {
                max = ar[j];
            }
        }
        int p = 0;
        for(int j = 0; j < arr.length; j++) {
            if(ar[j] == max) {
                if(p == 0) {
                    if(!arr[j].equals("")) {
                        out = "[" + arr[j];
                        p += 1;
                    }
                }
                else {
                    out += "," + arr[j];
                }
            }
        }
        out += "]";
        System.out.println(out + "-" + max);
    }
}