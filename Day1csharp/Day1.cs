using System.IO;

class Solution
{
    public static void Main(string[] args)
    {
        string line;

        try
        {
            //pass file path and name to constructor
            StreamReader sr = new StreamReader("day1.txt");

            //read first line
            line = sr.ReadLine();

            //continue until EOF
            while (line != null)
            {
                Console.WriteLine(line);
                line = sr.ReadLine();
            }

            //CLOSE THE FILE
            sr.Close();

            Console.ReadLine();
        }
        catch (Exception e)
        {
            Console.WriteLine("Exception: " + e.Message);
        }
        finally
        {
            Console.WriteLine("Executing finally block");
        }
    }
}