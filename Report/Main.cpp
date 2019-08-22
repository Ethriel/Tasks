#include"Header.h"

int main()
{
	ReportCreator* rc = new ReportCreator();
	ReportBuilder* rb = nullptr;
	int ch = 0;
	while (true)
	{
		system("cls");
		cout << "(1) text report\n";
		cout << "(2) html report\n";
		cin >> ch;
		switch ((REPORT_TYPE)ch)
		{
		case TEXT:
			rb = new TextReportBuilder();
			break;
		case HTML:
			rb = new HTMLReportBuilder();
			break;
		default:
		{
			cout << "You\'ve entered incorrect report type!\n";
			system("pause");
		}
		break;
		}

		if (rb != nullptr)
		{
			rc->createReport(rb);
			delete rb;
			rb = nullptr;
		}
	}

	system("pause");
}