#include"Header.h"

Report::Report() :name("REPORT")
{
}

Report::Report(string name) : name(name)
{
}

string Report::getReport()
{
	return this->report;
}

void Report::setReport(string head, string main, string footer)
{
	this->report = head + "\n" + main + "\n" + footer;
}

void Report::show() const
{
	cout << report << endl;
	system("pause");
}
