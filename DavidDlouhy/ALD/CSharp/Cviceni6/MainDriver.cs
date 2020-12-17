using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni6
{
    class MainDriver
    {
        private static List<Osoba> listOfOsoba = new List<Osoba>();
        public static void Main(String [] args)
        {
            loadOsoba();
            string line = Console.ReadLine();
            while (line !="---")
            {
                printBy(line);
                line = Console.ReadLine();
            }
            Console.ReadKey();
        }
         private static void loadOsoba()
        {
            int numberOfPersons = Convert.ToInt32(Console.ReadLine());
            for(int i=0; i<numberOfPersons; i++)
            {
                string [] line =  (Console.ReadLine()).Split(' ');
                Osoba loadedOsoba = new Osoba(line[0], line[1], line[3], Convert.ToInt32(line[4]), line[2], line[5]);
                listOfOsoba.Add(loadedOsoba);
            }
        }
        private static void printListOfOsoba()
        {
            foreach(Osoba osobaInList in listOfOsoba)
            {
                Console.WriteLine("-- " + osobaInList.toString());
            }
        }
        private static void printListOfOsoba(List<Osoba> specificList)
        {
            foreach (Osoba osobaInList in specificList)
            {
                Console.WriteLine("-- " + osobaInList.toString());
            }
        }
        private static void printBy(string atribute)
        {
            switch(atribute)
            {
                case "jmeno":
                    Console.WriteLine("NULL_JMENO");
                    break;
                case "prijmeni":
                    Console.WriteLine("NULL_PRIJEMNI");
                    break;
                case "skupina":
                    Console.WriteLine("Trideni dle SKUPINA");
                    List<string> listSkupina = new List<string>();
                    foreach (Osoba osobaInList in listOfOsoba)
                    {
                        string loadedSkupina = osobaInList.getSkupina();
                        bool exist = false;
                        foreach (string skupinaInListSkupina in listSkupina)
                        {
                            if (skupinaInListSkupina == loadedSkupina)
                            {
                                exist = true;
                            }
                        }
                        if (!exist)
                        {
                            listSkupina.Add(loadedSkupina);
                        }
                    }

                    foreach (string pohlaviInListSkupina in listSkupina)
                    {
                        Console.WriteLine("-skupina " + pohlaviInListSkupina + ":");
                        foreach (Osoba osobaInList in listOfOsoba)
                        {
                            if (osobaInList.getSkupina() == pohlaviInListSkupina)
                            {
                                Console.WriteLine("-- " + osobaInList.toString());
                            }
                        }
                    }
                    break;
                case "pohlavi":
                    Console.WriteLine("Trideni dle POHLAVI");
                    List<string> listPohlavi = new List<string>();
                    foreach(Osoba osobaInList in listOfOsoba)
                    {
                        string loadedPohlavi = osobaInList.getPohlavi();
                        bool exist = false;
                        foreach(string pohlaviInListPohlavi in listPohlavi)
                        {
                            if(pohlaviInListPohlavi==loadedPohlavi)
                            {
                                exist = true;
                            }
                        }
                        if(!exist)
                        {
                            listPohlavi.Add(loadedPohlavi);
                        }
                    }

                    foreach(string pohlaviInListPohlavi in listPohlavi)
                    {
                        Console.WriteLine("-skupina " + pohlaviInListPohlavi.Substring(0, 1) + ":");
                        foreach(Osoba osobaInList in listOfOsoba)
                        {
                            if(osobaInList.getPohlavi()==pohlaviInListPohlavi)
                            {
                                Console.WriteLine("-- " + osobaInList.toString());
                            }
                        }
                    }

                    break;
                case "rok-studia":
                    Console.WriteLine("Trideni dle ROK_STUDIA");
                    List<int> listRok = new List<int>();
                    foreach (Osoba osobaInList in listOfOsoba)
                    {
                        int loadedRok = osobaInList.getRokStudia();
                        bool exist = false;
                        foreach (int RokInListRok in listRok)
                        {
                            if (RokInListRok == loadedRok)
                            {
                                exist = true;
                            }
                        }
                        if (!exist)
                        {
                            listRok.Add(loadedRok);
                        }
                    }

                    foreach (int RokInListRok in listRok)
                    {
                        Console.WriteLine("-skupina " + RokInListRok.ToString() + ":");
                        foreach (Osoba osobaInList in listOfOsoba)
                        {
                            if (osobaInList.getRokStudia() == RokInListRok)
                            {
                                Console.WriteLine("-- " + osobaInList.toString());
                            }
                        }
                    }
                    break;
                case "programovaci-jazyk":
                    Console.WriteLine("Trideni dle PROGRAMOVACI_JAZYK");
                    List<string> listProgramovacijazyk = new List<string>();
                    foreach (Osoba osobaInList in listOfOsoba)
                    {
                        string loadedProgramovaciJazyk = osobaInList.getProgramovaciJazyk();
                        bool exist = false;
                        foreach (string prjzInListProgramovacijazyk in listProgramovacijazyk)
                        {
                            if (prjzInListProgramovacijazyk == loadedProgramovaciJazyk)
                            {
                                exist = true;
                            }
                        }
                        if (!exist)
                        {
                            listProgramovacijazyk.Add(loadedProgramovaciJazyk);
                        }
                    }

                    foreach (string prjzInListProgramovacijazyk in listProgramovacijazyk)
                    {
                        Console.WriteLine("-skupina " + prjzInListProgramovacijazyk + ":");
                        foreach (Osoba osobaInList in listOfOsoba)
                        {
                            if (osobaInList.getProgramovaciJazyk() == prjzInListProgramovacijazyk)
                            {
                                Console.WriteLine("-- " + osobaInList.toString());
                            }
                        }
                    }
                    break;
            }

        }
    }
}
