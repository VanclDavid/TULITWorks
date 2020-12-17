using System;
using System.Collections;
using System.Collections.Generic;

namespace cviceni2
{
    class Program
    {
        public static void Main(string[] args)
        {
            int number = Convert.ToInt32(Console.ReadLine());
            for(int i=1;i<=number;i++)
            {
                divisor(i);
            }
        }

        private static void divisor(int number)
        {
            
            var list = new List<int>();
            for(int i=1; i<=number; i++)
            {
                if (number > 0 && ((number % i)==0))
                {
                    list.Add(i);
                }
            }
            string text = number.ToString()+": ";
            bool first = true;
            foreach(int div in list)
            {
                if(!first)
                { 
                    text += ", "+div.ToString();
                }
                else
                {
                    text += div.ToString();
                    first = !first;
                }
            }
            text += "\n";
            Console.Write(text);
        }

        private static void demo()
        {
            //STACK, zásobík
            var stack = new Stack<int>();
            stack.Push(1);
            stack.Push(2);
            //QUEUE, fronta
            var queue = new Queue<int>();
            queue.Enqueue(1);
            queue.Enqueue(2);
            //List
            var list = new List<int>(1);
            //var list = new List<int>(10);počáteční kapacita 10 šetří čas
            list.Add(1);
            list.Add(2);
            //přidá pouze unkátní prvky, 1 se přidá poze 1x
            var set = new HashSet<int>();
            set.Add(1);
            set.Add(2);
            set.Add(1);
            //slovník kam přidávám hodotu na klíč, 1. je klíč, pak hodnota
            var map = new Dictionary<string, int>();
            map.Add("Martin", 2);
            var map2 = new Dictionary<string, List<string>>();
            map2.Add("Martin", new List<string> { "Hájek", "Motejlek" });
        }
    }
}
