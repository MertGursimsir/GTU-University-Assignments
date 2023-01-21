import java.util.Random;
import java.util.Scanner;
public class testSorts{
	public static void main(String[] args){
		System.out.printf("VALIDATION TEST FOR MERGE SORT, QUICK SORT AND NEW_SORT\n-------------------------------------------------------\n");
		validationTest("merge sort");
		validationTest("quick sort");
		validationTest("new_sort");

		System.out.printf("Do you want performance test? This may take a while (Y for yes) >> ");
		Scanner scan = new Scanner(System.in);
		String control = scan.nextLine();

		if (control.equals("Y")){
			System.out.printf("PERFORMANCE TEST FOR MERGE SORT, QUICK SORT AND NEW_SORT\n--------------------------------------------------------\n");
			long totalSM = 0, totalMM = 0, totalLM = 0;
			long totalSQ = 0, totalMQ = 0, totalLQ = 0;
			long totalSN = 0, totalMN = 0, totalLN = 0;

			for (int i = 0; i < 1000; ++i){
				Integer[] smallArrayMerge = randomArrayGenerator(100);
				Integer[] mediumArrayMerge = randomArrayGenerator(1000);
				Integer[] largeArrayMerge = randomArrayGenerator(10000);

				Integer[] smallArrayQuick = new Integer[100];
				System.arraycopy(smallArrayMerge, 0, smallArrayQuick, 0, 100);
				Integer[] mediumArrayQuick = new Integer[1000];
				System.arraycopy(mediumArrayMerge, 0, mediumArrayQuick, 0, 1000);
				Integer[] largeArrayQuick = new Integer[10000];
				System.arraycopy(largeArrayMerge, 0, largeArrayQuick, 0, 10000);

				Integer[] smallArrayNew = new Integer[100];
				System.arraycopy(smallArrayMerge, 0, smallArrayNew, 0, 100);
				Integer[] mediumArrayNew = new Integer[1000];
				System.arraycopy(mediumArrayMerge, 0, mediumArrayNew, 0, 1000);
				Integer[] largeArrayNew = new Integer[10000];
				System.arraycopy(largeArrayMerge, 0, largeArrayNew, 0, 10000);

				long startSM = System.nanoTime();
				Sortings.mergeSort(smallArrayMerge);
				long endSM = System.nanoTime();
				totalSM+=endSM-startSM;

				long startMM = System.nanoTime();
				Sortings.mergeSort(mediumArrayMerge);
				long endMM = System.nanoTime();
				totalMM+=endMM-startMM;

				long startLM = System.nanoTime();
				Sortings.mergeSort(largeArrayMerge);
				long endLM = System.nanoTime();
				totalLM+=endLM-startLM;

				long startSQ = System.nanoTime();
				Sortings.quickSort(smallArrayQuick);
				long endSQ = System.nanoTime();
				totalSQ+=endSQ-startSQ;

				long startMQ = System.nanoTime();
				Sortings.quickSort(mediumArrayQuick);
				long endMQ = System.nanoTime();
				totalMQ+=endMQ-startMQ;

				long startLQ = System.nanoTime();
				Sortings.quickSort(largeArrayQuick);
				long endLQ = System.nanoTime();
				totalLQ+=endLQ-startLQ;

				long startSN = System.nanoTime();
				Sortings.new_sort(smallArrayNew);
				long endSN = System.nanoTime();
				totalSN+=endSN-startSN;

				long startMN = System.nanoTime();
				Sortings.new_sort(mediumArrayNew);
				long endMN = System.nanoTime();
				totalMN+=endMN-startMN;

				long startLN = System.nanoTime();
				Sortings.new_sort(largeArrayNew);
				long endLN = System.nanoTime();
				totalLN+=endLN-startLN;
			}

			System.out.printf("\nAverage time for 1000 small  size (100)   array sorting with merge sort: %d ns\n", totalSM/1000);
			System.out.printf("Average time for 1000 medium size (1000)  array sorting with merge sort: %d ns\n", totalMM/1000);
			System.out.printf("Average time for 1000 large  size (10000) array sorting with merge sort: %d ns\n\n", totalLM/1000);

			System.out.printf("Average time for 1000 small  size (100)   array sorting with quick sort: %d ns\n", totalSQ/1000);
			System.out.printf("Average time for 1000 medium size (1000)  array sorting with quick sort: %d ns\n", totalMQ/1000);
			System.out.printf("Average time for 1000 large  size (10000) array sorting with quick sort: %d ns\n\n", totalLQ/1000);

			System.out.printf("Average time for 1000 small  size (100)   array sorting with new_sort: %d ns\n", totalSN/1000);
			System.out.printf("Average time for 1000 medium size (1000)  array sorting with new_sort: %d ns\n", totalMN/1000);
			System.out.printf("Average time for 1000 large  size (10000) array sorting with new_sort: %d ns\n\n", totalLN/1000);
		}
		

	}

	private static Integer[] randomArrayGenerator(int size){
		Integer[] array;
		if (size == 100) array = new Integer[100];
		else if (size == 1000) array = new Integer[1000];
		else array = new Integer[10000];
		
		for (int i = 0; i < size; ++i){
			Random generator = new Random();
			array[i] = generator.nextInt(12345);
		}

		return array;
	}

	private static <T> void validationTest(String s){
		Integer arrayTest1[] = {-123, 1234, 1, 140, 4, 5, 3, 0, -1, 32, 4, 13, -12312, 12};
		Integer arrayTest2[] = {-123, 1234, 1, 140, 4, 5, 3, 0, -1, 32, 4, 13, -12312};
		Integer arrayTest3[] = {};
		Integer arrayTest4[] = {12};

		System.out.printf("Array with even number (14) of elements ---> %s", stringArray(arrayTest1));
		if (s.equals("merge sort")) Sortings.mergeSort(arrayTest1);
		else if (s.equals("quick sort")) Sortings.quickSort(arrayTest1);
		else if (s.equals("new_sort")) Sortings.new_sort(arrayTest1);
		System.out.printf("Array after being sorted by %-10s  ---> %s", s, stringArray(arrayTest1));

		System.out.printf("\nArray with odd number (13) of elements  ---> %s", stringArray(arrayTest2));
		if (s.equals("merge sort")) Sortings.mergeSort(arrayTest2);
		else if (s.equals("quick sort")) Sortings.quickSort(arrayTest2);
		else if (s.equals("new_sort")) Sortings.new_sort(arrayTest2);
		System.out.printf("Array after being sorted by %-10s  ---> %s", s, stringArray(arrayTest2));

		System.out.printf("\nEmpty array                             ---> %s", stringArray(arrayTest3));
		if (s.equals("merge sort")) Sortings.mergeSort(arrayTest3);
		else if (s.equals("quick sort")) Sortings.quickSort(arrayTest3);
		else if (s.equals("new_sort")) Sortings.new_sort(arrayTest3);
		System.out.printf("Array after being sorted by %-10s  ---> %s", s, stringArray(arrayTest3));

		System.out.printf("\nArray with 1 element                    ---> %s", stringArray(arrayTest4));
		if (s.equals("merge sort")) Sortings.mergeSort(arrayTest4);
		else if (s.equals("quick sort")) Sortings.quickSort(arrayTest4);
		else if (s.equals("new_sort")) Sortings.new_sort(arrayTest4);
		System.out.printf("Array after being sorted by %-10s  ---> %s", s, stringArray(arrayTest4));

		System.out.printf("\n\n=========================================================================================\n\n");
	}

	private static <T> String stringArray(T[] array){
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < array.length; ++i){
			sb.append(array[i]);
			if (i != array.length-1) sb.append(" | ");
		}
		sb.append("\n");
		return sb.toString();
	}
}