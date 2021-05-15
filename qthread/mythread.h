#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>

//生成随机数
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

protected:
    void run() override;

signals:
    void sendArray(QVector<int> num);
private:
    int m_num;

public slots:
    void recvNum(int num);
};

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);

protected:
    void run() override;

signals:
    void finish(QVector<int> list);
private:
    QVector<int> m_list;
};

class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
    void recvArray(QVector<int> list);
private:
    void quickSort(QVector<int> &arr,int l,int r);

protected:
    void run() override;

signals:
    void finish(QVector<int> list);
private:
    QVector<int> m_list;
};

#endif // MYTHREAD_H
