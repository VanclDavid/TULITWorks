using System.Collections.Generic;

namespace CV02_STIN {
    class Order {
        private string orderName;
        private List<OrderItem> orderItems = new List<OrderItem>();
        /// <summary>
        /// Order
        /// </summary>
        /// <param name="orderName"></param>
        public Order(string orderName) {
            this.orderName = orderName;
        }
        /// <summary>
        /// Returns the number of records.
        /// </summary>
        /// <returns></returns>
        public int getListCount() {
            return this.orderItems.Count;
        }
        /// <summary>
        /// Returns name.
        /// </summary>
        /// <returns></returns>
        public string getName() {
            return this.orderName;
        }
        /// <summary>
        /// Add item.
        /// </summary>
        /// <param name="item"></param>
        public void addItem(OrderItem item) {
            this.orderItems.Add(item);
        }
        /// <summary>
        /// Returns item.
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public OrderItem getItem(int index) {
            return this.orderItems[index];
        }
    }
}
