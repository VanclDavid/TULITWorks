using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameCharacter
{
    public partial class Form1 : Form
    {
        Game game;
        Random rnd;
        Character character1;
        Character character2;
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!game.isEnd)
            {
                game.fight();
                refrest_stats();
            } else
            {
                button2.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Enabled = false;
            rnd = new Random();
            character1 = new Character(textBox1.Text, rnd);
            character2 = new Character("enemy", 10, 10);
            game = new Game(character1, character2,rnd);
            label1.Text = character1.get_name();
            label2.Text = character2.get_name();
            refrest_stats();
            button2.Enabled = true;
        }
        private void refrest_stats()
        {
            label2.Text = Convert.ToString(character1.get_health());
            label3.Text = Convert.ToString(character1.get_combat_skill());
            label5.Text = Convert.ToString(character2.get_health());
            label6.Text = Convert.ToString(character2.get_combat_skill());
        }
    }
}
