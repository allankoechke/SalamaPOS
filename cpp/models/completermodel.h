#ifndef COMPLETERMODEL_H
#define COMPLETERMODEL_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractListModel>
#include "src/completer.h"

class CompleterModel : public QAbstractListModel
{
    Q_OBJECT

    enum CompleterModelRoles{
        CompleterNameRole = Qt::UserRole+1,
        CompleterKeyRole
    };

public:
    explicit CompleterModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLES
    Q_INVOKABLE void addCompleterItems(const QVariant &str);

    Q_INVOKABLE void removeCompleterItem(const QVariant &str);

    Q_INVOKABLE int size();

    Q_INVOKABLE QString getKey(int index);

    Q_PROPERTY(int completerSize READ completerSize WRITE setCompleterSize NOTIFY completerSizeChanged)

    // Internals
    int findItemIndex(const QString &str);

    void addItem(Completer * completer);

    void removeItem(int index);

    void clearModel();

    int completerSize() const;

    void setCompleterSize(int completerSize);

signals:
    void logDataChanged(QString level, QString info);
    void completerSizeChanged(int completerSize);

private:
    QList<Completer *> m_completer;

    int m_completerSize;
};

#endif // COMPLETERMODEL_H
