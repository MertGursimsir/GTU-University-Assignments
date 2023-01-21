@SuppressWarnings("unchecked")
public class BinarySearchTree<E> implements SearchTree<E>{
	private E[] array;
	private int size;
	private int capacity;
	private int lastIndex;

	private E[] buffer = (E[]) new Object[10];
	private int bufferSize = 0;
	private int bufferCapacity = 10;

	/**
	 * No parameter constructor.
	 * Sets size to 0 and starts with the capacity 10.
	 */
	public BinarySearchTree(){
		size = 0;
		lastIndex = -1;
		capacity = 10;
		array = (E[]) new Object[capacity];
	}

	/**
	 * Constructor.
	 * Sets size to 0 and starts with given capacity.
	 */
	public BinarySearchTree(int capacityValue) throws Exception{
		size = 0;
		lastIndex = -1;
		if (capacity < 1) throw new Exception("Unproper capacity");
		capacity = capacityValue;
		array = (E[]) new Object[capacity];
	}

	/**
	 * Increases the capacity of the tree array.
	 */
	private void enlarge(){
		capacity = capacity*2;
		E[] temp = (E[]) new Object[capacity];
		for (int i = 0; i <= lastIndex; ++i) temp[i] = array[i];
		array = temp;
	}

	/**
	 * Finds target and returns it.
	 * @param target Target value to be found.
	 * @return Found element.
	 */
	public E find(E target){
		return find(target, 0);
	}

	/**
	 * Helper recursive find method.
	 * @param target Target value to be found.
	 * @param index Index that we are looking at in the array.
	 * @return Found element.
	 */
	private E find(E target, int index){
		if (index >= array.length) return null;
		else if (array[index] == null) return null;
		else if (((Comparable<E>)target).compareTo(array[index]) == 0) return target;
		else if (((Comparable<E>)target).compareTo(array[index]) < 0) return find(target, index*2+1);
		else return find(target, index*2+2);
	}

	/**
	 * Finds target and returns true if it exists in the tree.
	 * @param target Target value to be found.
	 * @return true if element exists in tree, otherwise false
	 */
	public boolean contains(E target){
		return contains(target, 0);
	}

	/**
	 * Helper recursive contains method.
	 * @param target Target value to be found.
	 * @return true if element exists in current index, otherwise false
	 */
	private boolean contains(E target, int index){
		if (index >= array.length) return false;
		else if (array[index] == null) return false;
		else if (((Comparable<E>)target).compareTo(array[index]) == 0) return true;
		else if (((Comparable<E>)target).compareTo(array[index]) < 0) return contains(target, index*2+1);
		else return contains(target, index*2+2);
	}

	/**
	 * Inserts given item to the tree.
	 * @param item Item to be inserted to tree.
	 * @return true if item successfully inserted, otherwise false
	 */
	public boolean add(E item){
		Comparable<E> temp = (Comparable<E>)item;
		if (capacity <= lastIndex*2 + 2) enlarge();
		if (size == 0){
			array[0] = item;
			lastIndex = 0;
		}
		else{
			//Finding proper place and inserting the item
			int index = 0;
			boolean flag = true;
			while (flag){
				if (temp.compareTo(array[index]) > 0){
					index = 2*index + 2;
					if (array[index] == null){
						array[index] = item;
						if (lastIndex < index) lastIndex = index;
						flag = false;
					}
				}
				else if (temp.compareTo(array[index]) < 0){
					index = 2*index + 1;
					if (array[index] == null){
						array[index] = item;
						if (lastIndex < index) lastIndex = index;
						flag = false;
					}
				}
				else return false;
			}
		}
		size++;
		return true;
	}

	/**
	 * Deletes given target value from the tree and returns it.
	 * @param target Value to be deleted.
	 * @return Returns deleted item
	 */
	public E delete(E target){
		E found = null;

		//Finds the item
		for (int i = 0; i <= lastIndex; ++i){
			if (array[i] == null) break;
			else if (array[i].equals(target)){
				found = array[i];
				changer(i);
				size--;
				break;
			}
			else if ((((Comparable<E>)target).compareTo(array[i]) < 0)) i = i*2;
			else i = i*2+1;
		}

		if (found == null) return null;

		int temp = lastIndex;
		for (int i = 0; i <= temp; ++i) if (array[i] != null) lastIndex = i;
		
		return found;
	}

	/**
	 * Redesign the tree array in proper manner.
	 * @param index Index to redesign the array from.
	 */
	private void changer(int index){
		//Deleted node has no children
		if (index*2+1 >= array.length || index*2+2 >= array.length) {
			array[index] = null; 
			return;
		}
		
		//Deleted node has no children
		else if (array[index*2 + 1] == null && array[index*2 + 2] == null){
			array[index] = null;
			return;
		}

		//Deleted node has only left child
		else if (array[index*2+1] != null && array[index*2+2] == null){
			int maxAtLeft = findMax(index*2+1);
			array[index] = array[maxAtLeft];
		}

		//Deleted node has only right child
		else if (array[index*2+1] == null && array[index*2+2] != null){
			int minAtRight = findMin(index*2+2);
			array[index] = array[minAtRight];
		}

		//Deleted node has 2 children
		else{
			int minAtRight = findMin(index*2+2);
			array[index] = array[minAtRight];
		}

		deleteToBuffer(index);
		if (array[0] == null) { lastIndex = -1; size = 0; }
		for (int i = 0; i < bufferSize; ++i) add(buffer[i]);

		emptyBuffer();
	}

	/**
	 * Adding elements to buffer and deletes them from tree array.
	 * @param index Index to indicate starting point.
	 */
	private void deleteToBuffer(int index){
		for (int i = index; i <= lastIndex; ++i){
			if (array[i] != null) addBuffer(array[i]);
			array[i] = null;
		}
	}

	/**
	 * Finds maximum in the tree starting from given index.
	 * @param index Index to indicate starting point
	 * @return Returns index of the maximum element.
	 */
	private int findMax(int index){
		while (index*2+2<=lastIndex && array[index*2+2] != null) index = index*2+2;
		return index;
	}

	/**
	 * Finds minimum in the tree starting from given index.
	 * @param index Index to indicate starting point
	 * @return Returns index of the minimum element.
	 */
	private int findMin(int index){
		while (index*2+1<=lastIndex && array[index*2+1] != null) index = index*2+1;
		return index;
	}

	/**
	 * Removes given element from the tree and returns true if operation is successful.
	 * @param target to be deleted.
	 * @return true if target succesfully removed, false otherwise
	 */
	public boolean remove(E target){
		E result = delete(target);
		if (result == null) return false;
		else return true;
	}

	/**
	 * Empty the buffer
	 */
	private void emptyBuffer(){
		bufferSize = 0;
	}

	/**
	 * Adds given item to buffer array
	 * @param item Item to be inserted to buffer array
	 */
	private void addBuffer(E item){
		if (bufferSize >= bufferCapacity) enlargeBuffer();
		buffer[bufferSize] = item;
		bufferSize++;
	}

	/**
	 * Increases the capacity of the buffer array.
	 */
	private void enlargeBuffer(){
		bufferCapacity = bufferCapacity*2;
		E[] temp = (E[]) new Object[bufferCapacity];
		for (int i = 0; i < bufferSize; ++i) temp[i] = buffer[i];
		buffer = temp;
	}

	/**
	 * Overridden toString method
	 * @return String representation of the binary search tree.
	 */
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i <= lastIndex; ++i) {
			sb.append(array[i]);
			if (i != lastIndex) sb.append(" - ");
		}
		sb.append("\n");
		return sb.toString();
	}

	/**
	 * Method to represent tree as string
	 * @return String representation of the binary search tree
	 */
	public String TreeString() {
		StringBuilder sb = new StringBuilder();
		TreeString(0, 1, sb);
		return sb.toString();
	}

	/**
	 * Helper overloaded TreeString method
	 * @param node Index of the array whose data will be added to StringBuilder sb
	 * @param depth Depth of the current node
	 * @param sb StringBuilder to represent returned string with original TreeString method
	 */
	private void TreeString(int index, int depth, StringBuilder sb) {
		for (int i = 1; i < depth; i++) sb.append("-");
		if (array[index] == null) sb.append("null\n");
		else {
			sb.append(array[index].toString());
			sb.append("\n");
			TreeString(2*index+1, depth + 1, sb);
			TreeString(2*index+2, depth + 1, sb);
		}
	}
}