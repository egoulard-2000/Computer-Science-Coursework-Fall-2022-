#include <iostream>

/// <summary>
/// 
/// Question 1 Prompt: 
///     The returned value is allocated on behalf of the caller. 
///     The Value is the integer to convert, and base is octal, decimal, or hex.
/// 
/// </summary>
/// <param name="Value"></param>
/// <param name="Base"></param>
/// <returns></returns>
char* itoa(int Value, int Base)
{
    const int Octal = 8, Decimal = 10, Hex = 16;

    const int Length = 20;
    static char Result[Length];
    int i = Length - 1;

    #pragma region EdgeCases
    if (Value == 0)
    {
        Result[i--] = '0';
        return &Result[i + 1];
    }

    bool IsNegative = false;
    if (Value < 0)
    {
        Value *= -1;
        IsNegative = true;
    }
    #pragma endregion

    // Keep evaluating digits in input Value so we can translate the Value to its Base equivalent
    if (Base == Octal || Base == Decimal || Base == Hex)
    {
        const char* ValueArr = "0123456789abcdef";
        while (Value != 0)
        {
            Result[i--] = ValueArr[Value % Base];
            Value /= Base;
        }

        // Prepend negative sign to output if negative value
        if (IsNegative)
            Result[i--] = '-';

        return &Result[i + 1];
    }

    return &Result[i + 1]; // Return Empty if Arguments are invalid
}

/// <summary>
/// 
/// Question 2 Prompt: 
///     This function, provided a row-major matrix of integers, builds a string 
///     with the entries of that matrix appended in clockwise order.
/// 
/// </summary>
/// <param name="Matrix"></param>
/// <param name="NumRows"></param>
/// <param name="NumColumns"></param>
/// <param name="OutBuffer"></param>
void BuildStringFromMatrix(int* Matrix, int NumRows, int NumColumns, char* OutBuffer)
{
    #pragma region MatrixVariables
    const int MatrixLength = NumRows * NumColumns;

    // Make temporary values that will dynamically change as the matrix shrinks
    int CurrentMatrixLength = MatrixLength;
    int CurrentColumns = NumColumns;
    int CurrentRows = NumRows;
    #pragma endregion
    
    int BufferIndex = 0;
    int MatrixIndex = 0;
    while (CurrentMatrixLength > 0)
    {
        #pragma region TopLeft_To_BottomRight
        for (int i = 0; i <= CurrentColumns - 1 && BufferIndex < MatrixLength; i++)
        {
            OutBuffer[BufferIndex++] = Matrix[MatrixIndex++]; // Iterate the top row

            if (i == CurrentColumns - 1)
            {
                CurrentRows--; // Finished searching top row

                MatrixIndex--;
                for (int j = 0; j < CurrentRows; j++)
                {
                    // Iterate the right-most column (downward)
                    MatrixIndex += NumColumns;
                    OutBuffer[BufferIndex++] = Matrix[MatrixIndex];
                }
                CurrentColumns--; // Finished searching right column
            }
        }
        #pragma endregion

        #pragma region BottomRight_To_TopLeft
        MatrixIndex--;
        for (int i = 0; i <= CurrentColumns - 1 && BufferIndex < MatrixLength; i++)
        {
            OutBuffer[BufferIndex++] = Matrix[MatrixIndex--]; // Iterate the bottom row

            if (i == CurrentColumns - 1)
            {
                CurrentRows--; // Finished searching bottom row

                MatrixIndex++;
                for (int j = 0; j < CurrentRows; j++)
                {
                    // Iterate the left-most column (upward)
                    MatrixIndex -= NumColumns;
                    OutBuffer[BufferIndex++] = Matrix[MatrixIndex];
                }
                CurrentColumns--; // Finished searching left column
            }
        }
        #pragma endregion

        CurrentMatrixLength = CurrentRows * CurrentColumns; // Update to Smaller Matrix Size
        MatrixIndex++; // Adjust index to the 'new' top left of matrix
    }

    #pragma region PrintContentsToString
    const int DecimalBase = 10;
    const int BufferLength = MatrixLength;
    for (int i = 0; i < BufferLength - 1; i++)
    {
        std::cout << itoa(OutBuffer[i], DecimalBase) << ", ";
    }
    std::cout << itoa(OutBuffer[BufferLength - 1], DecimalBase) << std::endl; // print last one without extra comma
    #pragma endregion
    return;
}

int main()
{
    const int Octal = 8, Decimal = 10, Hex = 16;
    
    // Question 1

    std::cout << itoa(256, Octal) << std::endl;
    std::cout << itoa(2147483647, Decimal) << std::endl;
    std::cout << itoa(-2147483647, Decimal) << std::endl;
    std::cout << itoa(2147483647, Octal) << std::endl;
    std::cout << itoa(-2147483647, Hex) << std::endl;

    // Question 2

    int Matrix[12] = { 2, 3, 4, 8, 5, 7, 9, 12, 1, 0, 6, 10 };
    char Result[12];
    BuildStringFromMatrix(Matrix, 3, 4, Result);

    // static int Matrix[30] = { 4, 3, 5, 6, 7, 8, 10, 50, 33, 19, 1, 2, 80, 84, 92, 100, 4, 8, 22, 11, 13, 52, 48, 36, 76, 58, 9, 16, 25, 30 };
    // char Result[30];
    // BuildStringFromMatrix(Matrix, 6, 5, Result);
    
    // int Matrix[50] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50 };
    // char Result[50];
    // BuildStringFromMatrix(Matrix, 10, 5, Result);

    return 0;
}