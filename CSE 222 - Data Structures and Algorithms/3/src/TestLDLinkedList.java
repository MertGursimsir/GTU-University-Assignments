public class TestLDLinkedList{
	@SuppressWarnings("unchecked")
	public static void main(String[] args){
		LDLinkedList<String> tester = new LDLinkedList();
		System.out.println("TESTING THE LDLinkedList CLASS");
		System.out.println("------------------------------");
		System.out.println("This is the linked list that has names.\n8 names are added.");
		tester.addLast("Feynman");		tester.addLast("Hawking");
		tester.addLast("Michio");		tester.addLast("Asimov");
		tester.addLast("Elon");			tester.addLast("Michelangelo");
		tester.addLast("Sagan");		tester.addLast("Camus");
		System.out.printf("LIST:\n%s\n", tester.toString());
		System.out.printf("REMOVED NODES:\n%s\n", tester.toStringRemoved());

		System.out.println("\nNow 2 more names will be added, 1 to the beginning and 1 to the middle.");
		tester.addFirst("Grange");	tester.add(4, "Bowie");
		System.out.printf("LIST:\n%s\n", tester.toString());
		System.out.printf("REMOVED NODES:\n%s\n", tester.toStringRemoved());

		System.out.println("\nNow names Grange, Elon, and Camus will be removed.");
		tester.remove(9); tester.remove(6); tester.remove(0);
		System.out.printf("LIST:\n%s\n", tester.toString());
		System.out.printf("REMOVED NODES:\n%s\n", tester.toStringRemoved());

		System.out.println("\nNow to use removed nodes, add 2 names; 1 to the beginning and 1 to the end.");
		tester.addFirst("Murakami");	tester.addLast("Palahniuk");
		System.out.printf("LIST:\n%s\n", tester.toString());
		System.out.printf("REMOVED NODES:\n%s\n", tester.toStringRemoved());

		System.out.println("\nLastly let's try enhanced for loop for the main list: ");
		for (String test : tester){
			System.out.printf("%s ", test);
		}
		System.out.printf("\n--END OF TESTING--\n");
	}
}