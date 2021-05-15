#include "mythread.h"
#include <QElapsedTimer>
#include <QDebug>
#include <QThread>

Generate::Generate(QObject *parent) : QObject(parent)
{

}


void Generate::working(int num){
    qDebug()<<"生成随机数的线程的线程地址: "<<QThread::currentThread();
    QVector<int> list;
    QElapsedTimer time;
    time.start();
    for(int i=0;i<num;i++){
        list.push_back(qrand()%100000);
    }
    long long milsec = time.elapsed();
    qDebug()<<"生成"<<num<<"个随机数总共用时："<<milsec<<"毫秒";
    emit sendArray(list);
}

BubbleSort::BubbleSort(QObject *parent) : QObject(parent)
{

}

void BubbleSort::working(QVector<int> list){
    qDebug()<<"冒泡排序的线程的线程地址: "<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    for (int i = 0; i < list.size(); i++){
        for (int j = 0; j < list.size() - 1 - i;j++){
            if(list[j+1]<list[j]){
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
    long long milsec = time.elapsed();
    qDebug()<<"冒泡排序总共用时："<<milsec<<"毫秒";
    emit finish(list);
}


QuickSort::QuickSort(QObject *parent) : QObject(parent)
{

}


void QuickSort::working(QVector<int> list){
    qDebug()<<"快速排序的线程的线程地址: "<<QThread::currentThread();
    QElapsedTimer time;
    time.start();
    quickSort(list, 0, list.size()-1);
    long long milsec = time.elapsed();
    qDebug()<<"快速排序总共用时："<<milsec<<"毫秒";
    emit finish(list);
}

void QuickSort::quickSort(QVector<int> &arr,int l,int r){
    if(l<r){
        int i=l,j=r;
        int x=arr[l];
        while(i<j){
            while(i<j&&arr[j]>=x){
                j--;
            }
            if(i<j){
                arr[i++]=arr[j];
            }
            while(i<j&&arr[i]<x){
                i++;
            }
            if(i<j){
                arr[j--]=arr[i];
            }
        }
        arr[i]=x;
        quickSort(arr,l,i-1);
        quickSort(arr,i+1,r);
    }
}
