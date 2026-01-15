namespace Program;

class Car
{
    public int length;
    public int noOfWheel;
    public int speed;

    public Car()
    {
        this.length = 0;
        this.noOfWheel = 0;
        this.speed = 0;
    }

    public Car(int length, int noOfWheel, int speed)
    {
        this.length = length;
        this.noOfWheel = noOfWheel;
        this.speed = speed;
    }

    public void Display()
    {
        Console.WriteLine($"Length = {length}\nNo. of Wheel = {noOfWheel}\nSpeed = {speed}");
    }
}

class Program
{
    public static void Main()
    {
        Car c1 = new Car(20, 4, 100);
        c1.Display();
    }
}
