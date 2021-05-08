using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameCharacter
{
    class Character
    {
        private string name;
        private int health;
        private int combat_skill;
        public Character(string name, Random rnd)
        {
            this.name = name;
            health = rnd.Next(13) + 12;
            combat_skill = rnd.Next(7) + 6;
        }
        public Character(string name, int health, int combat_skill)
        {
            this.name = name;
            this.health = health;
            this.combat_skill = combat_skill;
        }
        public bool Lower_health(int damage)
        {
            if (this.health-damage > 0)
            {
                health = health - damage;
                return true;
            } else
            {
                health = 0;
                return false;
            }
        }
        public int Attack(Random rnd)
        {
            return rnd.Next(7) + rnd.Next(7) + this.combat_skill;
        }
        public int get_health()
        {
            return this.health;
        }
        public int get_combat_skill()
        {
            return this.combat_skill;
        }
        public string get_name()
        {
            return this.name;
        }
    }
}
