/**
 * <h1>CLASS THAT PROVIDES CONVERSION FROM BINARY TREE TO BINARY SEARCH TREE!</h1>
 * @author Mert Gürşimşir
 * @version 1.0 (May 13 2022)
 */

import sourcepackage.*;
import java.util.*;

@SuppressWarnings("unchecked")
public class convertToBST{
	private static int index = 0;

	/**
	 * Static generic method which is presented to the folks of this code
	 * @param binaryTree Binary tree whose structure will be used to construct bst
	 * @param array Array that includes elements of the bst
	 * @return Constructed binary search tree
	 */
	public static <T extends Comparable<T>> BinarySearchTree<T> convert(BinaryTree<T> binaryTree, T[] array){
		index = 0;
		if (array.length == 0) return null;
		
		Arrays.sort(array);
		Q1Recursive(binaryTree, array);

		BinarySearchTree<T> temp = new BinarySearchTree();
		createBST(temp, binaryTree);
		return temp;
	}

	/**
	 * Method to recursively fill the tree with the elements
	 * @param binaryTree Binary tree whose structure will be used to construct bst
	 * @param array Array that includes elements of the bst
	 */
	private static <T extends Comparable<T>> void Q1Recursive(BinaryTree<T> binaryTree, T[] array){
		if (binaryTree == null) return;
		Q1Recursive(binaryTree.getLeftSubtree(), array);
		binaryTree.setData(array[index++]);
		Q1Recursive(binaryTree.getRightSubtree(), array);
	}

	/**
	 * Method to create binary search tree by adding elements in the binary tree properly
	 * @param binaryTree Binary tree whose structure will be used to construct bst
	 * @param bst Binary search tree to be created
	 */
	private static <T extends Comparable<T>> void createBST(BinarySearchTree<T> bst, BinaryTree<T> binaryTree){
		if (binaryTree == null) return;
		bst.add(binaryTree.getData());
		createBST(bst, binaryTree.getLeftSubtree());
		createBST(bst, binaryTree.getRightSubtree());
	}
}