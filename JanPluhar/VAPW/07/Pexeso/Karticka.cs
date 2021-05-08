using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pexeso
{
    class Karticka : Button
    {
        private int value;
        public Karticka(int value,int sizeX,int sizeY, int x, int y, EventHandler onclick, Form1 form) : base()
        {
            this.value = value;
            form.Controls.Add(this);
            this.Size = new Size(sizeX, sizeY);
            this.Location = new Point(x, y);
            this.Click += onclick;
            this.Text = "";
        }
        public int Get_value()
        {
            return value;
        }
        public void show_value()
        {
            this.Text = ""+value;
        }
        public void hide_value()
        {
            this.Text = "";
        }
    }
}
