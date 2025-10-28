import java.awt.*;
import java.util.Calendar;
import java.util.Scanner;

public class BasicMission1 {
    /*
    A decimal number N to convert to a d-based number
    N = (N // d) * d + N % d
    */

    private static char[] alphabet;

    private static void makeAlpha() {
        alphabet = new char[36];
        for(int i = 0; i < 36; i += 1) {
            if(i < 10){
                alphabet[i] = (char)(i + 48);
            }else {
                alphabet[i] = (char)(i + 55);
            }
        }
    }

    public static String convert(int deci, int d) {
        /*
        Take a decimal number as input, convert to d-based number

        div N to d first, push the mod to stack then
         */
        Stack<Character> s = new Stack<>();
        makeAlpha();
        convertBuild(deci, d, s);
        return convertBuildString(s);
    }

    public static void convertBuild(int deci, int d, Stack<Character> s) {
        if(deci < d) {
            s.push(alphabet[deci]);
            return;
        }
        s.push(alphabet[deci % d]);
        convertBuild(deci / d, d, s);
    }

    public static String convertBuildString(Stack<Character> s) {
        if (s.size() == 0){
            return "";
        }
        return s.pop() + convertBuildString(s);
    }

    public static int getInteger(String prompt, Scanner scanner) {
        while (true) {
            try {
                System.out.print(prompt);
                int i = scanner.nextInt();
                return i;
            } catch (Exception i) {
                System.out.println("Invalid Integer\n: ");
                scanner.next();
            }
        }
    }

    public static void main(String[] args){
        System.out.print("Convert decimal number to d-based number, please input ");
        try(Scanner scanner = new Scanner(System.in)) {
            int decimal = getInteger("decimal number: ", scanner);
            int d;
            while (true) {
                d = getInteger("d-based d: ", scanner);
                if (1 < d && d <= 36) {
                    break;
                }
                System.out.println("Out of range");
            }
            String result = convert(decimal, d);
            System.out.println("result is: " + result);
        }
    }
}
