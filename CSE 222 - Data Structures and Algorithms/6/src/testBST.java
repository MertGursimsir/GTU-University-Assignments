import java.io.*;
import java.util.Scanner;

public class testBST{
	public static void main(String[] args){
		try{
			System.out.printf("TEST OF THE HASHING WITH BST\n");
			System.out.printf("----------------------------\n");
			System.out.printf("VALIDATION TEST WITH FILE \"pairs.txt\"\n\n");
			System.out.printf("After adding elements in the file to the hash table with size 7:\n\n");
			BSTHashing<Integer, String> tester = new BSTHashing<Integer, String>(7);
			readFile(tester);
			System.out.printf("%s", tester);

			System.out.printf("Let's get value of the key 16: %s\n", tester.get(16));
			System.out.printf("Let's get value of the key 13: %s\n", tester.get(13));

			String temp = tester.remove(13);
			System.out.printf("\nLet's remove non-existing key (13).\nReturned element of remove(13): %s\n", temp);
			temp = tester.remove(44);
			System.out.printf("\nLet's remove existing key (44).\nReturned element of remove(44): %s\n", temp);
			tester.remove(12); tester.remove(17); tester.remove(6); tester.remove(15); 
			tester.put(23, "changedValue");
			System.out.printf("\nLet's remove some other keys (12, 17, 6, 15) and change value of 23.\n");
			System.out.printf("\nTable after these removals:\n\n%s", tester);
			
			for (int i = 100; i < 111; ++i) tester.put(i, "toExceedThreshold");
			System.out.printf("\nLet's try to exceed threshold with adding more dummy elements. Table after rehash:\n\n%s", tester);

			/***************************************************************************************************************************/

			System.out.printf("Do you want performance test? This may take a while (Y: yes, N: no) >> ");
			Scanner scan = new Scanner(System.in);
			String control = scan.nextLine();

			if (control.equals("Y")){
				System.out.printf("\n\nPERFORMANCE TEST\n\n");
				BSTHashing<Integer, Integer> tester2 = new BSTHashing<Integer, Integer>();
			
				long totalTime = 0;
				for (int i = 0; i < 100; ++i){
					long start = System.nanoTime();
					for (int j = 0; j < 100; ++j){
						Integer nextInt = (int)(32000*Math.random());
						tester2.put(nextInt, nextInt);
					}
					long end = System.nanoTime();
					totalTime += (end-start);
					tester2 = new BSTHashing<Integer, Integer>();
				}
				System.out.println("Average time for 100 (size = 100)   tables: " + (totalTime / 100) + " ns\n");

				totalTime = 0;
				for (int i = 0; i < 100; ++i){
					long start = System.nanoTime();
					for (int j = 0; j < 1000; ++j){
						Integer nextInt = (int)(32000*Math.random());
						tester2.put(nextInt, nextInt);
					}
					long end = System.nanoTime();
					totalTime += (end-start);
					tester2 = new BSTHashing<Integer, Integer>();
				}
				System.out.println("Average time for 100 (size = 1000)  tables: " + (totalTime / 100) + " ns\n");

				totalTime = 0;
				for (int i = 0; i < 100; ++i){
					long start = System.nanoTime();
					for (int j = 0; j < 10000; ++j){
						Integer nextInt = (int)(32000*Math.random());
						tester2.put(nextInt, nextInt);
					}
					long end = System.nanoTime();
					totalTime += (end-start);
					tester2 = new BSTHashing<Integer, Integer>();
				}
				System.out.println("Average time for 100 (size = 10000) tables: " + (totalTime / 100) + " ns\n");
			}
			
		}
		catch (Exception e){
			System.out.printf("%s", e);
		}
	}

	public static void readFile(BSTHashing<Integer, String> tester) throws FileNotFoundException{
		File pairs = new File("pairs.txt");
		Scanner reader = new Scanner(pairs);
		while (reader.hasNext()){
			Integer key = Integer.parseInt(reader.next());
			String value = reader.next();
			tester.put(key, value);
		}
	}
}