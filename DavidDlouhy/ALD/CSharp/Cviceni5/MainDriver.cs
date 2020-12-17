using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni5
{
    class MainDriver
    {
        public static void Main(string[]args)
        {
            //Quicksort vlastně dělíme na menší pole a beme nejvyší index to je pivot
            new MainDriver();
        }
        public int CompareCount=0;
        public MainDriver()
        {
            var rng = new Random();
            var n = 1_000;
            var arr = new int[n].Select(i => rng.Next(0, n)).ToArray();
            QuickSort(arr);
            Console.WriteLine("Počet celkem: "+CompareCount);
            //Console.WriteLine("LOG: " + (n*Math.Log2(n))); nefunguje log2
            Console.WriteLine("NEJHORŠÍ N^2: " + (n*n));
            Console.ReadKey();

            //Co implementuje c# a java?
            
            /*var arr2 = arr
                .OrderBy(i => 1)
                .ToArray();
            
            */

            //malé pole -> použijem něco co má malou složitost, quicksort
            //U objeků heap sort, nežere tolik místa, ten je nevhodné použít u malých, protože tam je inicializační režije

            //máme si procvičit mapy a formátování řetězců
        }

        public void QuickSort(int [] arr)
        {
            QuickSort(arr, 0, arr.Length-1);
        }
        private void QuickSort(int[] arr, int low, int high)
        {
            if(low<high)
            {
                var pivot = Partition(arr, low, high);
                QuickSort(arr, low, pivot - 1);
                QuickSort(arr, pivot + 1, high);
            }
        }
        private int Partition(int[]arr, int low, int high)
        {
            var j = low-1;
            var pivot = arr[high];
            for(var i=low;i<high;i++)
            {
                CompareCount++;
                if (arr[i]<pivot)
                {
                    j++;
                    var tmp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = tmp;

                    //(arr[i], arr[j]) = (arr[j], arr[i]);//je prohození od c# 7
                }
            }
            (arr[j+1], arr[high]) = (arr[high], arr[j+1]);
            return j + 1;
        }
    }
}
