//Time complexity is O(n)

// Maulik Chhabra (github ID: Maulikchhabra)


import java.util.Arrays;

public class ValidShuffle {
    
    public static void main(String[] args) {
        
        String a="abc";
        String b="xyz";
        

        char arr1[]=a.toCharArray();
        char arr2[]=b.toCharArray();

        // String shuffle1="a1b2c3";
        char[] shuffle2="abzxcy".toCharArray(); //string to be validated

		//Sorting all the arrays
        Arrays.sort(arr1);	
        Arrays.sort(arr2);
        Arrays.sort(shuffle2);

		//If shuffle does not equal arr1 + arr2 length then error
        if(arr1.length+arr2.length!=shuffle2.length){
            System.err.println("Not a valid shuffle: Length error");
        }
        else{
            int i=0,j=0,k=0; //initializa pointers

            while(k<shuffle2.length){ //k is pointer for shuffle
                if(i<arr1.length && arr1[i]==shuffle2[k]){
                    i++;
                }
                else if(j<arr2.length && arr2[j]==shuffle2[k]){
                    j++;
                }
                else{
                    System.err.println("Not a valid shuffle: Element error");
                }
                k++;
            }

            if(i>=arr1.length && j>=arr2.length){ //If i and j are greater than arr1 and arr2 lengths then valid
                System.out.println("Valid");
            }
           
        }
   

    }       
}
