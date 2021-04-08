namespace CV02_STIN {
    class OrderItem {
        private int itemCount;
        private string[] orderDetail;
        /// <summary>
        /// Order item
        /// </summary>
        /// <param name="orderDetail"></param>
        /// <param name="itemCount"></param>
        public OrderItem(string[] orderDetail, int itemCount) {
            this.orderDetail = orderDetail;
            this.itemCount = itemCount;
        }
        /// <summary>
        /// Returns order detail of index;
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public string getOrderDetail(int index) {
            return this.orderDetail[index];
        }
        /// <summary>
        /// Returns amount.
        /// </summary>
        /// <returns></returns>
        public int getItemCount() {
            return this.itemCount;
        }
    }
}
