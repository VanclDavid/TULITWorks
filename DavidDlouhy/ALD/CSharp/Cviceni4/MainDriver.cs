using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni4
{
    class MainDriver
    {
        private const char mine = '*';
        private const char click = 'o';
        private const char unhide = '.';
        private const char none = '?';
        private const char numberNone = 'Z';
        private static char[,] playgroung;
        public static void Main(string [] args)
        {
            string[] input = (Console.ReadLine()).Split(' ');
            int row = Convert.ToInt32(input[0]);
            int col = Convert.ToInt32(input[1]);
            playgroung = new char[row, col];
            initMines();
            int mineSum = Convert.ToInt32(Console.ReadLine());
            for (int i=0;i<mineSum;i++)
            {
                input = (Console.ReadLine()).Split(' ');
                int rowMine = Convert.ToInt32(input[0]);
                int colMine = Convert.ToInt32(input[1]);
                playgroung[rowMine, colMine] = mine;
            }
            int clickSum = Convert.ToInt32(Console.ReadLine());
            for (int i = 0; i < clickSum; i++)
            {
                input = (Console.ReadLine()).Split(' ');
                int rowClick = Convert.ToInt32(input[0]);
                int colClick = Convert.ToInt32(input[1]);
                playgroung[rowClick, colClick] = click;
            }
            displayPlayground();
            doClick();
            Console.WriteLine();
            displayPlaygroundFinal();
            Console.ReadKey();
        }

        private static char[,] initMines()
        {
            for(int i=0;i< playgroung.GetLength(0);i++)
            {
                for(int j=0;j< playgroung.GetLength(1); j++)
                {
                    playgroung[i,j]  = none;
                }
            }
            return playgroung;
        }

        private static void displayPlayground()
        {
            for (int i = 0; i < playgroung.GetLength(0); i++)
            {
                string line = "";
                for (int j = 0; j < playgroung.GetLength(1); j++)
                {
                    
                    line += playgroung[i,j]+" ";
                }
                Console.WriteLine(line);
            }
        }
        private static void displayPlaygroundFinal()
        {
            for (int i = 0; i < playgroung.GetLength(0); i++)
            {
                string line = "";
                for (int j = 0; j < playgroung.GetLength(1); j++)
                {
                    if (playgroung[i, j] == numberNone|| playgroung[i, j] == mine)
                    {

                        line += (none + " ");
                    }
                    else { 
                    line += (playgroung[i, j] + " ");}
                }
                Console.WriteLine(line);
            }
        }
        private static void setUnhide(int x, int y)
        {
            int mineCounter = 0;
            if (playgroung[x,y] == mine || playgroung[x, y] == unhide || playgroung[x, y] == numberNone)
            {
                return;
            }
            //Console.WriteLine("proc");
            if (!isMineClose(x, y))
            {
                playgroung[x, y] = unhide;
            }
            else
            {
                playgroung[x, y] = numberNone;
            }
            
            if (x!=0)
            {
                if(playgroung[x-1, y] != mine)
                {
                    setUnhide(x - 1, y);
                }
                if (y != 0)
                {
                    if (playgroung[x - 1, y - 1] != mine)
                    {
                        setUnhide(x - 1, y - 1);
                    }
                }
                if(y != (playgroung.GetLength(1) - 1))
                {
                    if(playgroung[x - 1, y + 1] != mine )
                    {
                        setUnhide(x - 1, y + 1);
                    }
                }
            }
            if (x != (playgroung.GetLength(0)-1))
            {
                if (playgroung[x + 1, y] != mine )
                {
                    setUnhide(x + 1, y);
                }
                if(y!=0)
                {
                    if (playgroung[x + 1, y - 1] != mine )
                    {
                        setUnhide(x + 1, y - 1);
                    }
                }
                if (y != (playgroung.GetLength(1) - 1))
                {
                    if (playgroung[x + 1, y + 1] != mine )
                    {
                        setUnhide(x + 1, y + 1);
                    }
                }
            }
            if (y != 0)
            {
                if (playgroung[x, y-1] != mine )
                {
                    setUnhide(x, y-1);
                }
            }
            if (y != (playgroung.GetLength(1) - 1))
            {
                if (playgroung[x , y+1] != mine )
                {
                    setUnhide(x, y+1);
                }
            }
            if (mineCounter>0)
            {
                return;
            }
        }

        private static bool isMineClose(int x, int y)
        {
            if (x != 0)
            {
                if (playgroung[x - 1, y] == mine)
                {
                    return true;
                }
                if (y != 0)
                {
                    if (playgroung[x - 1, y - 1] == mine)
                    {
                        return true;
                    }
                }
                if (y != (playgroung.GetLength(1) - 1))
                {
                    if (playgroung[x - 1, y + 1] == mine)
                    {
                        return true;
                    }
                }
            }
            if (x != (playgroung.GetLength(0) - 1))
            {
                if (playgroung[x + 1, y] == mine)
                {
                    return true;
                }
                if (y != 0)
                {
                    if (playgroung[x + 1, y - 1] == mine)
                    {
                        return true;
                    }
                }
                if (y != (playgroung.GetLength(1) - 1))
                {
                    if (playgroung[x + 1, y + 1] == mine)
                    {
                        return true;
                    }
                }
            }
            if (y != 0)
            {
                if (playgroung[x, y - 1] == mine)
                {
                    return true;
                }
            }
            if (y != (playgroung.GetLength(1) - 1))
            {
                if (playgroung[x, y + 1] == mine)
                {
                    return true; 
                }
            }
            return false;
        }

        private static void doClick()
        {
            for(int i =0;i<playgroung.GetLength(0);i++)
            {
                for(int j=0;j<playgroung.GetLength(1);j++)
                {
                    if(playgroung[i,j]==click)
                    {
                        setUnhide(i, j);
                        playgroung[i, j] = unhide;
                    }
                }
            }
        }

        /*
        public static void ukazkaRekurze()
        {
            //může zjednodušit lgiku, ale může program zaplnit pamětí a zničí se
            //faktorial
            //konečnost,  
            int num = factorial(5);
            Console.WriteLine(num);
            num = fibonacci(5);
            Console.WriteLine(num);
        }
        public static int factorial(int n)
        {
            Console.WriteLine("factorial(" +n+ ")");
            //rekurze, která vola sama sebe pouze jendou
            if(n<=1)
            {
                return 1;
            }
            return n * factorial(n - 1);
        }
        public static int fibonacci(int n)
        {
            Console.WriteLine("fibonacci(" + n + ")");
            //rekurze, která vola sama sebe 2x
            if (n <= 1)//pokud se dá n==1 tak dojde k zacyklení a chbě
            {
                return 1;
            }
            return fibonacci(n-1)+fibonacci(n-2);
        }
        public static void ukazkaNarocnosti()
        {
            Random Rng = new Random();
            int n = 10_000;
            var cisla = (new int[n]).Select(i => Rng.Next(0, 1000)).ToArray();
            var start = DateTime.Now;
            int cislo = sumNumbers(cisla);
            int[] nums = bubbleSort(cisla);
            var timeTooked = DateTime.Now - start;
            Console.WriteLine(timeTooked);
        }
        public static int pickRandomNumber(int[] numbers)
        {
            //složitost je furt stejná (1)
            var random = new Random();
            return numbers[random.Next(0, numbers.Length)];
        }
        public static int sumNumbers(int [] numbers)
        {
            //lineární složitost, proměnlivý počet
            var sum = 0;
            foreach(var number in numbers)
            {
                sum += number;
            }
            return sum;
        }
        public static int [] bubbleSort(int[]numbers)
        {
            //kvadratická složitost, bubble sort x^2
            //čas se násobí 100x tak náročné
            //n*n složitost, n je počet ktoků for cyklu
            for(int i =0;i<numbers.Length-1;i++)
            {
                for(int j=0;j<numbers.Length-1;j++)
                {
                    if(numbers[j]>numbers[j+1])
                    {
                        var tmp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = tmp;
                    }
                }
            }
            return numbers;
        }*/
    }
}
