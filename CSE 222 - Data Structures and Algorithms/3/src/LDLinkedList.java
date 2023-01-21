import java.util.List;
import java.util.AbstractList;
import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * <h1>LAZY DELETION LINKED LIST!</h1>
 * This class is implementation of linked list with lazy deletion strategy.
 * @author Mert Gürşimşir
 * @version 1.0 (March 19 2022)
 */
@SuppressWarnings("unchecked")
public class LDLinkedList<E> extends AbstractList<E> implements List<E>{
	private Node<E> head = null;
	private Node<E> tail = null;
	private int size = 0;
	private Node<E> removedHead = null;
	private int removedSize = 0;

	/**
	 *  Inner iterator class for LinkedList
	 */
	private class LDListIter implements ListIterator<E>{
		private Node<E> next;
		private Node<E> lastReturned;
		private int index = 0;

		/**
		 *	Constructor of iterator class.
		 * 	Iterate iterator ith times.
		 * 	@param i given index value
		 */
		public LDListIter(int i) {
			if (i < 0 || i > size) throw new IndexOutOfBoundsException("Invalid index " + i);
			
			lastReturned = null; 

			if (i == size) {
				index = size;
				next = null;
			}
			else { // Start at the beginning
				next = head;
				for (index = 0; index < i; index++)
					next = next.next;
			}
		}
		/**
		 * 	Adds parameter element to the list
		 * 	@param e Object to be added to list
		 */
		public void add(E e){
			Node<E> temp = removedHead;
			if (temp == null) temp = new Node<E>(e);
			else{
				removedHead = removedHead.next;
				if (removedHead != null) removedHead.prev = null;
				temp.data = e;
				temp.next = null;
				temp.prev = null;
				removedSize--;
			}

			if (head == null){	//if list is empty
				head = temp;
				tail = head;
			}
			else if (next == head){	//if adding to head
				temp.next = next;
				next.prev = temp;
				head = temp;
			}
			else if (next == null){	//if adding to tail
				tail.next = temp;
				temp.prev = tail;
				tail = temp;
			}
			else{	//if adding to middle
				temp.prev = next.prev;
				next.prev.next = temp;
				temp.next = next;
				next.prev = temp;
			}
			index++;
			size++;
			lastReturned = null;
		}

		/**
		 * 	Replaces the last item returned with the specified element
		 * 	@param e Object to be set.
		 */
		public void set(E e){ 
			if (lastReturned == null) throw new IllegalStateException();
			lastReturned.data = e;
		}
		/**
		 * 	Removes last item returned by next() or previous()
		 */
		public void remove(){ 
			if (lastReturned == null) throw new IllegalStateException();
			if (lastReturned != null){
				if (next == null || next.prev == lastReturned) index--;
				if (lastReturned.next == null){
					tail = lastReturned.prev;
					lastReturned.prev.next = null;
				}
				else if (lastReturned.prev == null){
					head = lastReturned.next;
					lastReturned.next.prev = null;
				}
				else{
					lastReturned.prev.next = lastReturned.next;
					lastReturned.next.prev = lastReturned.prev;
				}

				if (removedHead == null){
					lastReturned.next = lastReturned.prev = null;
					removedHead = lastReturned;
				}
				else{
					lastReturned.next = removedHead;
					lastReturned.next.prev = lastReturned;
					lastReturned.prev = null;
					removedHead = lastReturned;
				}
				removedSize++;
				size--;
				//lastReturned = null;
			}
		}
		/**
		 * 	Returns index of previous element
		 * 	@return previous index.
		 */
		public int previousIndex(){ 
			if (!hasPrevious()) return -1;
			return index-1;
		}
		/**
		 * 	Returns index of next element
		 *	@return next index
		 */
		public int nextIndex(){ 
			if (!hasNext()) return size;
			return index;
		}
		/**
		 * 	Returns previous element and move cursor backward
		 * 	@return previous element of the cursor
		 */
		public E previous(){ 
			if (!hasPrevious()) throw new NoSuchElementException();
			if (next == null) next = tail;
			else next = next.prev;
			lastReturned = next;
			index--;
			return lastReturned.data;
		}
		/**
		 * 	Returns next element and move cursor forward
		 * 	@return next element
		 */
		public E next(){ 
			if (!hasNext()) throw new NoSuchElementException();
			lastReturned = next;
			next = next.next;
			index++;
			return lastReturned.data;
		}
		/**
		 * 	Returns true if there is previous element
		 * 	@return boolean to indicate if there is previous element
		 */
		public boolean hasPrevious(){ 
			return (next == null && size != 0) || next.prev != null;
		}
		/**
		 * 	Returns true if there is next element
		 * 	@return boolean to indicate if there is next element
		 */
		public boolean hasNext(){ 
			return next != null;
		}

	}

	/**
	 * 	Inner node class that indicates nodes of the linked list
	 */
	private static class Node<E> {
		private E data;
		private Node<E> next = null;
		private Node<E> prev = null;

		/**
		 * 	Constructor of the node class
		 * 	@param dataItem data reference of the node
		 */
		private Node(E dataItem) {
			data = dataItem;
		}
	}

	/**
	 * 	Adds specified element to the given index
	 * 	@param index specified position
	 * 	@param obj element to be inserted
	 */
	public void add(int index, E obj){ 
		listIterator(index).add(obj);
	}
	/**
	 * 	Removes element at the specified index
	 * 	@param index specified position
	 * 	@return element that is removed
	 */
	public E remove(int index){
		LDListIter tempIter = new LDListIter(0);
		LDListIter tempIterReturn = new LDListIter(index);
		if (index < 0 || index >= size) throw new IndexOutOfBoundsException("Out of bounds.");
		for (int i = 0; i <= index; ++i){
			tempIter.next();
		}
		tempIter.remove();
		if (tempIterReturn.lastReturned != null) return tempIterReturn.lastReturned.data;
		else if (tempIterReturn.next != null) return tempIterReturn.next.data;
		else return null;
	}
	/**
	 * 	Returns element at the given index
	 * 	@param index specified position
	 * 	@return element at the specified position
	 */
	public E get(int index){ 
		return listIterator(index).next();
	}
	/**
	 * 	Replace element at the given index with given element
	 * 	@param index specified position
	 * 	@param element element that will be replaced
	 * 	@return element that is set
	 */
	public E set(int index, E element){
		LDListIter tempIter = new LDListIter(0);
		LDListIter tempIterReturn = new LDListIter(index);
		if (index < 0 || index >= size) throw new IndexOutOfBoundsException("Out of bounds.");
		for (int i = 0; i <= index; ++i){
			tempIter.next();
		}
		tempIter.set(element);
		if (tempIterReturn.lastReturned != null) return tempIterReturn.lastReturned.data;
		else if (tempIterReturn.next != null) return tempIterReturn.next.data;
		else return null;
	}
	/**
	 * 	Adds element to the beginning
	 * 	@param obj specified element
	 */
	public void addFirst(E obj) {
		add(0, obj);
	}
	/**
	 * 	Adds element to the end
	 * 	@param obj specified element
	 */
	public void addLast(E obj) {
		add(size, obj);
	}
	/**
	 * 	Returns first element
	 * 	@return first element
	 */
	public E getFirst() {
		return head.data;
	}
	/**
	 * 	Returns last element
	 * 	@return last element
	 */
	public E getLast() {
		return tail.data;
	}
	/**
	 * 	Returns number of elements
	 * 	@return size of the list
	 */
	public int size(){ 
		return size;
	}
	/**
	 * 	Returns the number of elements in the list that keeps removed elements
	 *	@return number of removed elements
	 */
	public int removedSize(){
		return removedSize;
	}
	/**
	 * 	Returns list iterator of the list
	 * 	@param index specified index
	 * 	@return LDListIter at the specified index
	 */
	public LDListIter listIterator(int index){ 
		return new LDListIter(index);
	}

	/**
	 * 	Overridden string method
	 * 	@return String that keeps elements of the list
	 */
	public String toString(){
		Node<E> temp = head;
		StringBuilder result = new StringBuilder();
		while (temp != null) {
			result.append(temp.data);
			if (temp.next != null)
				result.append(" --> ");
			temp = temp.next;
		}
		return result.toString();
	}
	/**
	 * 	Method to show returned list elements as a string
	 * 	@return String that keeps returned elements
	 */
	public String toStringRemoved(){
		Node<E> temp = removedHead;
		StringBuilder result = new StringBuilder();
		while (temp != null) {
			result.append(temp.data);
			if (temp.next != null)
				result.append(" --> ");
			temp = temp.next;
		}
		return result.toString();
	}

	/**
	 * 	Overridden clone method
	 * 	@return shallow copy of the linked list
	 */
	public LDLinkedList clone(){
		LDLinkedList copy = new LDLinkedList();
		copy.head = head;
		copy.tail = tail;
		copy.size = size;
		copy.removedHead = removedHead;
		copy.removedSize = removedSize;
		return copy;
	} 
}