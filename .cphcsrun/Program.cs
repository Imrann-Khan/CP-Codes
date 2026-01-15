using System;
using System.Numerics;
using System.Security.Cryptography.X509Certificates;

namespace HelloWorld
{
    class Program
    {
        public static int GCD(int x, int y)
        {
            if(y==0) return x;
            return GCD(y, x%y);
        }
        
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            
            while (t-- > 0)
            {
                string[] input = Console.ReadLine().Split();
                int l = Convert.ToInt32(input[0]);
                int a = Convert.ToInt32(input[1]);
                int b = Convert.ToInt32(input[2]);
                
                int g = GCD(b,l);
                int maxPrize = 0;
                
                for (int i = 0; i < l / g; i++)
                {
                    int position = (a + i * b) % l;
                    maxPrize = Math.Max(maxPrize, position);
                }
                
                Console.WriteLine(maxPrize);
            }
        }
    }
}