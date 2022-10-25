package Aheys;

import java.util.Arrays;

public class TestArrays {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int array1[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
		int array2[];

//		for (int i = 0; i < array1.length; i++) {
//			System.out.println(array1[i]);
//		}
		
		array2 = array1;
		for (int i = 0; i < array2.length; i++) {
			if(i%2 == 0 ) {
				array2[i]=i;
			}
			System.out.println(array2[i]);
		}
		System.out.println("\n==========================\n");
		
		int[][] matriz=new int[5][];
		
		for(int i = 0; i < matriz.length; i++) {
			matriz[i]=new int[i];
			for(int j = 0; j < matriz[i].length; j++) {
				matriz[i][j] = i*j;
			}
		}
		
		System.out.println(Arrays.deepToString(matriz));
		
	}

}
