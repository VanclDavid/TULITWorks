using System;
using System.Collections.Generic;

namespace CV02_STIN {
    class OrderList {
        private List<Order> orderList = new List<Order>();
        private string[] tHeader;
        /// <summary>
        /// List of orders
        /// </summary>
        /// <param name="tHeader"></param>
        public OrderList(string[] tHeader) {
            this.tHeader = tHeader;
        }
        /// <summary>
        /// Method finishing order
        /// </summary>
        public void finishOrder() {
            foreach (Order order in this.orderList) {
                this.printOrderName(order.getName());
                double totalSum = 0.0;
                for (int i = 0; i < order.getListCount(); i++) {
                    OrderItem item = order.getItem(i);
                    int width = Int32.Parse(item.getOrderDetail(Array.IndexOf(this.tHeader, "sirka")));
                    int height = Int32.Parse(item.getOrderDetail(Array.IndexOf(this.tHeader, "vyska")));
                    int depth = Int32.Parse(item.getOrderDetail(Array.IndexOf(this.tHeader, "hloubka")));
                    int maxValue = Math.Max(width, Math.Max(height, depth));
                    double sumPerItem = 0;
                    if (maxValue > 100) {
                        int weight = Int32.Parse(item.getOrderDetail(Array.IndexOf(this.tHeader, "vaha")));
                        if (weight < 20) {
                            sumPerItem = item.getItemCount() * 10;
                        } else {
                            sumPerItem = item.getItemCount() * weight * 0.2;
                            if (item.getOrderDetail(0) == "lednice") sumPerItem *= 2;
                        }
                    } else {
                        sumPerItem = item.getItemCount() * 5;
                    }
                    totalSum += sumPerItem;
                    this.printOrderTicker(item.getItemCount(), item.getOrderDetail(0), item.getOrderDetail(1), sumPerItem);
                }
                this.printSumTicket(totalSum);
            }
        }
        /// <summary>
        /// Add order
        /// </summary>
        /// <param name="order"></param>
        public void addOrder(Order order) {
            this.orderList.Add(order);
        }
        /// <summary>
        /// Print order
        /// </summary>
        /// <param name="name"></param>
        private void printOrderName(string name) {
            Console.WriteLine(String.Format(" {0}", name));
        }
        /// <summary>
        /// Method printing ticket
        /// </summary>
        /// <param name="itemCount"></param>
        /// <param name="itemName"></param>
        /// <param name="itemType"></param>
        /// <param name="sumPerItem"></param>
        private void printOrderTicker(int itemCount, string itemName, string itemType, double sumPerItem) {
            Console.Write(String.Format(" polozka: {0} x {1} ({2}) {3}\n", itemCount, itemName, itemType, sumPerItem));
        }
        /// <summary>
        /// Print summary
        /// </summary>
        /// <param name="totalSum"></param>
        private void printSumTicket(double totalSum) {
            Console.WriteLine(String.Format(" suma: {0}\n", totalSum));
        }
    }
}
