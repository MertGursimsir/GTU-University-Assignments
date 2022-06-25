/**
 * <h1>HASHING WITH HYBRID OF DOUBLE AND COALESCED HASHINGS!</h1>
 * This class uses hybrid of double and coalesced hashings to deal with collisions.
 * @author Mert Gürşimşir
 * @version 1.0 (April 23 2022)
 */
import sourcepackage.KWHashMap;
@SuppressWarnings("unchecked")
public class HybridHash<K, V> implements KWHashMap<K, V>{
	/**
	 * Inner class that holds key-value pairs and next item.
	 */
	private static class Entry<K, V>{
		private K key;
		private V value;
		private Entry<K, V> next;
		private int nextIndex;

		/**
		 * Constructer to create one entry with given key and value.
		 * @param keyValue Key of the entry.
		 * @param valueValue Value of the entry.
		 */
		public Entry(K keyValue, V valueValue){
			key = keyValue;
			value = valueValue;
			next = null;
			nextIndex = -1;
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
		 * Overridden toString method.
		 * @return Returns string to represent key-value pair.
		 */
		public String toString(){
			StringBuilder sb = new StringBuilder();
			sb.append(key.toString());
			sb.append(" - ");
			sb.append(value.toString());
			return sb.toString();
		}
	}

	private Entry<K, V>[] table;
	private int keyNumber;
	private static final int CAPACITY = 11;
	private static final double THRESHOLD = 0.75;

	/**
	 * No parameter constructor to create table with size 11.
	 */
	public HybridHash(){
		table = new Entry[CAPACITY];
		keyNumber = 0;
	}

	/**
	 * Creates table with given capacity.
	 * @param capacity Capacity of the table.
	 */
	public HybridHash(int capacity) throws Exception{
		if (capacity <= 0) throw new Exception("Unproper capacity.");
		table = new Entry[capacity];
		keyNumber = 0;
	}

	/**
	 * @return Returns the largest prime number smaller than 0.8*tablesize
	 */
	private int primeNumber(){
		int prime_number = 1;
		boolean isPrime;
		for (int i = (int)(table.length*0.8); i > 0; --i){
			isPrime = true;
			for (int j = 2; j < i && isPrime; ++j){
				if (i % j == 0) isPrime = false;
			}
			if (isPrime){ prime_number = i; break; }
		}
		return prime_number;
	}

	/**
	 * Finds the index that given key belongs to.
	 * @param key Key of the searched index entry.
	 * @return Returns the index that given key belongs to.
	 */
	private int indexFinder(Object key){
		int prime_number = primeNumber();
		int keyHash = key.hashCode();
		int hash1 = keyHash % table.length;
		int hash2 = prime_number - (keyHash % prime_number);
		int index = (hash1 + hash2) % table.length;
		int i = 2;
		if (index < 0) index += table.length;

		//Probing the table until empty entry or the entry that has the same key is found.
		while (table[index] != null && !key.equals(table[index].key)){
			index = (hash1 + i*hash2) % table.length;
			i++;
			if (index < 0) index += table.length;
		}
		return index;
	}

	/**
	 * Finds the index of the given key without any probe.
	 * @param key Key of the searched index entry
	 * @return Returns the index of the given key without any probe
	 */
	private int hash(Object key){
		int prime_number = primeNumber();
		int keyHash = key.hashCode();
		int hash1 = keyHash % table.length;
		int hash2 = prime_number - (keyHash % prime_number);
		int index = (hash1 + hash2) % table.length;
		return (index < 0) ? index+table.length : index;
	}

	/**
	 * Finds the given key in the table with using next informations in the entries.
	 * @param key Key of the searched entry.
	 * @param start Starting entry of the table.
	 * @return Index of the found entry.
	 */
	private int whereIsElement(Object key, int start){
		while (start != -1 && table[start] != null && !table[start].key.equals(key)) start = table[start].nextIndex;
		return (start == -1 || table[start] == null) ? -1 : start;
	}

	/**
	 * Getter for the value, uses links during search.
	 * @param key Key of the searching value.
	 * @return Returns value of the given key.
	 */
	public V get(Object key){
		int index = hash(key);
		Entry<K, V> temp = table[index];
		while (temp != null && !key.equals(temp.key)) temp = temp.next;
		if (temp == null) return null;
		else return temp.value;
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
		int firstHash = hash(key);
		int index = whereIsElement(key, firstHash);

		//Entry already exists
		if (index != -1){
			V old = table[index].value;
			table[index].value = value;
			return old;
		}

		//Entry doesn't exist
		index = indexFinder(key);
		Entry<K, V> temp = table[firstHash];
		if (temp != null){
			while (temp.next != null) temp = temp.next;
			table[index] = new Entry<K, V>(key, value);
			temp.next = table[index];
			temp.nextIndex = index;
		}
		else table[firstHash] = new Entry<K, V>(key, value);
		keyNumber++;
		double loadFactor = (double)(keyNumber) / table.length;
		if (loadFactor > THRESHOLD) rehash();

		return null;
	}

	/**
	 * Rehashing the table if threshold has been exceeded.
	 */
	private void rehash(){
		Entry<K, V>[] old = table;
		table = new Entry[2*old.length + 1];

		//Copying all the elements
		keyNumber = 0;
		for (int i = 0; i < old.length; ++i){
			if (old[i] != null) put(old[i].key, old[i].value);
		}
	}

	/**
	 * Remove operation on the table.
	 * @param key Key of the element that will be removed.
	 * @return Returns value of the removed entry.
	 */
	public V remove(Object key){
		int firstHash = hash(key);
		int index = whereIsElement(key, firstHash);

		//Entry does not exist
		if (index == -1) return null;
		V returnedValue = table[index].value;
		
		//Entry exists, reconnecting pointers
		Entry<K, V> temp = table[firstHash];
		if (key.equals(temp.key)){
			Entry<K, V> mortal = table[firstHash].next;
			if (table[firstHash].next != null){
				int toDelete = whereIsElement(table[firstHash].next.key, hash(table[firstHash].next.key));
				table[toDelete] = null;
			}
			table[index] = table[index].next;
		}
		else{
			while (!temp.next.key.equals(key)) temp = temp.next;
			Entry<K, V> mortal = table[index].next;
			if (table[index].next != null){
				int toDelete = whereIsElement(table[index].next.key, hash(table[index].next.key));
				table[toDelete] = null;
			}
			temp.next = table[index] = mortal;
			temp.nextIndex = index;
		}
		keyNumber--;
		return returnedValue;
	}

	/**
	 * Returns size of the given table.
	 * @return Size of the table.
	 */
	public int size(){
		return keyNumber;
	}

	/**
	 * Overridden toString method.
	 * @return Returns String that represents the table.
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < table.length; ++i){
			sb.append(i);
			sb.append(" --> ");
			sb.append(table[i]);
			sb.append(" | NEXT : ");
			if (table[i] != null) sb.append(table[i].next);
			else sb.append("null");
			sb.append("\n");
		}
		return sb.toString();
	}
}