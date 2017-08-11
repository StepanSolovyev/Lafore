
// Export.h



namespace LandLord
{
	void getaLine(string& inStr);  // получение строки текста
	char getaChar();               // получение символа

								   ////////////////////класс tenant (жильцы)//////////////////
	class tenant
	{
	private:
		string name;       // им€ жильца
		uint64_t aptNumber;     // номер комнаты жильца
								// здесь может быть проча€ информаци€ о жильце 
								// (телефон и т.п.)

	public:
		tenant(string n, uint64_t aNo);
		~tenant();
		uint64_t getAptNumber();
		// нужно дл€ использовани€ во множестве
		friend bool operator<(const tenant&, const tenant&);
		friend bool operator==(const tenant&, const tenant&);
		// дл€ операций ввода-вывода
		friend ostream& operator<<(ostream&, const tenant&);
	};  // конец объ€влени€ класса tenant

		////////////////////класс compareTenants///////////////////
	class compareTenants            // функциональный объект дл€
									// сравнени€ имен жильцов
	{
	public:
		bool operator()(tenant*, tenant*) const;
	};

	///////////////////класс tenantList////////////////////////
	class tenantList
	{
	private:
		// установить указатели на жильцов
		set<tenant*, compareTenants> setPtrsTens;
		set<tenant*, compareTenants>::iterator iter;

	public:
		~tenantList();                // деструктор 
									  // (удаление жильцов)
		void insertTenant(tenant*);   // внесение жильца в список
		uint64_t getAptNo(string);         // возвращает номер комнаты
		void display();               // вывод списка жильцов
	};
	// конец объ€влени€ класса tenantList

	////////////////класс tenantInputScreen////////////////////
	class tenantInputScreen
	{
	//private:
	public:

		tenantList* ptrTenantList;
		string tName;
		uint64_t aptNo;

	public:
		tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
		{ /* тут пусто */
		}
		void getTenant();
	};  // конец класса tenantInputScreen


	//////////////////////////////////////////////////////
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