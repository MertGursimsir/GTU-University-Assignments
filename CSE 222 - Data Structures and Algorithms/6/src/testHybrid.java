import java.util.Scanner;
public class testHybrid{
	public static void main(String[] args){
		try{
			System.out.printf("TEST OF THE HYBRID HASHING\n");
			System.out.printf("--------------------------\n");
			System.out.printf("VALIDATION TEST WITH ELEMENTS IN THE PDF\n\n");
			HybridHash<Integer, String> tester = new HybridHash<Integer, String>(10);
			tester.put(3, "valueOf3");
			tester.put(12, "valueOf12");
			tester.put(13, "valueOf13");
			tester.put(25, "valueOf25");
			tester.put(23, "valueOf23");
			tester.put(51, "valueOf51");

			System.out.printf("After adding elements to the hash table with size 10 (index --> {key - value} | NEXT : {next entry}):\n\n");
			System.out.printf("%s", tester);

			System.out.printf("\nLet's get value of the key 12: %s\n", tester.get(12));
			System.out.printf("Let's get value of the key 40: %s\n", tester.get(40));

			String temp = tester.remove(40);
			System.out.printf("\nLet's remove non-existing key (40).\nReturned element of remove(40): %s\n", temp);
			temp = tester.remove(25);
			System.out.printf("\nLet's remove existing key (25).\nReturned element of remove(25): %s\n", temp);
			System.out.printf("\nTable after these removals:\n\n%s", tester);
			temp = tester.remove(23);
			System.out.printf("\nLet's remove another existing key (23).\nReturned element of remove(23): %s\n", temp);
			System.out.printf("\nTable after this removal:\n\n%s", tester);

			tester.put(25, "toExceedThreshold"); tester.put(23, "toExceedThreshold"); tester.put(31, "toExceedThreshold"); tester.put(32, "toExceedThreshold");
			System.out.printf("\nLet's try to exceed threshold with adding more dummy elements. Table after rehash:\n\n%s", tester);

			tester.remove(51);
			System.out.printf("\nLet's remove key 51.\n");
			System.out.printf("\nTable after this removal:\n\n%s", tester);
			tester.remove(13);
			System.out.printf("\nLet's remove key 13.\n");
			System.out.printf("\nTable after this removal:\n\n%s", tester);
			tester.remove(32);
			System.out.printf("\nLet's remove key 32.\n");
			System.out.printf("\nTable after this removal:\n\n%s", tester);
			tester.remove(25);
			tester.put(12, "changedValue");
			System.out.printf("\nLet's remove key 25 and change value of key 12.\n");
			System.out.printf("\nTable:\n\n%s", tester);

			/***************************************************************************************************************************/

			System.out.printf("Do you want performance test? This may take a while (Y: yes, N: no) >> ");
			Scanner scan = new Scanner(System.in);
			String control = scan.nextLine();

			if (control.equals("Y")){
				System.out.printf("\n\nPERFORMANCE TEST\n\n");
				HybridHash<Integer, Integer> tester2 = new HybridHash<Integer, Integer>();
			
				long totalTime = 0;
				for (int i = 0; i < 100; ++i){
					long start = System.nanoTime();
					for (int j = 0; j < 100; ++j){
						Integer nextInt = (int)(32000*Math.random());
						tester2.put(nextInt, nextInt);
					}
					long end = System.nanoTime();
					totalTime += (end-start);
					tester2 = new HybridHash<Integer, Integer>();
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
					tester2 = new HybridHash<Integer, Integer>();
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
					tester2 = new HybridHash<Integer, Integer>();
				}
				System.out.println("Average time for 100 (size = 10000) tables: " + (totalTime / 100) + " ns\n");
			}

			

		}
		catch(Exception e){
			System.out.printf("%s\n", e);
		}
	}
}