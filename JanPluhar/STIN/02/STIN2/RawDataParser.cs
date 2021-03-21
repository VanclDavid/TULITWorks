using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace STIN2
{
    static class RawDataParser
    {/// <summary>
    /// Converts input data into table or array of Product objects
    /// </summary>
    /// <param name="data">string input data</param>
    /// <param name="separator">separator between each parameter</param>
    /// <param name="lineseparator">separator between each line/object</param>
    /// <returns></returns>
        public static string[][] CreateTable(string data, char separator, char lineseparator)
        {
            ///parse string by separators into 2D array
            string[] lines = data.Split(lineseparator);
            string[][] table = new string[lines.Length][];
            for (int i = 0; i < lines.Length; i++)
            {
                table[i] = lines[i].Split(separator);
            }
            return table;
        }
        public static Product[] CreateProductArray(string[][] table,string[] columnHeader) {
            ///create Product object array from parameters in 2D array
            Product[] products = new Product[table.Length];
            int[] paramLayout = GetParametersLayout(columnHeader);
            for (int i = 0; i < products.Length; i++)
            {
                products[i] = new Product(table[i][paramLayout[0]], table[i][paramLayout[1]], Convert.ToInt32(table[i][paramLayout[2]]), Convert.ToInt32(table[i][paramLayout[3]]), Convert.ToInt32(table[i][paramLayout[4]]), Convert.ToInt32(table[i][paramLayout[5]]), Convert.ToInt32(table[i][paramLayout[6]]));
            }
            return products;
        }
        private static int[] GetParametersLayout(string[] array)
        {///determines order of parameter in input string
            string[] layout = { "typ", "vyrobce", "cena", "vaha", "sirka", "vyska", "hloubka" };
            int[] output = new int[layout.Length];
            for (int i = 0; i < layout.Length; i++)
            {
                for (int j = 0; j < array.Length; j++)
                {
                    if (array[j].Equals(layout[i]))
                    {
                        output[i] = j;
                        break;
                    }
                }
            }
            return output;
        }
    }
}
