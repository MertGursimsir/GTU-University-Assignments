public class testHeap{
	public static void main(String[] args){
		Heap<Integer> tester = new Heap<Integer>();
		System.out.printf("TESTING THE HEAP STRUCTURE\n");
		System.out.printf("--------------------------\n");
		System.out.printf("Adding 6, 18, 20, 28, 29, 37, 26, 76, and 32 to tester heap.\n");
		tester.add(6);
		tester.add(18);
		tester.add(20);
		tester.add(28);
		tester.add(29);
		tester.add(37);
		tester.add(26);
		tester.add(76);
		tester.add(32);
		System.out.printf("Heap after insertions:\n%s", tester);

		System.out.printf("\n\n2 elements will be removed.\n");
		tester.remove();
		tester.remove();
		System.out.printf("After removals:\n%s", tester);

		
		System.out.printf("------------------------------------------------\n");
		Heap<Integer> tester2 = new Heap<Integer>();
		System.out.printf("\nAdding 8 to second tester heap.\n");
		tester2.add(8);
		System.out.printf("Removing one element from second tester heap.\n");
		tester2.remove();
		System.out.printf("After these 2 operations second tester heap:\n%s", tester2);
	
		System.out.printf("\n\nAdding 8, 30, 74, 89, 66, and 39 to second tester heap.\n");
		tester2.add(8);
		tester2.add(30);
		tester2.add(74);
		tester2.add(89);
		tester2.add(66);
		tester2.add(39);
		System.out.printf("Second heap after insertions:\n%s", tester2);

		System.out.printf("\n\nIncrementing key value of element 8 to 80 at the second heap.\n");
		tester2.incrementKey(8, 80);
		System.out.printf("Second heap after key incrementation:\n%s", tester2);

		System.out.printf("------------------------------------------------\n");
		System.out.printf("Merging first and second heaps.\nResult:\n%s", tester.merge(tester2));



		System.out.printf("------------------------------------------------\n");
		Heap<String> tester3 = new Heap<String>();
		System.out.printf("\nAdding Palahniuk, Tarantino, Camus, Hetfield, Angie, and Murakami to last tester heap.\n");
		tester3.add("Palahniuk");
		tester3.add("Tarantino");
		tester3.add("Camus");
		tester3.add("Hetfield");
		tester3.add("Angie");
		tester3.add("Murakami");
		System.out.printf("Last heap after insertions:\n%s", tester3);
		tester3.remove();
		tester3.remove();
		tester3.remove();
		System.out.printf("\n\nAfter 3 removals:\n%s", tester3);
	}


}