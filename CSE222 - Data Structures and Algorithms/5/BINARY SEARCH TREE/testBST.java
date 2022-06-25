@SuppressWarnings("deprecation")
public class testBST{
	public static void main(String[] args){
		BinarySearchTree<Integer> tester = new BinarySearchTree<Integer>();
		System.out.printf("TESTING BINARY SEARCH TREE\n");
		System.out.printf("--------------------------\n");
		System.out.printf("Adding 25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, and 48 to tree.\n");
		tester.add(25);
		tester.add(20);
		tester.add(36);
		tester.add(10);
		tester.add(22);
		tester.add(30);
		tester.add(40);
		tester.add(5);
		tester.add(12);
		tester.add(28);
		tester.add(38);
		tester.add(48);
		System.out.printf("\nArray representation of the BST:\n%s\n",tester);
		System.out.printf("Tree representation of the BST:\n%s\n",tester.TreeString());

		System.out.printf("Deleting 25 from the tree.\n");
		tester.delete(25);
		System.out.printf("\nArray representation of the BST:\n%s\n",tester);
		System.out.printf("Tree representation of the BST:\n%s\n",tester.TreeString());

		System.out.printf("Deleting 48 from the tree.\n");
		tester.delete(48);
		System.out.printf("\nArray representation of the BST:\n%s\n",tester);
		System.out.printf("Tree representation of the BST:\n%s\n",tester.TreeString());

		if (tester.contains(25)) System.out.printf("Tree contains 25.\n");
		else System.out.printf("Tree doesn't contain 25.\n");

		if ((new Integer(38)).equals(tester.find(38))) System.out.printf("Tree contains 38.\n");
		else System.out.printf("Tree doesn't contain 38.\n");



		BinarySearchTree<String> tester2 = new BinarySearchTree<String>();
		System.out.printf("-----------------------------------------------------------------\n");
		System.out.printf("Adding lay, house, rat, lay, jack, that, milked, and cow to tree.\n");
		tester2.add("lay");
		tester2.add("house");
		tester2.add("rat");
		tester2.add("lay");
		tester2.add("jack");
		tester2.add("that");
		tester2.add("milked");
		tester2.add("cow");
		System.out.printf("\nArray representation of the BST:\n%s\n",tester2);
		System.out.printf("Tree representation of the BST:\n%s\n",tester2.TreeString());

		System.out.printf("Deleting rat from the tree.\n");
		tester2.delete("rat");
		System.out.printf("\nArray representation of the BST:\n%s\n",tester2);
		System.out.printf("Tree representation of the BST:\n%s\n",tester2.TreeString());

		System.out.printf("Deleting house from the tree.\n");
		tester2.delete("house");
		System.out.printf("\nArray representation of the BST:\n%s\n",tester2);
		System.out.printf("Tree representation of the BST:\n%s\n",tester2.TreeString());

		if (tester2.contains("milked")) System.out.printf("Tree contains milked.\n");
		else System.out.printf("Tree doesn't contain milked.\n");

		if ("mert".equals(tester2.find("mert"))) System.out.printf("Tree contains mert.\n");
		else System.out.printf("Tree doesn't contain mert.\n");
	}	
}