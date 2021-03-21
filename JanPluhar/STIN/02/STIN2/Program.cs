using System;
using System.Collections.Generic;

namespace STIN2
{
    class Program
    {
        static string columnHeaders = "typ;vyrobce;cena;vaha;sirka;vyska;hloubka";
        static string data = "mycka;Samsung;9800;35;60;120;48\nlednice;Gorenje;12000;65;55;200;50\nmikrovlnna trouba;Elektorlux;2200;10;40;35;40\nsvetlo;Lumen;1250;2;30;15;10";
        static void Main(string[] args)
        {
            Product[] products = RawDataParser.CreateProductArray(RawDataParser.CreateTable(data, ';', '\n'),columnHeaders.Split(';'));
            OrderSystem orderSystem = new OrderSystem(0, "os");
            Order order1 = new Order("0001");
            order1.AddProduct(products[0],1);
            order1.AddProduct(products[3],2);
            Order order2 = new Order("0002");
            order2.AddProduct(products[1],2);
            order2.AddProduct(products[2],1);
            orderSystem.addOrder(order1);
            orderSystem.addOrder(order2);
            orderSystem.printBill();
            Console.ReadLine();
        }
    }
}
