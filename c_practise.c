#include <stdio.h>

float celcius_to_fahrenheit(float celsius)
{
    //convert celsius to fahrenheight
    return (celsius * 9.0 / 5.0) + 32.0;
}

int palindrome(int number)
{
    //return the flipped number
    int result = 0;
    while (number > 0)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }

    return result;
}

int largest_palindrome(void)
{
    //return the largest palindrome which is the product of 2 3-digit numbers
    int largest = 0;
    int product;
    for (int i=100;i < 1000; i++)
    {
        for (int j=100;j < 1000; j++)
        {
            product = i*j;
            if (product > largest)
            {
                if (palindrome(product) == product)
                {
                    largest = product;
                }
            }

        }
    }

    return largest;
}

long long int nth_fib(long long int n)
{
    //return the nth fibonacci number
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        long long int a = 0, b = 1, c;
        for (long long int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}


int main(void)
{
    //main selection point
    int choise;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choise);

    switch (choise)
    {
        case 1:
            float celsius;
            printf("_____Celcius to fahrenheit converter_____\nEnter the temperature in Celsius: ");
            scanf("%f", &celsius);
            printf("%f Celsius is equal to %f farenheight", celsius, celcius_to_fahrenheit(celsius));
            break;
        case 2:
            int number;
            printf("___Palindrome creator___\nEnter the number to flip: ");
            scanf("%d", &number);
            printf("Thre palindrome of %d is %d", number, palindrome(number));
            break;
        case 3:
            printf("___Largest palindrome___\nThe largest palindrome which is the product of 2 3-digit numbers is %d", largest_palindrome());
            break;
        case 4:
            long long int num;
            printf("___Nth fib number___\nEnter the target fibonacci number: ");
            scanf("%lld", &num);
            printf("The %lldth fibonacci number is %d", num, nth_fib(num));
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.");
    }

    return 0;
}