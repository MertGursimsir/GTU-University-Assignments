/**
 * <h1>HASHING WITH BINARY SEARCH TREE!</h1>
 * This class uses binary search trees to chain items mapped on the same table slot.
 * @author Mert Gürşimşir
 * @version 1.0 (April 23 2022)
 */
import sourcepackage.*;
@SuppressWarnings("unchecked")
public class BSTHashing<K, V> implements KWHashMap<K, V>{
	/**
	 * Inner class that holds key-value pairs.
	 */
	private static class Entry<K, V> implements Comparable{
		private K key;
		private V value;

		/**
		 * Constructer to create one entry with given key and value.
		 * @param keyValue Key of the entry.
		 * @param valueValue Value of the entry.
		 */
		public Entry(K keyValue, V valueValue){
			key = keyValue;
			value = valueValue;
		}

		/**
		 * Getter for the key.
		 * @return Returns key of the entry.
		 */
		public K getKey(){
			return key;
		}

		/**
		 * Getter for the value.
		 * @return Returns value of the entry.
		 */
		public V getValue(){
			return value;
		}

		/**
		 * Setter for the value.
		 * @param valueValue Value to be set.
		 * @return Returns old value.
		 */
		public V setValue(V valueValue){
			V temp = value;
			value = valueValue;
			return temp;
		}

		/**
		 * Overridden compareTo method to compare entries by their key.
		 * @param other Other object to be compared.
		 */
		public int compareTo(Object other){
			return ((Comparable<K>)key).compareTo(((Entry<K, V>)other).key);
		}

		/**
		 * Overridden toString method.
		 * @return Returns string to represent key-value pair.
		 */
		public String toString(){
			StringBuilder sb = new StringBuilder();
			sb.append(key.toString());
			sb.append("-");
			sb.append(value.toString());
			return sb.toString();
		}
	}

	private BinarySearchTree<Entry<K, V>>[] table;
	private int keyNumber;
	private static final int CAPACITY = 11;
	private static final double THRESHOLD = 3.0;

	/**
	 * No parameter constructor to create table with size 11.
	 */
	public BSTHashing(){
		table = new BinarySearchTree[CAPACITY];
		keyNumber = 0;
	}

	/**
	 * Creates table with given capacity.
	 * @param capacity Capacity of the table.
	 */
	public BSTHashing(int capacity) throws Exception{
		if (capacity <= 0) throw new Exception("Unproper capacity.");
		table = new BinarySearchTree[capacity];
		keyNumber = 0;
	}

	/**
	 * Getter for the value.
	 * @param key Key of the searching value.
	 * @return Returns value of the given key.
	 */
	public V get(Object key){
		int index = key.hashCode() % table.length;
		if (index < 0) index += table.length;

		if (table[index] == null) return null;
		Entry<K, V> temp = table[index].find(new Entry(key, null));
		//find method of the binary search tree is used
		
		if (temp != null) return temp.value;
		else return null;
	}

	/**
	 * Checks if table is empty.
	 * @return Returns true if table is empty, otherwise false.
	 */
	public boolean isEmpty(){
		return keyNumber == 0;
	}

	/**
	 * Inserts given key-value pair to the hash table.
	 * @param key Key of the entry.
	 * @param value Value of the entry.
	 * @return Returns old value if it exists, otherwise null.
	 */
	public V put(K key, V value){
		int index = key.hashCode() % table.length;
		if (index < 0) index += table.length;
		if (table[index] == null) table[index] = new BinarySearchTree<Entry<K, V>>();
		Entry<K, V> temp = table[index].find(new Entry(key, null));

		//If given key is already in the table
		if (temp != null){
			V oldValue = temp.value;
			temp.value = value;
			return oldValue;
		}

		table[index].add(new Entry<K, V>(key, value));
		keyNumber++;
		if (keyNumber > (THRESHOLD*table.length)) rehash();
		return null;
	}

	/**
	 * Rehashing the table if threshold has been exceeded.
	 */
	private void rehash(){
		BinarySearchTree<Entry<K, V>>[] oldTable = table;
		table = new BinarySearchTree[2*oldTable.length + 1];

		keyNumber = 0;
		for (int i = 0; i < oldTable.length; ++i) rehashRecursiveHelper(oldTable[i]);
	}

	/**
	 * Recursive rehash method to put elements to bigger table recursively.
	 * @param searchIn BinaryTree to look for elements.
	 */
	private void rehashRecursiveHelper(BinaryTree<Entry<K, V>> searchIn){
		if (searchIn == null) return;
		else{
			Entry<K, V> temp = searchIn.getData();
			put(temp.key, temp.value);
			rehashRecursiveHelper(searchIn.getRightSubtree());
			rehashRecursiveHelper(searchIn.getLeftSubtree());
		}
	}

	/**
	 * Remove operation on the table.
	 * @param key Key of the element that will be removed.
	 * @return Returns value of the removed entry.
	 */
	public V remove(Object key){
		int index = key.hashCode() % table.length;
		if (index < 0) index += table.length;
		if (table[index] == null) return null;

		//Element exists in the table.
		Entry<K, V> temp = table[index].find(new Entry(key, null));
		if (temp != null){
			table[index].delete(temp);
			keyNumber--;
			if (table[index].getData() == null) table[index] = null;
			return temp.value;
		}
		return null;
	}

	/**
	 * Returns size of the given table.
	 * @return Size of the table.
	 */
	public int size(){
		return table.length;
	}

	/**
	 * Overridden toString method.
	 * @return Returns String that represents the table.
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < table.length; ++i){
			sb.append(table[i]);
			sb.append("\n\n=======================================\n\n");
		}
		return sb.toString();
	}
}