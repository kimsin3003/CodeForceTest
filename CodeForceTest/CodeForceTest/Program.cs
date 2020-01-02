using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeForceTest
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] dimensions = input.Split(new char[] { ' ' });
            int n = int.Parse(dimensions[0]);
            int m = int.Parse(dimensions[1]);

            List<string> cellState = new List<string>();
            for (int i = 0; i < n; i++)
                cellState.Add(Console.ReadLine());

            string[] result = new string[n];

            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if(cellState[i][j] == '.')
                    {
                        if(CheckAdjIsB(result, i, j))
                        {
                            result[i] += 'W';
                        }
                        else
                        {
                            result[i] += 'B';
                        }
                    }
                    else
                    {
                        result[i] += '-';
                    }
                }
                Console.WriteLine(result[i]);
            }
            Console.Read();
        }

        static bool CheckAdjIsB(string[] result, int i, int j)
        {
            if (i > 0 && result[i - 1][j] == 'B')
            {
                return true;
            }
            if (j > 0 && result[i][j - 1] == 'B')
            {
                return true;
            }
            return false;
        }
    }
}
