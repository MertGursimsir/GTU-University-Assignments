import sourcepackage.*;
@SuppressWarnings("unchecked")
public class test{
	public static void main(String[] args){
		/*************************TEST FOR CONVERSION FROM BINARY TREE TO BINARY SEARCH TREE******************************/
		System.out.println("*********TEST FOR CONVERSION FROM BINARY TREE TO BINARY SEARCH TREE**********");
		System.out.println("TEST 1\n------");
		Integer[] array = {10, 2, 8, 4, 7};
		System.out.printf("Array of elements: ");
		for (int i = 0; i < array.length; ++i) System.out.printf("%d ", array[i]);
		System.out.println("\n==================================================================");

		BinaryTree<Integer> node1 = new BinaryTree(0, null, null);
		BinaryTree<Integer> node2 = new BinaryTree(0, null, null);
		BinaryTree<Integer> node3 = new BinaryTree(0, node1, node2);
		BinaryTree<Integer> node4 = new BinaryTree(0, null, null);
		BinaryTree<Integer> root = new BinaryTree(0, node3, node4);
		System.out.println("STRUCTURE OF THE BINARY TREE");
		System.out.println("----------------------------");
		System.out.println(root);
		System.out.println("==================================================================");

		System.out.println("BINARY SEARCH TREE");
		System.out.println("------------------");
		BinarySearchTree<Integer> bst = convertToBST.convert(root, array);
		System.out.println(bst);



		System.out.println("\n\n\nTEST 2\n------");
		Integer[] array2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		System.out.printf("Array of elements: ");
		for (int i = 0; i < array2.length; ++i) System.out.printf("%d ", array2[i]);
		System.out.println("\n==================================================================");

		node1 = new BinaryTree(0, null, null);
		node2 = new BinaryTree(0, null, node1);
		node3 = new BinaryTree(0, null, node2);
		node4 = new BinaryTree(0, null, node3);
		BinaryTree<Integer> node5 = new BinaryTree(0, null, node4);
		BinaryTree<Integer> node6 = new BinaryTree(0, null, node5);
		BinaryTree<Integer> node7 = new BinaryTree(0, null, node6);
		BinaryTree<Integer> node8 = new BinaryTree(0, null, node7);
		BinaryTree<Integer> node9 = new BinaryTree(0, null, node8);
		root = new BinaryTree(0, null, node9);
		System.out.println("STRUCTURE OF THE BINARY TREE");
		System.out.println("----------------------------");
		System.out.println(root);
		System.out.println("==================================================================");

		System.out.println("BINARY SEARCH TREE");
		System.out.println("------------------");
		bst = convertToBST.convert(root, array2);
		System.out.println(bst);


		System.out.println("\n\n\nTEST 3\n------");
		Integer[] array3 = {42};
		System.out.printf("Array of elements: ");
		for (int i = 0; i < array3.length; ++i) System.out.printf("%d ", array3[i]);
		System.out.println("\n==================================================================");

		
		root = new BinaryTree(0, null, null);
		System.out.println("STRUCTURE OF THE BINARY TREE");
		System.out.println("----------------------------");
		System.out.println(root);
		System.out.println("==================================================================");

		System.out.println("BINARY SEARCH TREE");
		System.out.println("------------------");
		bst = convertToBST.convert(root, array3);
		System.out.println(bst);




		/*************************TEST FOR CONVERSION FROM BINARY SEARCH TREE TO AVL TREE******************************/
		System.out.println("\n\n\n************TEST FOR CONVERSION FROM BINARY SEARCH TREE TO AVL TREE*********");
		System.out.println("TEST 1\n------");
		BinarySearchTree<Integer> bst1 = new BinarySearchTree();
		bst1.add(33); bst1.add(53); bst1.add(61);
		bst1.add(13); bst1.add(21); bst1.add(11);
		bst1.add(8);  bst1.add(9);

		System.out.println("BINARY SEARCH TREE\n------------------\n" + bst1);
		System.out.println("==================================================================");

		bst1.convertAVL();
		System.out.println("AVL TREE\n--------\n" + bst1);
		System.out.println("==================================================================");

		System.out.println("\n\n\nTEST 2\n------");
		BinarySearchTree<Integer> bst2 = new BinarySearchTree();
		bst2.add(4); bst2.add(3); bst2.add(2);
		bst2.add(1); bst2.add(5); bst2.add(6);
		bst2.add(7);

		System.out.println("BINARY SEARCH TREE\n------------------\n" + bst2);
		System.out.println("==================================================================");

		bst2.convertAVL();
		System.out.println("AVL TREE\n--------\n" + bst2);
		System.out.println("==================================================================");

		System.out.println("\n\n\nTEST 3\n------");
		BinarySearchTree<Integer> bst3 = new BinarySearchTree();
		bst3.add(1); bst3.add(2); bst3.add(3);
		bst3.add(4); bst3.add(5); bst3.add(6);

		System.out.println("BINARY SEARCH TREE\n------------------\n" + bst3);
		System.out.println("==================================================================");

		bst3.convertAVL();
		System.out.println("AVL TREE\n--------\n" + bst3);
		System.out.println("==================================================================");

	}
}