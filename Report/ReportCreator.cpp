#include"Header.h"

void ReportCreator::createReport(ReportBuilder * builder)
{
	builder->setHead();
	builder->setMain();
	builder->setFooter();
	builder->getReport()->setReport(builder->getHead(), builder->getMain(), builder->getFooter());
	builder->getReport()->show();
}