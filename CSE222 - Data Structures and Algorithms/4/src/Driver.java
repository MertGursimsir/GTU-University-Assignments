public class Driver{
	public static void main(String[] args){
		Recursion program = new Recursion();

		System.out.println("*******************************");
		System.out.printf("---------FIRST PROGRAM---------\n");
		System.out.println("*******************************");
		String big = "It is only teachers who are saving nations; teachers, the new generation will be your devotion.";
		String query = "teachers";
		String big2 = "While there's life, there's hope.";
		String query2 = "there";

		System.out.println("FIRST TRY:");
		System.out.printf("Big string: %s\n", big);
		System.out.printf("Query string: %s\n", query);
		System.out.printf("Index of 1. occurrence: %d\n", program.Q1(query, big, 1));
		System.out.printf("Index of 2. occurrence: %d\n", program.Q1(query, big, 2));
		System.out.printf("Index of 3. occurrence: %d\n", program.Q1(query, big, 3));

		System.out.println("\nSECOND TRY:");
		System.out.printf("Big string: %s\n", big2);
		System.out.printf("Query string: %s\n", query2);
		System.out.printf("Index of 1. occurrence: %d\n", program.Q1(query2, big2, 1));
		System.out.printf("Index of 2. occurrence: %d\n", program.Q1(query2, big2, 2));
		System.out.printf("Index of 3. occurrence: %d\n", program.Q1(query2, big2, 3));

		/*********************************************************************************************************/	

		System.out.println("\n\n\n*******************************");
		System.out.printf("---------SECOND PROGRAM--------\n");
		System.out.println("*******************************");
		int[] arraySorted = {-25, 0, 1, 3, 5, 11, 42, 42, 42, 53, 60, 71, 99};

		System.out.printf("Array: ");
		for(int i = 0; i < arraySorted.length; ++i) System.out.printf("%d ", arraySorted[i]);
		System.out.printf("\nNumber of items in the array between 5 and 71: %d\n", program.Q2(arraySorted, 5, 71));
		System.out.printf("Number of items in the array between -100 and 10: %d\n", program.Q2(arraySorted, -100, 10));
		System.out.printf("Number of items in the array between -30 and 0: %d\n", program.Q2(arraySorted, -30, 0));
		System.out.printf("Number of items in the array between 53 and 60: %d\n", program.Q2(arraySorted, 53, 60));

		/*********************************************************************************************************/	

		System.out.println("\n\n\n*******************************");
		System.out.printf("---------THIRD PROGRAM---------\n");
		System.out.println("*******************************");

		int[] arrayUnsorted = {-42, 42, 0, 99, -1859, 1901, 18, 99, 996, -5, 5, 42, 0, 90};
		System.out.println("\nFIRST TRY:");
		System.out.printf("Array: ");
		for(int i = 0; i < arrayUnsorted.length; ++i) System.out.printf("%d ", arrayUnsorted[i]);
		System.out.printf("\nSubarray/s that the sum of its/theirs items is equal to 42:\n");
		program.Q3(arrayUnsorted, 42);

		int[] arrayUnsorted2 = {0, 99, 124, 0, -124, -99, 123, 905, -905, 66, -65};
		System.out.println("\nSECOND TRY:");
		System.out.printf("Array: ");
		for(int i = 0; i < arrayUnsorted2.length; ++i) System.out.printf("%d ", arrayUnsorted2[i]);
		System.out.printf("\nSubarray/s that the sum of its/theirs items is equal to 0:\n");
		program.Q3(arrayUnsorted2, 0);

		/*********************************************************************************************************/

		System.out.println("\n\n\n*******************************");
		System.out.printf("----------LAST PROGRAM---------\n");
		System.out.println("*******************************");

		System.out.println("\nFIRST TRY (array with length 7):");
		//0 represents empty block
		int[] arrayBlocks = {0, 0, 0, 0, 0, 0, 0};
		int L = arrayBlocks.length;
		program.Q5(arrayBlocks, L);

		System.out.println("\nSECOND TRY (array with length 10):");
		int[] arrayBlocks2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		int L2 = arrayBlocks2.length;
		program.Q5(arrayBlocks2, L2);
	}
}