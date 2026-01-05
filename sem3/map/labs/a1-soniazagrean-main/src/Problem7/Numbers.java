package Problem7;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.util.Collections.swap;

public class Numbers {
    public static List<Integer> ReadUI() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int line = sc.nextInt();
        sc.nextLine();

        System.out.println(line);
        System.out.println("Type numbers with positive and negative values:");

        String input = sc.nextLine();
        String[] inputArray = input.trim().split(" ");

        List<Integer> numbers = new ArrayList<>();
        for (String s : inputArray) {
            numbers.add(Integer.parseInt(s));
        }
        return numbers;
    }

    public static List<Integer> SelectNegativeNum(List<Integer> numbers) {
        List<Integer> result = new ArrayList<>();
        for (Integer argument : numbers) {
            if (argument < 0) {
                result.add(argument);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        List<Integer> result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        if (args.length > 0) {
            for (String s : args) {
                list.add(Integer.parseInt(s));
            }
            result = SelectNegativeNum(list);
            SortList(result);
            if (!result.isEmpty()) {
                System.out.println("Sorted negative numbers:");
                for (Integer number : result) {
                    System.out.println(number);
                }
            }
            else {
                System.out.println("There are no negative numbers");
            }

        }
        else {
            list = ReadUI();
            result = SelectNegativeNum(list);
            SortList(result);
            if (!result.isEmpty()) {
                System.out.println("Sorted negative numbers:");
                for (Integer number : result) {
                    System.out.println(number);
                }
            }
            else {
                System.out.println("There are no negative numbers");
            }
        }
    }
    public static void SortList(List<Integer> list) {
        boolean valid = false;
        while (!valid) {
            valid = true;
            for (int i = 1; i < list.size(); ++i) {
                if (list.get(i - 1) > list.get(i)) {
                    int temp = list.get(i - 1);
                    list.set(i - 1, list.get(i));
                    list.set(i, temp);
                    valid = false;
                }
            }
        }
    }
}
