#include "crediteeaccount.h"

CrediteeAccount::CrediteeAccount(QObject *parent) : QObject(parent)
{ }

CrediteeAccount::CrediteeAccount(const QString &firstName, const QString &lastName, const QString &mobileNo, const QString &idNo, const int &debtAmount, QObject *parent)
    : QObject(parent), m_firstName(firstName), m_lastName(lastName), m_mobileNo(mobileNo), m_idNo(idNo), m_debtAmount(debtAmount)
{ }

QString CrediteeAccount::firstName() const
{
    return m_firstName;
}

QString CrediteeAccount::lastName() const
{
    return m_lastName;
}

QString CrediteeAccount::mobileNo() const
{
    return m_mobileNo;
}

QString CrediteeAccount::idNo() const
{
    return m_idNo;
}

int CrediteeAccount::debtAmount() const
{
    return m_debtAmount;
}

void CrediteeAccount::setFirstName(QString firstName)
{
    if (m_firstName == firstName)
        return;

    m_firstName = firstName;
    emit firstNameChanged(m_firstName);
}

void CrediteeAccount::setLastName(QString lastName)
{
    if (m_lastName == lastName)
        return;

    m_lastName = lastName;
    emit lastNameChanged(m_lastName);
}

void CrediteeAccount::setMobileNo(QString mobileNo)
{
    if (m_mobileNo == mobileNo)
        return;

    m_mobileNo = mobileNo;
    emit mobileNoChanged(m_mobileNo);
}

void CrediteeAccount::setIdNo(QString idNo)
{
    if (m_idNo == idNo)
        return;

    m_idNo = idNo;
    emit idNoChanged(m_idNo);
}

void CrediteeAccount::setDebtAmount(int debtAmount)
{
    if (m_debtAmount == debtAmount)
        return;

    m_debtAmount = debtAmount;
    emit debtAmountChanged(m_debtAmount);
}
