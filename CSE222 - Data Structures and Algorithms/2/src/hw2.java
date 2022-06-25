public class hw2{
	public static void main(String args[]){
		int[] array = {1, 2, 3, -5, -4, 10, -2, -9, 13, -11};
		pairOfSum(array,11);
		System.out.println("---------------------------------");
		pairOfSumRecursive(array, 11, 10);
	}

	public static void pairOfSum(int[] array, int sum){
		long start = System.nanoTime();

		for (int i = 0; i < array.length-1; ++i){
			for (int j = i+1; j < array.length; ++j){
				if (array[i] + array[j] == sum)
					System.out.printf("Sum of indexes %d and %d equals to sum : %d + %d = %d\n", i,j,array[i],array[j],sum);
			}
		}

		long end = System.nanoTime();
		long total = end - start;
		System.out.println(total);
	}
	public static void pairOfSumRecursive(int[] array, int sum, int n){
		//n : size,  i : starting index
		int i = array.length - n;
		if (n == 0) return;
		for(int j = i+1; j < array.length; ++j){
			if (array[i] + array[j] == sum)
				System.out.printf("Sum of indexes %d and %d equals to sum : %d + %d = %d\n"
								, i,j,array[i],array[j],sum);
		}
		pairOfSumRecursive(array, sum, n-1);
	}
}