import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // n = 참가자의 수
        int n = scanner.nextInt();
        // 티셔츠 사이즈별 신청자 수
        int []arr = new int[6];

        for(int i=0; i<6; i++){
            arr[i] = scanner.nextInt();
        }

        //티셔츠를 최소 T장씩, 볼펜을 최소 P자루씩 묶음으로 주문해야 함
        int t, p;
        t = scanner.nextInt();
        p = scanner.nextInt();

        int result_t = 0;
        int sum = 0;
        for(int i=0; i<6; i++){
            if(arr[i] % t == 0) result_t += arr[i] / t;
            else result_t += arr[i]/t + 1;

            sum += arr[i];
        }

        System.out.println(result_t);
        System.out.println(sum / p + " " +  sum % p);

    }
}