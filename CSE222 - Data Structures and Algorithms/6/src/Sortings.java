/**
 * <h1>SORTING ALGORITHMS MERGE - QUICK - NEW!</h1>
 * This class have methods to sorting an array with merge sort, quick sort, and another new_sort.
 * @author Mert Gürşimşir
 * @version 1.0 (April 23 2022)
 */
@SuppressWarnings("unchecked")
public class Sortings{
	/**
	 * Generic mergeSort method to sort given array in ascending order.
	 * @param array Array to be sorted
	 */
	public static <T extends Comparable<T>> void mergeSort(T[] array) {
		if (array.length > 1) {
			int half = array.length / 2;
			T[] left = (T[]) new Comparable[half];
			T[] right = (T[]) new Comparable[array.length-half];
			System.arraycopy(array,0,left,0,half);
			System.arraycopy(array,half,right,0,array.length-half);
			mergeSort(left);
			mergeSort(right);
			merge(array,left,right);
		}
	}

	/**
	 * Method to merge to parts of the array.
	 * @param array Array to be sorted.
	 * @param left Left part of the array.
	 * @param right Right part of the array.
	 */
	private static <T extends Comparable<T>> void merge(T[] array, T[] left, T[] right) {
		int i = 0, j = 0, k = 0;
		while (i < left.length && j < right.length) {
			if (left[i].compareTo(right[j]) < 0) array[k++] = left[i++];
			else array[k++] = right[j++];
		}
		while (i < left.length)  array[k++] = left[i++];
		while (j < right.length) array[k++] = right[j++];
	}

	/********************************************************************************************/

	/**
	 * This method sorts the array with quick sort algorithm.
	 * @param array Array to be sorted.
	 */
	public static <T extends Comparable<T>> void quickSort(T[] array) {
		recursiveQuickSort(array, 0, array.length-1);
	}

	/**
	 * Helper recursive method for quick sort.
	 * @param array Array to be sorted.
	 * @param first Starting index.
	 * @param last Ending index.
	 */
	private static <T extends Comparable<T>> void recursiveQuickSort(T[] array, int first, int last) {
		if (last <= first) return;
		int index = partition(array, first, last);
		recursiveQuickSort(array, first, index-1);
		recursiveQuickSort(array, index+1, last);
	}

	/**
	 * Partition method for quick sort.
	 * @param array Array to be sorted.
	 * @param first Starting index.
	 * @param last Ending index.
	 * @return Returns index of the pivot value.
	 */
	private static <T extends Comparable<T>> int partition(T[] array, int first, int last) {
		T prior = array[first];
		int up = first, down = last;
		do {
			while (prior.compareTo(array[down]) < 0) --down;
			while ((up < last) && (prior.compareTo(array[up]) >= 0)) ++up;
			if (up < down) swap(array,up,down);
		}while (down > up); 
		swap(array,first,down);
		return down;
	}

	/********************************************************************************************/

	/**
	 * Sorting the array with new sorting algorithm. 
	 * Algorithm finds min element between given 2 indices and replaces it with the starting index. 
	 * Also algorithm finds max element between given 2 indices and replaces it with the ending index.
	 * @param array Array to be sorted.
	 */
	public static <T extends Comparable<T>> void new_sort(T[] array){
		new_sort(array, 0, array.length-1);
	}

	/**
	 * Recursive algorithm to sort array with new_sort algorithm.
	 * @param array Array to be sorted.
	 * @param head Starting index.
	 * @param tail Ending index.
	 */
	private static <T extends Comparable<T>> T[] new_sort(T[] array, int head, int tail){
		if (head > tail) return array;
		else{
			int[] minMax = min_max_finder(array, head, tail);

			swap(array, head, minMax[0]);
			if (minMax[1] == head) minMax[1] = minMax[0];
			swap(array, tail, minMax[1]);

			return new_sort(array, head+1, tail-1);
		}
	}

	/**
	 * Recursive method that returns the indices of minimum and maximum items between the given head and tail items in an array in a single execution together.
	 * @param array Array that minimum and maximum indices will be found.
	 * @param head Starting index.
	 * @param tail Ending index.
	 */
	private static <T extends Comparable<T>> int[] min_max_finder(T[] array, int head, int tail){
		if (tail <= head+1){
			//Base Case
			if (array[head].compareTo(array[tail]) < 0){
				int[] min_max = {head, tail};
				return min_max;
			}
			else{
				int[] min_max = {tail, head};
				return min_max;
			}
		}
		int mid = (head+tail) / 2;
		int[] left = min_max_finder(array, head, mid);
		int[] right = min_max_finder(array, mid+1, tail);
		int[] last = {left[0], left[1]};
		if (array[right[0]].compareTo(array[last[0]]) < 0) last[0] = right[0];
		if (array[right[1]].compareTo(array[last[1]]) > 0) last[1] = right[1];
		return last;
	}

	/********************************************************************************************/

	/**
	 * Swap elements in the array.
	 * @param array Array whose elements will be swapped.
	 * @param ind1 Index of the one of the elements that will be swapped.
	 * @param ind2 Index of the one of the elements that will be swapped.
	 */
	private static <T extends Comparable<T>> void swap(T[] array, int ind1, int ind2){
		T temp = array[ind1];
		array[ind1] = array[ind2];
		array[ind2] = temp;
	}
}