/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.util.Arrays;
import java.lang.Math;
/**
 *
 * @author vito
 */
public class Sorting {
    
    public void selection_sort(Comparable[] T)
    {
        for (int c1=0;c1<T.length;c1++)
        {
            for(int c2=c1+1;c2<T.length;c2++)
            {
                if (T[c1].compareTo(T[c2]) > 0)
                {
                    Comparable tmp = T[c1];
                    T[c1] = T[c2];
                    T[c2] = tmp;
                }
            }
        }
    }
    
    public void inserting_sort(Comparable[] T)
    {
        for (int cc=0; cc<T.length-1;cc++)
        {
            if(T[cc].compareTo(T[cc+1]) == 1)
            {
                for (int c1 = cc; c1>=0 && (T[c1].compareTo(T[c1+1]) == 1); c1--)
                {
                    Comparable tmp = T[c1+1];
                    T[c1+1] = T[c1];
                    T[c1] = tmp;
                }
            }
        }
    }
    
    private int midpoint(int index1, int index2)
    {
        int len = index2-index1+1;
        int count=0;
        for(int test=1;test<len;test*=2){
            count+=1;
        }
        //return count;
        return (int)Math.pow(2, count-1)-1+index1;
    }
    
    private void merge(int index1, int index2, Comparable[] T)
    {
       
       int mid = midpoint(index1, index2);
       int len = index2-index1+1;
       
       
       System.out.println("index1 "+index1);
       System.out.println("index2 "+index2);
       System.out.println("mid "+mid);
       System.out.println("len "+len);
       int c1 = index1;
       int c2 = mid+1;
       Comparable[] tmp = new Comparable[len];
       
       for(int c=0; c<len;c++)
       {
           System.out.println("c "+c);
           System.out.println(Arrays.toString(tmp));
           System.out.println("c1 " + c1);
           System.out.println("c2 "+ c2);
           if (c1> mid)    {tmp[c] = T[c2]; c2++; continue;}
           if (c2 >index2)     {tmp[c] = T[c1]; c1++; continue;}
           if (T[c1].compareTo(T[c2])==1)   {tmp[c] = T[c2]; c2++; continue;}
           else {tmp[c] = T[c1]; c1++; continue;}        
       }
       System.out.println(Arrays.toString(tmp));
       for(int c3=index1;c3<=index2;c3++)
       {
           T[c3] = tmp[c3-index1];   
       }
       System.out.println(Arrays.toString(T));
    }
    
    
    private int minimum(Comparable a, Comparable b)
    {
        if (a.compareTo(b) == 1)    return 1;
        else return 0;
    }
    
    public void merge_sort_bt(Comparable[] T)
    {
        
        for(int c=1;c<=T.length;c*=2)
        {
            for(int index=0;index<T.length;index += 2*c)
            {
                Integer Int1 = new Integer(index+2*c-1);
                Integer Int2 = new Integer(T.length-1);
                int min = minimum(Int1,Int2);
                int index2 = (min==1)?Int2:Int1;
               // System.out.println(index);
               // System.out.println(index2);
                merge(index,index2,T);
            }   
        }
    }
    
    private void merge_sort_tb_recursive(int index1, int index2, Comparable[] T)
    {
        int len = index2-index1+1;
        int mid = midpoint(index1,index2);
        System.out.println("Merge point "+mid);
        if (index1 == index2) return;
      //  if(mid+1-index1 == 0) return;
      //  if((mid+1-index1 == 1))  merge(index1,mid+1,T);
      //  else    
        merge_sort_tb_recursive(index1,mid,T);
     //   if (index2-(len-mid-1)==0) return;
     //   if((index2-(len-mid-1) == 1)) merge(len-mid-1,index2, T);
     //   else    
        merge_sort_tb_recursive(mid+1,index2,T);
        merge(index1, index2, T);
    }
    
    public void merge_sort_tb(Comparable[] T)
    {
        merge_sort_tb_recursive(0,T.length-1,T);
    }
}
