using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cviceni6
{
    class Osoba
    {
        //jmeno prijmeni skupina pohlavi rok-studia programovaci-jazyk
        private string jmeno;
        private string prijmeni;
        private string pohlavi;
        private int rokStudia;
        private string skupina;
        private string programovaciJazyk;
        public Osoba(string jmeno, string prijmeni, string pohlavi, int rokStudia, string skupina, string programovaciJazyk)
        {
            this.jmeno = jmeno;
            this.prijmeni = prijmeni;
            this.pohlavi = pohlavi;
            this.rokStudia = rokStudia;
            this.skupina = skupina;
            this.programovaciJazyk = programovaciJazyk;
        }
        public int getRokStudia()
        {
            return rokStudia;
        }
        public string getJmeno()
        {
            return jmeno;
        }
        public string getPrijmeni()
        {
            return prijmeni;
        }
        public string getProgramovaciJazyk()
        {
            return programovaciJazyk;
        }
        public string getSkupina()
        {
            return skupina;
        }
        public string getPohlavi()
        {
            return pohlavi;
        }
        public string toString()
        {
            // JAKOTYC Stojan(M, 3. @ pa): Python
            return (getPrijmeni().ToUpper()+" "+getJmeno()+" ("+getPohlavi().Substring(0,1)+", "+getRokStudia().ToString()+". @ "+getSkupina().Substring(0,2)+"): "+getProgramovaciJazyk());
        }
    }
}
