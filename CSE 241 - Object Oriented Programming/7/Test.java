import dayofyearsetpackage.DayofYearSet;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.FileWriter;
import java.io.IOException;

public class Test{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);	//scanner to take inputs
		String input;	//input from user
		boolean flag = true; //flag for some loops
		int i = 0;	//iterator for some loops

		//USER FILLED ARRAYS
		DayofYearSet s1 = new DayofYearSet();
		DayofYearSet s2 = new DayofYearSet(10);

		//FILLED ARRAYS WITH ARRAYLIST
		ArrayList<DayofYearSet.DayofYear> datesArray = new ArrayList<DayofYearSet.DayofYear>();
		for (int j = 1; j < 13; j+=2){
			for (int k = 1; k < 31; k+=3){
				datesArray.add(new DayofYearSet.DayofYear(k,j));
			}
		}
		DayofYearSet s3 = new DayofYearSet(datesArray);
		ArrayList<DayofYearSet.DayofYear> datesArray2 = new ArrayList<DayofYearSet.DayofYear>();
		for (int j = 2; j < 13; j+=2){
			for (int k = 1; k < 30; k+=3){
				datesArray2.add(new DayofYearSet.DayofYear(k,j));
			}
		}
		DayofYearSet s4 = new DayofYearSet(datesArray2);


		/*****************************************************************************************
		**********************************TAKING INPUTS*******************************************
		*****************************************************************************************/

		System.out.println("~ WELCOME TO WORLD OF SETS ~");
		System.out.println("Now we will try our set methods one by one.");
		System.out.println("I want you to fill 2 sets, and I will create 2 more sets.");
		System.out.println("Type \"-1\" to stop filling.");
		System.out.println("\nFIRST SET\n---------");
		do{
			try{
				System.out.printf("\n%d. date:\n", i+1);
				System.out.printf("Day ---> ");
				int day = scanner.nextInt();
				if (day == -1) throw new Exception();	//Specify that user wants to exit
				System.out.printf("Month ---> ");
				int month = scanner.nextInt();
				if(month == -1) throw new Exception();	//Specify that user wants to exit
				s1.add(new DayofYearSet.DayofYear(day, month));
				i++;	
			}
			catch( InputMismatchException inputMismatchException ){
				System.err.printf( "\nException: %s\n", inputMismatchException );
				scanner.nextLine(); // discard input so user can try again
				System.out.println("You must enter integers. Please try again.\n" );
			}
			catch (Exception exception){
				flag = false;
			}
		}while(flag);

		flag = true; i = 0;
		System.out.println("\nSECOND SET\n---------");
		do{
			try{
				System.out.printf("\n%d. date:\n", i+1);
				System.out.printf("Day ---> ");
				int day = scanner.nextInt();
				if (day == -1) throw new Exception();
				System.out.printf("Month ---> ");
				int month = scanner.nextInt();
				if(month == -1) throw new Exception();
				s2.add(new DayofYearSet.DayofYear(day, month));
				i++;	
			}
			catch( InputMismatchException inputMismatchException ){
				System.err.printf( "\nException: %s\n", inputMismatchException );
				scanner.nextLine(); // discard input so user can try again
				System.out.println("You must enter integers. Please try again.\n" );
			}
			catch (Exception exception){
				flag = false;
			}
		}while(flag);

		/*****************************************************************************************
		**********************************SHOWING SETS********************************************
		*****************************************************************************************/


		System.out.printf("\nYour first set: %s", s1);
		System.out.printf("\nYour second set: %s", s2);
		System.out.printf("\nMy first set: %s", s3);
		System.out.printf("\nMy second set: %s", s4);
		System.out.printf("There are %d DayofYear objects alive.\n", DayofYearSet.aliveObjects());

		if (s1.equals(s2)) System.out.println("Your 2 sets are equal.");
		else System.out.println("Your 2 sets are not equal.");
		if (s3.equals(s4)) System.out.println("My 2 sets are equal.");
		else System.out.println("My 2 sets are not equal.");

		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		/*****************************************************************************************
		***************TRYING UNION, INTERSECTION, DIFFERENCE, COMPLEMENT METHODS*****************
		*****************************************************************************************/

		System.out.printf("\nUnion of your sets (s1 + s2): %s", s1.union(s2));
		System.out.printf("\nIntersection of your sets (s1 ^ s2): %s", s1.intersection(s2));
		System.out.printf("\nDifference of your sets (s1 - s2): %s", s1.difference(s2));
		System.out.printf("\nComplement of your first set (!s1): %s", s1.complement());

		System.out.printf("\nUnion of my sets (s3 + s4): %s", s3.union(s4));
		System.out.printf("\nIntersection of my sets (s3 ^ s4): %s", s3.intersection(s4));
		System.out.printf("\nDifference of my sets (s3 - s4): %s", s3.difference(s4));
		System.out.printf("\nComplement of my first set (!s3): %s", s3.complement());

		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		/*****************************************************************************************
		**********************************REMOVING ELEMENTS***************************************
		*****************************************************************************************/

		flag=true;
		System.out.println("Now I want you to remove 1 element from your first list.");
		if (s1.size() > 0){
			do{
				try{
					System.out.printf("Index to be removed:");
					int index = scanner.nextInt();
					s1.remove(index);
					flag = false;
				}
				catch( InputMismatchException inputMismatchException ){
					System.err.printf( "\nException: %s\n", inputMismatchException );
					scanner.nextLine(); // discard input so user can try again
					System.out.println("You must enter integers. Please try again.\n" );
				}
				catch(Exception exception){
					System.err.println( "You are out of set. Try again." );
				}
			}while(flag);
		}
		else System.out.println("Ooops. It looks like you don't have any element.");
		flag = true;
		System.out.println("Lastly I want you to remove 1 element from your second list.");
		if (s2.size() > 0){
			do{
				try{
					System.out.printf("Index to be removed:");
					int index = scanner.nextInt();
					s2.remove(index);
					flag = false;
				}
				catch( InputMismatchException inputMismatchException ){
					System.err.printf( "\nException: %s\n", inputMismatchException );
					scanner.nextLine(); // discard input so user can try again
					System.out.println("You must enter integers. Please try again.\n" );
				}
				catch(Exception exception){
					System.err.println( "You are out of set. Try again." );
				}
			}while(flag);
		}
		else System.out.println("Ooops. It looks like you don't have any element.");


		System.out.printf("\nYour first set after 1 element removed: %s", s1);
		System.out.printf("\nYour second set after 1 element removed: %s", s2);		
		System.out.printf("There are %d DayofYear objects alive.\n", DayofYearSet.aliveObjects());
		System.out.printf("Your first set has %d elements.\n", s1.size());
		System.out.printf("Your second set has %d elements.\n", s2.size());
		System.out.printf("My first set has %d elements.\n", s3.size());
		System.out.printf("My second set has %d elements.\n", s4.size());

		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		System.out.println("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		System.out.println("Now let's test the De Morgan rule.");
		System.out.println("De Morgan rule for your first and second sets !(s1 + s2) == !s1 ^ !s2 .");
		if (s1.union(s2).complement().equals(s1.complement().intersection(s2.complement())))
			System.out.println("Your 2 sets satisfied De Morgan rule.\n\n");

		System.out.println("De Morgan rule for my first and second sets !(s3 + s4) == !s3 ^ !s4 .");
		if (s3.union(s4).complement().equals(s3.complement().intersection(s4.complement())))
			System.out.println("My 2 sets satisfied De Morgan rule.\n\n");

		System.out.println("De Morgan rule for your first and my first sets !(s1 + s3) == !s1 ^ !s3 .");
		if (s1.union(s3).complement().equals(s1.complement().intersection(s3.complement())))
			System.out.println("Your first set and my first set satisfied De Morgan rule.\n\n");

		System.out.println("De Morgan rule for your second and my second sets !(s2 + s4) == !s2 ^ !s4 .");
		if (s2.union(s4).complement().equals(s2.complement().intersection(s4.complement())))
			System.out.println("Your second set and my second set satisfied De Morgan rule.\n\n");

		System.out.println("De Morgan rule for your first and my second sets !(s1 + s4) == !s1 ^ !s4 .");
		if (s1.union(s4).complement().equals(s1.complement().intersection(s4.complement())))
			System.out.println("Your first set and my second set satisfied De Morgan rule.\n\n");

		System.out.println("De Morgan rule for your second and my first sets !(s2 + s3) == !s2 ^ !s3 .");
		if (s2.union(s3).complement().equals(s2.complement().intersection(s3.complement())))
			System.out.println("Your first set and my first set satisfied De Morgan rule.\n\n");


		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////WRITING SOME SETS TO FILE//////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try{
			FileWriter file = new FileWriter("test.txt");

			file.write("YOUR FIRST SET (s1):");
			file.write(s1.toString());
			file.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			file.write("YOUR SECOND SET (s2):");
			file.write(s2.toString());
			file.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			file.write("!(s1+s2) :");
			file.write(s1.union(s2).complement().toString());
			file.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			file.write("!s1 ^ !s2 :");
			file.write(s1.complement().intersection(s2.complement()).toString());

			file.close();
		}
		catch(IOException exception){
			System.err.printf("Error!");
			exception.printStackTrace();
		}
	

	}
}