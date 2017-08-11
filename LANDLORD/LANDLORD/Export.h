
// Export.h



namespace LandLord
{
	void getaLine(string& inStr);  // ��������� ������ ������
	char getaChar();               // ��������� �������

								   ////////////////////����� tenant (������)//////////////////
	class tenant
	{
	private:
		string name;       // ��� ������
		uint64_t aptNumber;     // ����� ������� ������
								// ����� ����� ���� ������ ���������� � ������ 
								// (������� � �.�.)

	public:
		tenant(string n, uint64_t aNo);
		~tenant();
		uint64_t getAptNumber();
		// ����� ��� ������������� �� ���������
		friend bool operator<(const tenant&, const tenant&);
		friend bool operator==(const tenant&, const tenant&);
		// ��� �������� �����-������
		friend ostream& operator<<(ostream&, const tenant&);
	};  // ����� ���������� ������ tenant

		////////////////////����� compareTenants///////////////////
	class compareTenants            // �������������� ������ ���
									// ��������� ���� �������
	{
	public:
		bool operator()(tenant*, tenant*) const;
	};

	///////////////////����� tenantList////////////////////////
	class tenantList
	{
	private:
		// ���������� ��������� �� �������
		set<tenant*, compareTenants> setPtrsTens;
		set<tenant*, compareTenants>::iterator iter;

	public:
		~tenantList();                // ���������� 
									  // (�������� �������)
		void insertTenant(tenant*);   // �������� ������ � ������
		uint64_t getAptNo(string);         // ���������� ����� �������
		void display();               // ����� ������ �������
	};
	// ����� ���������� ������ tenantList

	////////////////����� tenantInputScreen////////////////////
	class tenantInputScreen
	{
	//private:
	public:

		tenantList* ptrTenantList;
		string tName;
		uint64_t aptNo;

	public:
		tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
		{ /* ��� ����� */
		}
		void getTenant();
	};  // ����� ������ tenantInputScreen


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