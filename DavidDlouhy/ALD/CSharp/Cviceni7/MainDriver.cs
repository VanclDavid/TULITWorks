using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni7
{
    class MainDriver
    {
        public static void Main(string [] args)
        {
            var rng = new Random();
            int n = 100;
            var items = new int[n].Select(i=>rng.Next(0,100)).ToArray();
            Console.WriteLine(items);
            Console.ReadLine();
        }

        public static void mergeSort(int[] arr)
        {
            mergeSort(arr, 0, arr.Length - 1);
        }
        //sub merge sort
        public static void mergeSort(int[] arr, int left, int right)
        {
            if(left<right)
            {
                var mid = (right + left) / 2;
                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);
                mergeSort(arr, left, mid, right);
            }
        }
        //počítáme že už je seřazeno
        private static void mergeSort(int[] arr, int left, int mid, int right)
        {
            int i = 0;
            int j = 0;
            var lSize = mid - left +1;
            var rSize = right - mid;
            var l = new int[lSize];
            var r = new int[rSize];
            for(i=0;i<lSize;i++)
            {
                l[i] = arr[i];
            }
            for(i =0;i<rSize;i++)
            {
                r[i] = arr[mid+i+1];
            }
            int k = left;
            i = 0;
            j = 0;
            while(i<lSize && j<rSize)
            {
                if(l[i]<r[j])
                {
                    arr[k] = l[i];
                    i++;
                    k++;
                }
                else
                {
                    arr[k] = r[j];
                    j++;
                    k++;
                }
            }
            while(i<lSize)
            {
                arr[k++] = l[j++];
            }
            while (j < rSize)
            {
                arr[k++] = r[j++];
            }
        }
    }
}
