/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.util.Arrays;
import java.util.Random;
/**
 *
 * @author vito
 */



public class JavaApplication1 {
    
    
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        /*
        Set random number type and amount,default 100 integers
        */
        String type = "int";
        int count = 7;
        
        /*
        Supported types include: int, float
        */
        Integer [] array_int = new Integer[count];
        Float [] array_float;
        Random rnd;
        rnd = new Random();
        if ("int".equals(type))
        {
            array_int = new Integer[count];
            for(int cc=0;cc<array_int.length;cc++)
            {
                array_int[cc] = rnd.nextInt();
            }
        }
        if ("float".equals(type))
        {
            array_float = new Float[count];
            for(int cc=0;cc<array_float.length;cc++)
            {
                array_float[cc] = rnd.nextFloat();
            }
        }
        System.out.println(Arrays.toString(array_int));
        Sorting sorting_engine = new Sorting();
        long startTime = System.nanoTime();
        sorting_engine.merge_sort_bt(array_int);
        long time_interval = System.nanoTime() - startTime;
        
        // TODO code application logic here
        System.out.print("Test\n");
        System.out.println(Arrays.toString(array_int));
        System.out.println(time_interval);
        
//        assert(false);
    }
    
}
