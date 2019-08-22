#pragma once
#include<iostream>
#include<string>
#include<map>

using namespace std;

enum REPORT_TYPE
{
	TEXT = 1,
	HTML
};

class Report
{
public:
	Report();
	Report(string name);
	~Report() {}
	string getReport();
	void setReport(string head, string main, string footer);
	void show() const;
protected:
	string name;
	string report;
};

class ReportBuilder abstract
{
public:
	ReportBuilder() :report(nullptr) {}
	virtual ~ReportBuilder() {}
	virtual void setHead() = 0;
	virtual void setMain() = 0;
	virtual void setFooter() = 0;
	string getHead()
	{
		return this->head;
	}
	string getMain()
	{
		return this->main;
	}
	string getFooter()
	{
		return this->footer;
	}
	Report* getReport() const
	{
		if (this->report != nullptr)
			return this->report;
		return nullptr;
	}
protected:
	Report* report;
	string head;
	string main;
	string footer;
};

class TextReportBuilder : public ReportBuilder
{
public:
	TextReportBuilder() :ReportBuilder()
	{
		this->report = new Report("Text Report");
	}
	~TextReportBuilder() {}
	void setHead() override
	{
		this->head = "Report #1";
		head.shrink_to_fit();
	}
	void setMain() override
	{
		this->main = "Some text";
		main.shrink_to_fit();
	}
	void setFooter() override
	{
		this->footer = "Date     sign";
		footer.shrink_to_fit();
	}
private:

};

class HTMLReportBuilder : public ReportBuilder
{
public:
	HTMLReportBuilder() :ReportBuilder()
	{
		this->report = new Report("HTML Report");
	}
	~HTMLReportBuilder() {}
	void setHead() override
	{
		this->head = "<h1> Report #1 </h1>";
	}
	void setMain() override
	{
		this->main = "<body> Some text </body>";
	}
	void setFooter() override
	{
		this->footer = "<footer> Date     sign </footer>";
	}
private:

};

class ReportCreator
{
public:
	ReportCreator() {}
	~ReportCreator() {}
	void createReport(ReportBuilder* builder);
private:

};