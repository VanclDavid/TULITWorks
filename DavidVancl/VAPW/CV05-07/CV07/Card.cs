using System.Windows.Forms;

namespace CV07
{
    class Card : Button {
        private int number;
        public Card(int number) {
            this.number = number;

            this.Height = 30;
            this.Width = 60;
        }
        public int getNumber() {
            return this.number;
        }
    }
}
