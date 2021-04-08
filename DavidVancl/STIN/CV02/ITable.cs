namespace CV02_STIN {
    class ITable {
        private string[] tHeader;
        private string[][] tBody;
        /// <summary>
        /// Preprocessed data table.
        /// </summary>
        /// <param name="header"></param>
        /// <param name="body"></param>
        public ITable(string header, string body) {
            this.tHeader = header.Split(';');
            this.tBody = new string[this.tHeader.Length][];
            string[] temp_data = body.Split('\n');
            for (int i = 0; i < temp_data.Length; i++) {
                this.tBody[i] = temp_data[i].Split(';');
            }
        }
        /// <summary>
        /// Returns a header.
        /// </summary>
        /// <returns></returns>
        public string[] getHeader() {
            return this.tHeader;
        }
        /// <summary>
        /// Returns the record.
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public string[] getRow(int index) {
            return this.tBody[index];
        }
    }
}
