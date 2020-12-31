#ifndef CREDITEEACCOUNT_H
#define CREDITEEACCOUNT_H

#include <QObject>

class CrediteeAccount : public QObject
{
    Q_OBJECT

public:
    explicit CrediteeAccount(QObject *parent = nullptr);

    CrediteeAccount(const QString &firstName, const QString &lastName, const QString &mobileNo, const QString &idNo, const int &debtAmount, QObject *parent = nullptr);

    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(QString mobileNo READ mobileNo WRITE setMobileNo NOTIFY mobileNoChanged)
    Q_PROPERTY(QString idNo READ idNo WRITE setIdNo NOTIFY idNoChanged)
    Q_PROPERTY(int debtAmount READ debtAmount WRITE setDebtAmount NOTIFY debtAmountChanged)

    QString firstName() const;

    QString lastName() const;

    QString mobileNo() const;

    QString idNo() const;

    int debtAmount() const;

public slots:
    void setFirstName(QString firstName);

    void setLastName(QString lastName);

    void setMobileNo(QString mobileNo);

    void setIdNo(QString idNo);

    void setDebtAmount(int debtAmount);

signals:

    void firstNameChanged(QString firstName);
    void lastNameChanged(QString lastName);
    void mobileNoChanged(QString mobileNo);
    void idNoChanged(QString idNo);
    void debtAmountChanged(int debtAmount);

private:
    QString m_firstName;

    QString m_lastName;

    QString m_mobileNo;

    QString m_idNo;

    int m_debtAmount;
};

#endif // CREDITEEACCOUNT_H
