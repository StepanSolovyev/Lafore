// landlord.h
// заголовочный файл landlord.cpp - содержит объявления
// классов и т.п.
//#pragma warning (disable:4786) // для множеств (только
//#pragma warning( disable : 4244 ) // warning C4244: 'return': conversion from 'uint64_t' to 'double', possible loss of data
// компиляторы microsoft)"

// для accumulate()
//using namespace std;
////////////////////глобальные методы//////////////////////
void getaLine(string& inStr);  // получение строки текста
char getaChar();               // получение символа

							   ////////////////////класс tenant (жильцы)//////////////////
class tenant
{
private:
	string name;       // имя жильца
	uint64_t aptNumber;     // номер комнаты жильца
					   // здесь может быть прочая информация о жильце 
					   // (телефон и т.п.)

public:
	tenant(string n, uint64_t aNo);
	~tenant();
	uint64_t getAptNumber();
	// нужно для использования во множестве
	friend bool operator<(const tenant&, const tenant&);
	friend bool operator==(const tenant&, const tenant&);
	// для операций ввода-вывода
	friend ostream& operator<<(ostream&, const tenant&);
};  // конец объявления класса tenant

////////////////////класс compareTenants///////////////////
class compareTenants            // функциональный объект для
								// сравнения имен жильцов
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
// конец объявления класса tenantList

////////////////класс tenantInputScreen////////////////////
class tenantInputScreen
{
private:
	tenantList* ptrTenantList;
	string tName;
	uint64_t aptNo;

public:
	tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
	{ /* тут пусто */
	}
	void getTenant();
};  // конец класса tenantInputScreen

	////////////////////класс rentRow//////////////////////////
	// одна строка таблицы прибыли: адрес и 12 месячных оплат
class rentRow
{
private:
	uint64_t aptNo;
	double rent[12];

public:
	rentRow(uint64_t);                 // конструктор с одним
								  // параметром
	void setRent(uint64_t, double);     // запись платы за месяц
	double getSumOfRow();          // сумма платежей 
								  // из одной строки
								  // нужно для сохранения во множестве
	friend bool operator<(const rentRow&, const rentRow&);
	friend bool operator==(const rentRow&, const rentRow&);

	// для вывода
	friend ostream& operator<<(ostream&, const rentRow&);
};  // конец класса rentRow
	///////////////////////////////////////////////////////////
class compareRows         // функциональный объект сравнения
						  // объектов rentRows
{
public:
	bool operator()(rentRow*, rentRow*) const;
};
////////////////////класс rentRecord///////////////////////
class rentRecord
{
private:
	// множество указателей на объекты rentRow (по одному на 
	// жильца)
	set<rentRow*, compareRows> setPtrsRR;
	set<rentRow*, compareRows>::iterator iter;
public:
	~rentRecord();
	void insertRent(uint64_t, uint64_t, double);
	void display();
	double getSumOfRents();        // сумма всех платежей
};  // конец класса rentRecord

	////////////////////класс rentInputScreen//////////////////
class rentInputScreen
{
private:
	tenantList* ptrTenantList;
	rentRecord* ptrRentRecord;
	string renterName;
	double rentPaid;
	uint64_t month;
	uint64_t aptNo;

public:
	rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR) :
		ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
	{ /*тут пусто*/
	}
	void getRent();               // арендная плата одного 
								  // жильца за один месяц
};  // конец класса rentInputScreen

	///////////////////////класс expense///////////////////////
class expense
{
public:
	uint64_t month, day;
	string category, payee;
	double amount;
	expense()
	{  }

		expense(uint64_t m, uint64_t d, string c, string p, double a) :
		month(m), day(d), category(c), payee(p), amount(a)
	{ /* тут пусто! */
	}
	// нужно для хранения во множестве
	friend bool operator<(const expense&, const expense&);
	friend bool operator==(const expense&, const expense&);
	// нужно для вывода
	friend ostream& operator<<(ostream&, const expense&);
};  // конец класса expense   
	///////////////////////////////////////////////////////////
class compareDates // функциональный объект сравнения затрат
{
public:
	bool operator()(expense*, expense*) const;
};
///////////////////////////////////////////////////////////
class compareCategories // функциональный объект сравнения затрат
{
public:
	bool operator()(expense*, expense*) const;
};
///////////////////класс expenseRecord/////////////////////
class expenseRecord
{
private:
	// вектор указателей на расходы
	vector<expense*> vectPtrsExpenses;
	vector<expense*>::iterator iter;

public:
	~expenseRecord();
	void insertExp(expense*);
	void display();
	double displaySummary();       // нужно для годового отчета 
};  // конец класса expenseRecord

	////////////////класс expenseInputScreen///////////////////
class expenseInputScreen
{
private:
	expenseRecord* ptrExpenseRecord;
public:
	expenseInputScreen(expenseRecord*);
	void getExpense();
};  // конец класса expenseInputScreen

	//////////////////класс annualReport///////////////////////
class annualReport
{
private:
	rentRecord* ptrRR;
	expenseRecord* ptrER;
	double expenses, rents;

public:
	annualReport(rentRecord*, expenseRecord*);
	void display();
};  // конец класса annualReport

	//////////////////конец useruint64_terface//////////////////////
class userInterface
{
private:
	tenantList*          ptrTenantList;
	tenantInputScreen*   ptrTenantInputScreen;
	rentRecord*          ptrRentRecord;
	rentInputScreen*     ptrRentInputScreen;
	expenseRecord*       ptrExpenseRecord;
	expenseInputScreen*  ptrExpenseInputScreen;
	annualReport*        ptrAnnualReport;
	char ch;

public:
	userInterface();
	~userInterface();
	void interact();
};  // конец класса useruint64_terfac
	//////////////////конец файла landlord.h///////////////////
