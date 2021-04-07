using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace CV07
{
    public partial class Form1 : Form {
        private Random rnd = new Random();
        private List<Card> generated_cards = new List<Card>();
        private Card[] swap_ = new Card[2];
        private bool can_click = true;
        public Form1() {
            InitializeComponent();
        }

        private void generate_Click(object sender, EventArgs e) {
            foreach (int number in Enumerable.Range(1, (int)field_size.Value).OrderBy(i => rnd.Next()).ToArray()) {
                Card card1 = new Card(number);
                card1.Click += new EventHandler(check_card);
                this.generated_cards.Add(card1);

                Card card2 = new Card(number);
                card2.Click += new EventHandler(check_card);
                this.generated_cards.Add(card2);
            }

            int x = 10;
            int y = 20;
            int index = 0;
            foreach (Card card in this.generated_cards.OrderBy(i => rnd.Next()).ToList()) {
                card.Location = new Point(x, y);
                this.field.Controls.Add(card);
                x += 65;
                index++;
                if (index >= Math.Ceiling((double) field_size.Value / 2)) {
                    y += 35;
                    x = 10;
                    index = 0;
                }
            }

            this.generate.Enabled = false;
        }

        private void check_card(object sender, EventArgs e){
            if (can_click) {
                if (this.swap_[0] == null)
                {
                    this.swap_[0] = (sender as Card);
                    (sender as Card).Text = (sender as Card).getNumber().ToString();
                }
                else if (this.swap_[1] == null)
                {
                    this.swap_[1] = (sender as Card);
                    (sender as Card).Text = (sender as Card).getNumber().ToString();
                    this.can_click = false;
                    this.clear_timer.Start();
                }
            }
        }

        private void field_size_KeyPress(object sender, KeyPressEventArgs e) {
            if (e.KeyChar < 48 || e.KeyChar > 57) {
                e.Handled = true;
            }
        }

        private void clear_timer_Tick(object sender, EventArgs e) {
            if (this.swap_[0].getNumber() == this.swap_[1].getNumber()) {
                this.field.Controls.Remove(this.swap_[0]);
                this.field.Controls.Remove(this.swap_[1]);
                this.generated_cards.Remove(this.swap_[0]);
                this.generated_cards.Remove(this.swap_[1]);
                if (this.generated_cards.Count <= 0) {
                    this.restart.Visible = true;
                }
            } else {
                this.swap_[0].Text = "";
                this.swap_[1].Text = "";
            }
            
            this.swap_[0] = null;
            this.swap_[1] = null;
            this.can_click = true;
            this.clear_timer.Stop();
        }

        private void restart_Click(object sender, EventArgs e) {
            this.generated_cards.Clear();
            this.swap_[0] = null;
            this.swap_[1] = null;
            this.can_click = true;
            this.generate.Enabled = true;
            this.restart.Visible = false;
        }
    }
}
