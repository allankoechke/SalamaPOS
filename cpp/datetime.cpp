#include "datetime.h"

DateTime::DateTime(QObject *parent) : QObject(parent)
{
}

QStringList DateTime::getTimestamp(const QString &when)
{
    QDateTime dt = QDateTime::currentDateTime();
    QStringList dtList;

    if(when == "now" || when == "")
    {
        QString now = dt.toString("yyyy-MM-dd hh:mm:ss") + "+03";
        dtList.append(now);
        return dtList;
    }

    else if(when == "today")
    {
        QDate today = QDate::currentDate();
        QString upper = today.toString("yyyy-MM-dd ") + "23:59:59+03";
        QString lower = today.toString("yyyy-MM-dd ") + "00:00:00+03";

        dtList.append(lower);
        dtList.append(upper);

        return dtList;
    }

    else if(when == "yesterday")
    {
        QDate today = QDate::currentDate();
        QDate yesterday = today.addDays(-1);
        QString upper = today.toString("yyyy-MM-dd ") + "00:00:00+03";
        QString lower = yesterday.toString("yyyy-MM-dd ") + "00:00:00+03";

        dtList.append(lower);
        dtList.append(upper);

        return dtList;
    }

    else if(when == "thisWeek")
    {
        QDate today = QDate::currentDate();
        int dow = today.dayOfWeek() - 1;

        QDate firstday = today.addDays(- dow);
        QDate endday = firstday.addDays(6);

        QString upper = endday.toString("yyyy-MM-dd ") + "23:59:59+03";
        QString lower = firstday.toString("yyyy-MM-dd ") + "00:00:00+03";

        dtList.append(lower);
        dtList.append(upper);

        return dtList;
    }

    else if(when == "thisMonth")
    {
        QDate today = QDate::currentDate();

        QList<int> d31 = {1,3,5,7,8,10,12};
        QList<int> d30 = {4,6,9,11};

        int feb = today.isLeapYear(today.year())? 29:28;

        int mo = today.month();
        int _mo = 0;

        if(d31.contains(mo))
            _mo = 31;

        else if(d30.contains(mo))
            _mo = 30;

        else
            _mo = feb;

        QString upper = today.toString("yyyy-MM") + "-" + QString::number(_mo)+ " 23:59:59+03";
        QString lower = today.toString("yyyy-MM") + "-01 00:00:00+03";

        dtList.append(lower);
        dtList.append(upper);

        return dtList;
    }

    else if(when == "thisYear")
    {
        QDate today = QDate::currentDate();

        QString upper = today.toString("yyyy") + "-12-31 23:59:59+03";
        QString lower = today.toString("yyyy") + "-01-01 00:00:00+03";

        dtList.append(lower);
        dtList.append(upper);

        return dtList;
    }

    return QStringList();
}
