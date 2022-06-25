package sourcepackage;
//KWHashMap interface in the book
public interface KWHashMap<K, V>{
	/**
	 * Getter for the value.
	 * @param key Key of the searching value.
	 * @return Returns value of the given key.
	 */
	V get(Object key);

	/**
	 * Checks if table is empty.
	 * @return Returns true if table is empty, otherwise false.
	 */
	boolean isEmpty();

	/**
	 * Inserts given key-value pair to the hash table.
	 * @param key Key of the entry.
	 * @param value Value of the entry.
	 * @return Returns old value if it exists, otherwise null.
	 */
	V put(K key, V value);

	/**
	 * Remove operation on the table.
	 * @param key Key of the element that will be removed.
	 * @return Returns value of the removed entry.
	 */
	V remove(Object key);

	/**
	 * Returns size of the given table.
	 * @return Size of the table.
	 */
	int size();
}