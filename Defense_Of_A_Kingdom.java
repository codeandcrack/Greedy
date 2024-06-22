import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
        Scanner s = new Scanner(System.in); 
        int t = s.nextInt(); 
        while(t > 0){
            int w = s.nextInt(); 
            int h = s.nextInt(); 
            int n = s.nextInt(); 
            
            int[] x = new int[n+2]; 
            int[] y = new int[n+2]; 
            x[0] = 0; 
            y[0] = 0; 
            for(int i = 2; i < n+2; i++){
                x[i] = s.nextInt(); 
                y[i] = s.nextInt(); 
            }
            x[1] = w; 
            y[1] = h; 
            Arrays.sort(x); 
            Arrays.sort(y); 
            
            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE; 
            for(int i = 0; i < n+1; i++){
                l1 = Math.max(l1, x[i+1] - x[i] - 1); 
                l2 = Math.max(l2, y[i+1] - y[i] - 1); 
            }
            System.out.println(l1*l2);
            t--;
        }
	}
}
