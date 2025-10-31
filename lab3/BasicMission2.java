import java.util.Collections;
import java.util.Objects;
import java.util.Scanner;
import java.util.ArrayList;

public class BasicMission2 {
    private static String getInput(String prompt, Scanner scanner) {
        while (true) {
            try {
                System.out.print(prompt);
                return scanner.nextLine();
            } catch (Exception i) {
                System.out.println("Invalid Integer\n: ");
                scanner.next();
            }
        }
    }

    private static int popToInt(Queue<Integer> q){

        if(q.size() == 0) return 0;
        return (int) ((q.pop() * Math.pow(10, q.size())) + popToInt(q));
    }

    private static ArrayList<String> formulaArray;
    private static void changeToArray(String formula) {
        /*
        convert a string formula to a list of each number and operator
         */
        formulaArray = new ArrayList<>();
        Queue<Integer> que = new Queue<>();
        for (char c : formula.toCharArray()) {
            if (c == ' ') {
                continue;
            }
            if (Character.isDigit(c)){
                que.push(Character.getNumericValue(c));
            }
            else {
                if(que.size() != 0){
                    formulaArray.add(String.valueOf(popToInt(que)));
                }
                formulaArray.add(String.valueOf(c));
            }
        }
    }

    private static boolean isNumeric(String str) {
        for (char c : str.toCharArray()) {
            if (!Character.isDigit(c)) {return false;}
        }
        return true;
    }

    private static boolean prior(String cur, String basic) {
        boolean[][] priorList = {
                //cur  basic +      -      *      /      (      )      #
                /* + */ {true,  true,  false, false, true,  true,  true },
                /* - */ {true,  true,  false, false, true,  true,  true },
                /* * */ {true,  true,  true,  true,  true,  true , true },
                /* / */ {true,  true,  true,  true,  true,  true , true },
                /* ( */ {false, false, false, false, true,  false, false},
                /* ) */ {true,  true,  true,  true,  true,  true,  true },
                /* # */ {false, false, false, false, true,  false, true }
        };

        String[] ops = {"+", "-", "*", "/", "(", ")", "#"};
        int curIdx = -1, basicIdx = -1, length = ops.length;
        for (int i = 0; i < length; i += 1) {
            if (ops[i].equals(cur)) curIdx = i;
            if (ops[i].equals(basic)) basicIdx = i;
        }

        if (curIdx == -1 || basicIdx == -1) {
            return false;
        }
        return priorList[curIdx][basicIdx];
    }

    public static void toReversePolish(ArrayList<String> list){
        Stack<String> Operator = new Stack<>();
        Stack<String> Number = new Stack<>();
        Operator.push("#");
        for(String s: list){
            //System.out.println(s);
            if(s.equals("#") && Operator.peek().equals("#")){
                //System.out.println("first #");
                continue;
            }
            if(isNumeric(s)){
                Number.push(s);
                //System.out.println("Numeric");
            }
            else if(s.equals("(")){
                Operator.push(s);
                //Operator.items.print();
                //System.out.println("left (");
            }
            else if(s.equals(")")){
                //Operator.items.print();
                while (!Operator.peek().equals("(")) {
                    Number.push(Operator.pop());
                }
                Operator.pop();
                //System.out.println("right )");
            }
            else if(s.equals("#")){
                while (!Operator.peek().equals("#")) {
                    Number.push(Operator.pop());
                }
                break;
            }
            else {
                if(prior(s, Operator.peek())){
                    Operator.push(s);
                    //System.out.println("Prior");
                }
                else {
                    while (!prior(s, Operator.peek())) {
                        Number.push(Operator.pop());
                    }
                    Operator.push(s);
                    //System.out.println("not prior");
                }
            }
        }
        Operator.pop();
        formulaArray.clear();
        ArrayList<String> temp = new ArrayList<>();
        while (Number.size() != 0) {
            temp.add(Number.pop());
        }
        Collections.reverse(temp);
        formulaArray.addAll(temp);
    }

    private static double sum(double a, double b, String op) {
        return switch (op) {
            case "+" -> a + b;
            case "-" -> a - b;
            case "*" -> a * b;
            case "/" -> {
                if (Double.compare(b, 0.0) == 0) throw new ArithmeticException("除数不能为 0");
                yield a / b;
            }
            default -> throw new IllegalArgumentException("未知运算符: " + op);
        };
    }

    public static double calculate(ArrayList<String> list){
        Stack<Double> stack = new Stack<>();
        int result = 0;
        for (String s : list) {
            if (isNumeric(s)) {
                stack.push(Double.parseDouble(s));
            }
            else {
                double b = stack.pop();  // 右操作数
                double a = stack.pop();  // 左操作数
                stack.push(sum(a, b, s));
            }
        }
        return stack.pop();
    }

    private static void printArray(ArrayList<String> list){
        for (String s : list){
            System.out.print(s + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)) {
            String formula = getInput("Input: ", scanner);

            changeToArray(formula);
            System.out.print("Input formula is: ");
            printArray(formulaArray);

            toReversePolish(formulaArray);
            System.out.print("Re_Polish formula is: ");
            printArray(formulaArray);

            double result = calculate(formulaArray);
            System.out.printf("result is: %.2f\n",result);
        }
    }
}
