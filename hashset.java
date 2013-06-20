//Program to find x in a[] s.t. a[i]+a[j]=x
import java.util.HashMap;
public class hashset{
	public static void main(String[] args) {
		int[] arr = {3, -2, 5, 6, 1, 9, 7, 8, 12, 4};
		printPairs(arr, 10);
	}
	private static void printPairs(int[] arr, int sum) {
		HashMap<Integer, Boolean> map = new HashMap<Integer, Boolean>();
		for(int i = 0; i < 10; i++) {
			if (map.containsKey(sum-arr[i])) {
				System.out.println(arr[i] + " " + (sum -arr[i]));
			} else {
				map.put(arr[i], true);
			}
		}
	}
}

