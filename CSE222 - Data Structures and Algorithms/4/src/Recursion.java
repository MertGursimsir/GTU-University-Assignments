/**
 * <h1>RECURSIVE METHODS' CLASS!</h1>
 * This class has methods that are written recursively.
 * @author Mert Gürşimşir
 * @version 1.0 (April 1 2022)
 */

public class Recursion{
	/**
	 * 	Method to search a given string in another given bigger string.
	 * 	@param query Query string that is being searched.
	 *  @param big Big string which we are looking query string in.
	 * 	@param i Number of occurrence of query string.
	 * 	@return ith occurrence of the query string in big string.
	 */
	public int Q1(String query, String big, int i){
		if (query.length() == 0 || i < 1) return -1;
		return Q1Wrapper(query, big, i, 0, 0);
	}

	/**
	 * 	Helper method for the Q1.
	 * 	@param query Query string that is being searched.
	 *  @param big Big string which we are looking query string in.
	 * 	@param i Number of occurrence of query string.
	 * 	@param indexB Holds the index of big string.
	 * 	@param indexQ Holds the index of query string.
	 * 	@return ith occurrence of the query string in big string.
	 */
	private int Q1Wrapper(String query, String big, int i, int indexB, int indexQ){
		if (indexB == big.length() && indexQ != query.length()) return -1;	//out of bounds
		if (indexQ == query.length() && i == 1) return indexB - query.length();	//found the query's ith occurrence
		if (indexQ == query.length() && i != 1){	//found but not ith occurrence
			if (big.charAt(indexB) == query.charAt(0)) return Q1Wrapper(query, big, i-1, indexB, 0);
			else return Q1Wrapper(query, big, i-1, indexB+1, 0);
		}
		//Recursive calls
		if (big.charAt(indexB) == query.charAt(indexQ)) return Q1Wrapper(query, big, i, indexB+1, indexQ+1);
		else return Q1Wrapper(query, big, i, indexB+1, 0);
	}

	/*********************************************************************************************************/

	/**
	 * 	Method to find the number of items in the array between two given integer values.
	 * 	@param array Sorted integer array.
	 * 	@param small First integer .
	 * 	@param big Second integer.
	 * 	@return Number of items in the array between first and second integers.
	 */
	public int Q2(int[] array, int small, int big){
		if (big < small) return Q2Wrapper(array, big, small, 0, array.length-1);
		else return Q2Wrapper(array, small, big, 0, array.length-1);
	}

	/**
	 * 	Helper method for the Q2.
	 * 	@param array Sorted integer array.
	 * 	@param small First integer .
	 * 	@param big Second integer.
	 * 	@param first Index to identify beginning of the array.
	 * 	@param last Index to identify end of the array.
	 * 	@return Number of items in the array between first and second integers.
	 */
	private int Q2Wrapper(int[] array, int small, int big, int first, int last){
		if (first > last) return 0;
		else{
			int mid = (first+last)/ 2;	//finding middle of the array
			if (big == array[mid] || array[mid] > big) return Q2Wrapper(array,small,big,first,mid-1);	//looking left subarray
			else if (small == array[mid] || array[mid] < small) return Q2Wrapper(array,small,big,mid+1, last);	//looking right subarray
			else return 1 + Q2Wrapper(array,small,big,first,mid-1) + Q2Wrapper(array,small,big,mid+1, last);	//looking both right and left subarrays
		}
	}

	/*********************************************************************************************************/

	/**
	 * 	Method to find contiguous subarray/s that the sum of its/theirs items is equal to a given integer value.
	 * 	@param array Unsorted integer array.
	 * 	@param sum Sum that code is looking for in the array.
	 */
	public void Q3(int[] array, int sum){
		Q3Wrapper(array, sum, 0, 1, 0);
	}

	/**
	 * 	Helper method for the Q3.
	 * 	@param array Unsorted integer array.
	 * 	@param sum Sum that code is looking for in the array.
	 * 	@param start Index to identify beginning of the array.
	 * 	@param end Index to identify end of the array.
	 * 	@param total Total sum so far.
	 */
	private void Q3Wrapper(int[] array, int sum, int start, int end, int total){
		if (start == array.length) return;	//out of bounds
		if (start+1 == end){	// first start to look for 1 subarray
			total = array[start];
			if (array[start] == sum) System.out.println(array[start]);
		}
		if (end != array.length && total + array[end] == sum){	// if so far values provide sum
			for (int k = start; k <= end; ++k) System.out.printf("%d ", array[k]);
			System.out.printf("\n");
		}

		//Recursive calls
		if (end == array.length) Q3Wrapper(array, sum, start+1, start+2, 0);
		else Q3Wrapper(array, sum, start, end+1, total+array[end]);
	}

	/*********************************************************************************************************/

	/**
	 * 	Method to fill given array with colored-blocks with length at least 3.
	 * 	@param arrayBlocks Array of empty blocks.
	 * 	@param L Length of the given array.
	 */
	public void Q5(int[] arrayBlocks, int L){
		for (int i = 3; i <= L; ++i) Q5Wrapper(arrayBlocks, L, 0, i);
	}

	/**
	 * 	Helper method for the Q5.
	 * 	@param arrayBlocks Array of empty blocks.
	 * 	@param L Length of the given array.
	 * 	@param index Current index.
	 * 	@param lengthColored Length of the colored-blocks.
	 */
	private void Q5Wrapper(int[] arrayBlocks, int L, int index, int lengthColored){
		if (lengthColored > L || lengthColored < 3 || index >= L) return;	//out of bounds
		else if (index + lengthColored > L) return;	//out of bounds
		else{
			//filling temporary array with a configuration
			int[] temp = new int[L];
			for (int i = 0; i < L; ++i){
				if (i < index || i >= index+lengthColored) temp[i] = arrayBlocks[i];
				else temp[i] = 1;
			}
			printer(temp); //prints configuration
			//Recursive calls
			Q5Wrapper(arrayBlocks, L, index+1, lengthColored);
			Q5Wrapper(temp, L, index+lengthColored+1, lengthColored);
			Q5Wrapper(temp, L, index+lengthColored+1, lengthColored+1);
			Q5Wrapper(temp, L, index+lengthColored+1, lengthColored-1);
		}
	}

	/**
	 * 	Printer method to print 1D array.
	 * 	@param array Array to be printed X for colored blocks.
	 */
	private void printer(int[] array){
		for (int i = 0; i < array.length*3; ++i) System.out.printf("-");
		System.out.println();
		for (int i = 0; i < array.length  ; ++i) System.out.printf("|%c|", (array[i]==0) ? ' ' : 'X');
		System.out.println();
		for (int i = 0; i < array.length*3; ++i) System.out.printf("-");
		System.out.println("\n");
	}
}