using System;
using System.Windows.Forms;

namespace CV08_10 {
    static class Program {
        public static EshopEngine shop = new EshopEngine();
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new ShopForm());
        }
    }
}
