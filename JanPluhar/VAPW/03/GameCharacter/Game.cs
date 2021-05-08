using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameCharacter
{
    class Game
    {
        private Character player1;
        private Character player2;
        public bool isEnd;
        Random rnd;
        public Game(Character player1, Character player2, Random rnd)
        {
            isEnd = false;
            this.rnd = rnd;
            this.player1 = player1;
            this.player2 = player2;
        }
        public Character fight()
        {
            if (player1.Attack(rnd) > player2.Attack(rnd))
            {
                if (!player2.Lower_health(2))
                {
                    isEnd = true;       
                }
                return player1;
            } else if (player2.Attack(rnd) > player1.Attack(rnd))
            {
                if (!player1.Lower_health(2))
                {
                    isEnd = true;
                }
                return player2;
            }
            return null;
        }
    }
}
