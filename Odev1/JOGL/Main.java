package Main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	private static int[] arr;
	private static int[] arrstatic;
	private static int[] arrpoints;
	private static float[][] cordinates;
	private static ArrayList<int[]> arrList;
	private static int size;
	private static int angle;
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
		System.out.println("Lutfen kose sayisini girin.");
		size = input.nextInt();
		System.out.println("Lutfen her kosenin komsu sayisini tek tek giriniz.");
		arr = new int[size];
		arrpoints = new int[size];
		arrstatic = new int[size];
		cordinates = new float[size][4];
		for (int i = 0; i < size; i++) {
			arr[i] = input.nextInt();
			arrpoints[i] = i;
		}
		angle = 360 / size;
		arrList = new ArrayList<int[]>();

		Arrays.sort(arr);

		algorithm();
	}

	private static void setcordinates() {
		int tempangle = 0;
		for (int i = arr.length - 1; i >= 0; i--) {
			cordinates[i][0] = (float) (Math.cos(Math.toRadians(tempangle)) * 0.5);
			cordinates[i][1] = (float) (Math.sin(Math.toRadians(tempangle)) * 0.5);
			cordinates[i][2] = (float) (Math.cos(Math.toRadians(tempangle)) * 0.55);
			cordinates[i][3] = (float) (Math.sin(Math.toRadians(tempangle)) * 0.55);
			tempangle = tempangle + angle;
		}
		// print();
	}

	private static void algorithm() {
		for (int i = size - 1; i >= 0; i--) {
			int a = check();
			if (a == -1) {
				System.out.println("Bu dizi bir cizgeye ait olamaz.");
				break;
			} else if (a == 0) {
				System.out.println("Bu dizi bir cizgeye ait olabilir.");
				setcordinates();

				int last = arrstatic.length - 1;
				for (int j = 0; j < arrList.size(); j++) {

					int[] myString = new int[arrstatic[last]];
					myString = arrList.get(j);
					for (int k = 0; k < myString.length; k++) {
						System.out.print(myString[k]);
					}
					System.out.print("\n");
					last--;
				}

				// print();
				Draw.Graph(cordinates, arrstatic, arrList, arrpoints);
				break;
			} else if (a == 1) {
				System.out.println("islem yapiliyor...");
			}
			process();
			sort();
		}
	}

	private static int check() {
		int a = 1;
		int counter = 0;
		for (int i = 0; i <= size - 1; i++) {
			if (arr[i] == 0) {
				counter++;
			} else if (arr[i] == -1) {
				return -1;
			}
		}
		if (counter == size)
			a = 0;
		return a;

	}

	private static void sort() {
		for (int k = 0; k < size; k++) {
			for (int i = size - 1; i > 0; i--) {

				if (arr[i] < arr[i - 1]) {
					int temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
					temp = arrpoints[i];
					arrpoints[i] = arrpoints[i - 1];
					arrpoints[i - 1] = temp;
				}
				// print();
			}
		}
		
		// print();
	}

	@SuppressWarnings("unused")
	private static void print() {
		for (int j = 0; j < arr.length; j++) {
			System.out.print(arr[j]);
		}
		System.out.println("\n");
		// System.out.println("\n");
		// for (int j = 0; j < arr.length; j++) {
		// System.out.print(arrpoints[j]);
		// }

		// for (int j = 0; j < arr.length; j++) {
		// System.out.print(cordinates[j][0]);
		// System.out.println(":");
		// }
		// System.out.println("\n");
		// for (int j = 0; j < arr.length; j++) {
		// System.out.print(cordinates[j][1]);
		// }

	}

	private static void process() {
		arrstatic[size - 1] = arr[size - 1];
		int[] arrlisttemp = new int[arr[size - 1]];
		int counter = size - 2;
		for (int i = arr[size - 1] - 1; i >= 0; i--) {
			arrlisttemp[i] = arrpoints[counter];
			counter--;
		}

		arrList.add(arrlisttemp);

		for (int i = size - 2; i > size - 2 - (arr[size - 1]); i--) {

			arr[i] = arr[i] - 1;
		}
		/*
		 * for (int j = 0; j < arrlisttemp.length; j++) {
		 * System.out.print(arrlisttemp[j]); }
		 */
		System.out.println("process..");
		size = size - 1;

	}
}
