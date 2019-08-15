package lesson1;

import java.util.Scanner;

public class W_Palindrome_number {
	public static void main(String[] args) {
		System.out.println("Enter a number:");
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		int tempNumber = number;
		
		//Reversed number
		int reversed = 0;
		while(number != 0) {
			int digit = number % 10;
			reversed = reversed * 10 + digit;
			number /= 10;
		}
		
		//Is a palindrome?
		if(tempNumber == reversed) {
			System.out.println(tempNumber + " is a Palindrome number!");
		}else {
			System.out.println(tempNumber + " is not a Palindrome number!");
		}
	}
}
/* If the number is equal to it's reversed number, then the given number is a palindrome number*/