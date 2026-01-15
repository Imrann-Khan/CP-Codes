using System.Text;

namespace Practice;

internal static class Program
{
    private static void Main(string[] args)
    {
        string path = "../../../myText.txt"; 
        using FileStream fileStream = new FileStream(path, FileMode.Append);

        byte[] byteData = Encoding.Default.GetBytes("This a simple text file writing example3");

        fileStream.Write(byteData, 0, byteData.Length);

        fileStream.Close();
    }
}
