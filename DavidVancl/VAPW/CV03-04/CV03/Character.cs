using System;

namespace CV03_04
{
    class Character
    {
        private String name;
        private int health;
        private int attack;

        public Character(String name)
        {
            if (name != "") {
                this.name = name;
            } else {
                this.name = "Default (no select)";
            }
            this.health = FightArena.double_roll_the_dice() + 12;
            this.attack = FightArena.roll_the_dice() + 6;
        }
        public Character() {
            this.name = "Enemy";
            this.health = 14;
            this.attack = 8;
        }
        public int getHealth() {
            return this.health;
        }
        public int getAttack() {
            return this.attack;
        }
        public String getName() {
            return this.name;
        }
        public void changeHealtTo(int health) {
            this.health = health;
        }
    }
}
