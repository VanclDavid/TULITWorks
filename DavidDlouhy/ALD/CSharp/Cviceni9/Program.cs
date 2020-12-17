using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Cviceni9
{
    class Program
    {
        private const string iLove= "I love";
        public static void Main(String [] args)
        {
            Console.SetIn(new StreamReader(Console.OpenStandardInput(8192)));

            string input = "";
            string line = Console.ReadLine();
            //int timeout = 0;
            int cc = 0;
            while (line != null&&cc!=2)
            {
                input += line;
                line = Console.ReadLine();
                if(line=="")
                {
                    cc++;
                    input += " ";
                }
                else
                {
                    cc = 0;
                }
            }
            if (input!="")
            { 
            searchUppercase(input.Split(' '));

            searchSpecificString(iLove, input);
            countSentences(input);
            }
            Console.ReadKey();
        }

        public static void searchUppercase(string [] input)
        {
            int number_of_uppercase=0;
            string output="";
            foreach(string word in input)
            {
               if(word != "")
               {
                    if(Regex.IsMatch(word.First().ToString(), "[A-Z]"))
                    { 
                    number_of_uppercase++;

                    if (word.Last() == '.')
                    {
                        output += "  " + number_of_uppercase + ") '" + (word.Substring(0, word.Length - 1)) + "'" + Environment.NewLine;
                    }
                    else
                    {
                        output += "  " + number_of_uppercase + ") '" + word + "'" + Environment.NewLine;
                    }
                    }

                }
            }
            Console.WriteLine("Uppercases "+number_of_uppercase+"x:");
            Console.WriteLine(output);
        }

        public static void searchSpecificString(string specificString, string input)
        {
           

            int result = Regex.Matches(input.ToLower(), specificString.ToLower()).Count;
            Console.WriteLine(specificString+" "+result+"x:");
            int counter = 0;
            bool nalezeno = false;
            string tempRetez = "";
            foreach(string slovo in input.Split(' '))
            {
                if (!nalezeno)
                {
                    if(slovo=="i"|| slovo == "I")
                    {
                        nalezeno = true;
                        tempRetez = slovo;
                    }
                }
                else
                {
                    nalezeno = false;
                    if (slovo == "love" || slovo == "Love" || slovo == "love." || slovo == "Love." || slovo == "LOVE." || slovo == "LOVE")
                    {
                        counter++;
                        if (slovo.Last() == '.')
                        {
                            tempRetez += " " + (slovo.Substring(0, slovo.Length - 1));
                        }
                        else
                        {
                            tempRetez += " " + slovo;
                        }
                        
                        Console.WriteLine("  " + counter + ") '" + tempRetez + "'");
                    }
                }
            }


            Console.WriteLine();
        }

        public static void countSentences(string input)
        {
            string[] sentences = input.Split('.');
            Console.WriteLine("Sentences "+(sentences.Length-1)+"x:");
            for(int i =0; i<sentences.Length-1;i++)
            {
                if(sentences[i].First()==' ')
                {
                    sentences[i] = sentences[i].Substring(1, sentences[i].Length - 1);
                }
                Console.WriteLine("  " + (i+1)+") '"+sentences[i] + ".'");
            }

        }

        /*
        public static void cviceniMain()
        {
            Dictionary<string, string> memo =new Dictionary<string, string>();

            string text = "abcdef";
            string text2 = "abcdefg";
            string [] slova = { "ab", "cd", "abc", "ef", "def" };
            //Console.WriteLine(muzeSlozt(text, slova, memo));
            //Console.WriteLine(muzeSlozt(text2, slova, memo));
            //Console.WriteLine(koliZpusobu(text, slova));

        }

        public static string muzeSlozt(string retezec, string[] slova, Dictionary<string, string> memo)
        {
            if(retezec=="")
            {
                return "ano";
            }
            foreach(string slovo in slova)
            {
                if(retezec.Contains(slovo))
                {
                    retezec = retezec.Remove(retezec.IndexOf(slovo), slovo.Length);
                    return muzeSlozt(retezec, slova, memo);
                }
                
            }
            return "ne";
        }

        public static int koliZpusobu(string retezec, string[] slova)
        {
            if (retezec == "")
            {
                return 1;
            }
            int pocetZpusobu = 0;
            foreach (string slovo in slova)
            {
                if (retezec.Contains(slovo))
                {
                    retezec = retezec.Remove(retezec.IndexOf(slovo), slovo.Length);
                    pocetZpusobu += koliZpusobu(retezec, slova);
                }

            }
            return pocetZpusobu;
        }
        */
    }
}
