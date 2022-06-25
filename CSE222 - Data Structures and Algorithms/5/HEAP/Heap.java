import java.util.*;
import java.io.*;

@SuppressWarnings("unchecked")
public class Heap<E> extends BinaryTree<E>{
	/**
	 * Inner class for node information
	 */
	protected static class Node<E> extends BinaryTree.Node<E> implements Serializable {
		protected Node<E> parent;
		protected Node<E> left;
		protected Node<E> right;

		/**
		 * Constructor
		 * @param data Data value of the node
		 */
		protected Node(E data) {
			super(data);
			parent = null;
		}

		/**
		 * Overridden string method
		 * @return Returns data value.
		 */
		public String toString () {
			return data.toString();
		}
	}
	protected Node<E> root;

	/**
	 * No parameter constructor
	 */
	public Heap(){
		root = null;
	}

	/**
	 * Finds the node that new node is going to be inserted
	 * @return Found node.
	 */
	private Node<E> endNode(){
		LinkedList<Node<E>> temp = new LinkedList<Node<E>>();
		Node<E> last = root;
		temp.add(root);
		while(temp.size() != 0 && last != null){
			last = temp.get(0);
			temp.removeFirst();
			if (last.left!=null && last.right!=null){
				temp.add(last.left);
				temp.add(last.right);
			}
			else break;
		}
		return last;
	}

	/**
	 * Finds the node at the end of the heap.
	 * @return Last node.
	 */
	private Node<E> lastInHeap(){
		if (root == null) return null;
		if (root.left == null && root.right == null) return root;
		else if (root.left != null && root.right == null) return root.left;
		
		LinkedList<Node<E>> temp = new LinkedList<Node<E>>();
		Node<E> last = root;
		temp.add(root);
		while(temp.size() != 0 && last != null){
			last = temp.get(0);
			temp.removeFirst();
			if (last.left!=null && last.right!=null){
				temp.add(last.left);
				temp.add(last.right);
			}
			else if (last.left != null) temp.add(last.left);
			else break;
		}
		return temp.getLast();
	}

	/**
	 * Insert given data to the proper place in heap.
	 * @param data Data value to be inserted in heap.
	 */
	public void add(E data){
		Node<E> temp = new Node<E>(data);
		Node<E> last = endNode();

		if (root == null){ root = temp; return; }
		else if (last.left == null){ last.left = temp; temp.parent = last;}
		else if (last.right == null){last.right = temp; temp.parent = last;}
		
		while (temp.parent != null && ((Comparable<E>)(temp.parent.data)).compareTo(temp.data) > 0){
			E mortalData = temp.data;
			temp.data = temp.parent.data;
			temp.parent.data = mortalData;
			temp = temp.parent;
		}
	}

	/**
	 * Remove proper value from the heap.
	 */
	public void remove(){
		if (root == null){ System.out.println("Heap is empty."); return; }

		Node<E> last = lastInHeap();
		if (root.left == null && root.right == null){ root = null; return;}
		else if (root.left == null){ root = root.right; return;}
		else if (root.right == null){root = root.left;  return;}

		E mortal = root.data;
		root.data = last.data;
		last.data = mortal;

		if (last.parent.left == last){ last.parent.left = last.parent.right; last.parent.right = null; }
		else last.parent.right = null;

		Node<E> temp = root;
		while(true){
			Node<E> top = temp;

			if (temp.left != null && ((Comparable<E>)temp.left.data).compareTo(top.data) < 0) top = temp.left;
			if (temp.right!= null && ((Comparable<E>)temp.right.data).compareTo(top.data)< 0) top = temp.right;
			if (top != temp){
				E newMortal = top.data;
				top.data = temp.data;
				temp.data = newMortal;
				temp = top;
			}
			else break;
		}
	}

	/**
	 * Merges 2 heaps.
	 * @param other Other heap to be merged with current heap.
	 * @return Merged heap.
	 */
	public Heap<E> merge(Heap<E> other){
		Heap<E> toReturn = new Heap<E>();

		mergeAdd(root, toReturn);
		mergeAdd(other.root, toReturn);

		return toReturn;
	}

	/**
	 * Helper method for merge method.
	 * @param node Node to be added to heap
	 * @param heap Heap that node will be added to
	 */
	private void mergeAdd(Node<E> node, Heap<E> heap){
		if (node != null){
			heap.add(node.data);
			mergeAdd(node.left, heap);
			mergeAdd(node.right, heap);
		}
	}

	/**
	 * Increments the key value of the given element.
	 * @param element Element to be incremented
	 * @param incremented Incremented value of the "element"
	 */
	public void incrementKey(E element, E incremented){
		if (((Comparable<E>)incremented).compareTo(element) < 0) {System.out.println("New value is not greater than old value."); return;}
		
		Node<E> toBeIncremented = search(element, root);
		if (toBeIncremented == null) {System.out.println("There is no such element."); return;}
		toBeIncremented.data = incremented;

		Node<E> temp = toBeIncremented;
		while(true){
			Node<E> top = temp;

			if (temp.left != null && ((Comparable<E>)temp.left.data).compareTo(top.data) < 0) top = temp.left;
			if (temp.right!= null && ((Comparable<E>)temp.right.data).compareTo(top.data)< 0) top = temp.right;
			if (top != temp){
				E newMortal = top.data;
				top.data = temp.data;
				temp.data = newMortal;
				temp = top;
			}
			else break;
		}
	}

	/**
	 * Search for the given element in the ref node
	 * @param element Element to be searched
	 * @param ref Node that given element is searched in
	 * @return Node that element belongs to
	 */
	private Node<E> search(E element, Node<E> ref){
		if (ref == null) return null;
		else if (ref.data.equals(element)) return ref;
		else{
			Node<E> left = search(element, ref.left);
			Node<E> right = search(element, ref.right);
			if (left != null) return left;
			else return right;
		}
	}

	/**
	 * Overridden toString method
	 * @return String representation of the heap
	 */
	public String toString() {
		StringBuilder sb = new StringBuilder();
		toString(root, 1, sb);
		return sb.toString();
	}

	/**
	 * Helper toString method
	 * @param node Node whose data will be added to StringBuilder sb
	 * @param depth Depth of the current node
	 * @param sb StringBuilder to represent returned string with original toString method
	 */
	private void toString(Node<E> node, int depth, StringBuilder sb) {
		for (int i = 1; i < depth; i++) sb.append("-");
		if (node == null) sb.append("null\n");
		else {
			sb.append(node.toString());
			sb.append("\n");
			toString(node.left, depth + 1, sb);
			toString(node.right, depth + 1, sb);
		}
	}
}