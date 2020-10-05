import java.io.*;
import java.util.*;

public class Person {
    private int age;    
  
    public Person(int initialAge) {
          // Add some more code to run some checks on initialAge
          if(initialAge>0) {
              age = initialAge;
          } else {
              System.out.println("Age is not valid, setting age to 0.");
              age = 0;
          }
    }

    public void amIOld() {
          String output = "";
          if(age<13) {
              output = "You are young.";
          }
          else if(age < 18) {
              output = "You are a teenager.";
          } else {
          output = "You are old.";
          }
        System.out.println(output);
    }

    public void yearPasses() {
          // Increment this person's age.
          age++;
    }


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int age = sc.nextInt();
			Person p = new Person(age);
			p.amIOld();
			for (int j = 0; j < 3; j++) {
				p.yearPasses();
			}
			p.amIOld();
			System.out.println();
        }
		sc.close();
    }
}