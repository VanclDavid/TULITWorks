namespace CV02_STIN {
    class Program {
        private static string headerColumns = "typ;vyrobce;cena;vaha;sirka;vyska;hloubka";
        private static string bodyRows = "mycka;Samsung;9800;35;60;120;48\nlednice;Gorenje;12000;65;55;200;50\nmikrovlnna trouba;Elektorlux;2200;10;40;35;40\nsvetlo;Lumen;1250;2;30;15;10";
        /// <summary>
        /// Main
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args) {
            ITable preTable = new ITable(Program.headerColumns, Program.bodyRows);

            Order first_order = new Order("O001");
            first_order.addItem(new OrderItem(preTable.getRow(0), 1));
            first_order.addItem(new OrderItem(preTable.getRow(3), 2));

            Order second_order = new Order("O002");
            second_order.addItem(new OrderItem(preTable.getRow(1), 2));
            second_order.addItem(new OrderItem(preTable.getRow(2), 1));

            OrderList orderList = new OrderList(preTable.getHeader());
            orderList.addOrder(first_order);
            orderList.addOrder(second_order);

            orderList.finishOrder();
        }
    }
}
