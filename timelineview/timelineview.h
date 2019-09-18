#ifndef TIMELINEVIEW_H
#define TIMELINEVIEW_H

#include "application.h"
#include "controller/signalmanager.h"
#include "dbmanager/dbmanager.h"
#include "widgets/thumbnaillistview.h"
#include "widgets/timelinelist.h"
#include "widgets/timelineitem.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <DListWidget>

class Title : public QWidget{
public:
    Title(){};
protected:
    void paintEvent(QPaintEvent *event){

        qDebug() << "x is "<<x();
        qDebug() << "pos.x is "<<pos().x();
    }
    void moveEvent(QMoveEvent *event){
        qDebug() << "moveEvent x is "<<x();
        qDebug() << "moveEvent pos.x is "<<pos().x();
    }

};
class TimeLineView : public QWidget
{
public:
    TimeLineView();
public slots:
    void on_AddLabel(QString date,QString num);
    void on_DelLabel();
    void on_MoveLabel(int y);
protected:
    void resizeEvent(QResizeEvent *ev) override;
private:
    void initUI();
    void initConnections();
    void sigImprotPicsIntoThumbnailView();
    void getImageInfos();
    void updataLayout();
    void initMainStackWidget();


    TimelineList *m_mainListWidget=nullptr;
    QLayout *m_mainLayout=nullptr;
    QList<QString> m_timelines;
    QWidget *m_dateItem=nullptr;
    DPushButton *pSuspensionChose;

    int m_index;
};

#endif // TIMELINEVIEW_H
