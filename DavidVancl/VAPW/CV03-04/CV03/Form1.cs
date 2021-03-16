using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CV03_04
{
    public partial class FightArena : Form
    {
        private static Random rand = new Random();
        private Character main_character;
        private Character enemy;
        public FightArena()
        {
            InitializeComponent();
        }
        private void generate_Click(object sender, EventArgs e)
        {
            this.main_character = new Character(hero_name.Text);
            this.enemy = new Character();

            this.hero_name_label.Text = "Name: " + this.main_character.getName();
            this.hero_attack_label.Text = "Attack: " + this.main_character.getAttack().ToString();
            this.herro_health_label.Text = "Health: " +  this.main_character.getHealth().ToString();

            this.enemy_name_label.Text = "Name: " + this.enemy.getName();
            this.enemy_attack_label.Text = "Attack: " + this.enemy.getAttack().ToString();
            this.enemy_health_label.Text = "Health: " + this.enemy.getHealth().ToString();

            this.fight_button.Enabled = true;
            this.generate.Enabled = false;
        }
        private void fight_button_Click(object sender, EventArgs e)
        {
            int hero_power = this.main_character.getAttack() + FightArena.double_roll_the_dice();
            int enemy_power = this.enemy.getAttack() + FightArena.double_roll_the_dice();

            if (hero_power > enemy_power) {
                this.enemy.changeHealtTo(this.enemy.getHealth() - 2);
                this.enemy_health_label.Text = this.enemy.getHealth().ToString();
            } else if (enemy_power > hero_power) {
                this.main_character.changeHealtTo(this.main_character.getHealth() - 2);
                this.herro_health_label.Text = this.main_character.getHealth().ToString();
            }

            if (this.main_character.getHealth() <= 0) {
                this.fight_button.Enabled = false;
                this.winner_label.Text = "Winner is: Enemy !!";
            } else if (this.enemy.getHealth() <= 0) {
                this.fight_button.Enabled = false;
                this.winner_label.Text = "Winner is: "+this.main_character.getName()+" !!";
            }

            this.hero_turn_label.Text = hero_power.ToString();
            this.enemy_turn_label.Text = enemy_power.ToString();
        }
        public static int roll_the_dice() {
            return FightArena.rand.Next(1, 7);
        }
        public static int double_roll_the_dice() {
            return FightArena.roll_the_dice() + FightArena.roll_the_dice();
        }
    }
}
