
// Export.h



namespace LandLord
{

	// This class is exported from the MathFuncsDll.dll
	public class MyMathFuncs
	{
	public:
		// Returns a + b
		static  double Add(double a, double b);

		// Returns a - b
		static  double Subtract(double a, double b);

		// Returns a * b
		static  double Multiply(double a, double b);

		// Returns a / b
		// Throws const std::invalid_argument& if b is 0
		static  double Divide(double a, double b);
	};
}