using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Pexeso
{
    class GameBoard
    {
        private List<Karticka> cards;
        private List<Karticka> clicked_cards;
        private int show_n_card;
        private System.Windows.Forms.Timer timer;
        private Form1 form;

        public GameBoard(int length,int show_n_card,Form1 form,System.Windows.Forms.Timer timer)
        {
            this.timer = timer;
            this.form = form;
            this.show_n_card = show_n_card;
            clicked_cards = new List<Karticka>();
            timer.Tick += new EventHandler(timer_Tick);
            timer.Interval = 3000;
            cards = new List<Karticka>();
            int[] values =new int[length * length];
            for (int i = 0; i < values.Length; i++)
            {
                values[i] = i+1;
                values[values.Length - 1 - i] = i+1;
            }
            reshuffle(values);
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    Karticka tmp = new Karticka(values[i+length*j],40,40,i*45,j*45,card_click,form);
                    cards.Add(tmp);
                }
            }
        }
        private static void reshuffle(int[] numbers)
        {
            Random rnd = new Random();
            for (int t = 0; t < numbers.Length; t++)
            {
                int tmp = numbers[t];
                int r = rnd.Next(t, numbers.Length);
                numbers[t] = numbers[r];
                numbers[r] = tmp;
            }
        }
        private void card_click(object sender, EventArgs e)
        {
            if (clicked_cards.Count < show_n_card)
            {
                if (!clicked_cards.Contains((sender as Karticka)))
                {
                    (sender as Karticka).show_value();
                    clicked_cards.Add(sender as Karticka);
                    if (clicked_cards.Count == show_n_card)
                    {
                        if (!timer.Enabled)
                        {
                            timer.Start();
                        }
                    }
                }
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            int value = (clicked_cards[0]).Get_value();
            bool isSame = true;
            foreach (Karticka card in clicked_cards)
            {
                if (card.Get_value() != value)
                {
                    isSame = false;
                }
                card.hide_value();
            }
            if (isSame)
            {
                foreach (Karticka card in clicked_cards)
                {
                    cards.Remove(card);
                    form.Controls.Remove(card);
                }
            }
            clicked_cards.Clear();
            timer.Stop();
        }
    }
}
