public class sort{
    public static void main(String[] args){
        int[] ar = {1 ,5, 12, 4, 4, 0, 10, -100};
        int size = ar.length;

        for (int nextPos = 1; nextPos < size; ++nextPos){
            int temp = nextPos;
            int nextVal = ar[nextPos];
            while (temp > 0 && nextVal < ar[temp-1]){
                ar[temp] = ar[temp-1];
                temp--;
            }
            ar[temp] = nextVal;
        }

        for (int i = 0; i< size; ++i){
            System.out.print(ar[i] + " ");
        }
        
    }
}