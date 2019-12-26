#ifndef ACTIVATORWINDOW_H
#define ACTIVATORWINDOW_H

#include <DMainWindow>
#include <QStackedWidget>
#include <DLabel>
#include <DToolButton>
#include <DSpinner>

DWIDGET_USE_NAMESPACE
class ActivatorWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit ActivatorWindow(QWidget *parent = nullptr);

signals:

public slots:

public:
    void toolButton(DToolButton *dToolBtn, QString btnTxt, QPixmap pixmap, Qt::ToolButtonStyle style, int reduce, int tW, int tH);
    void initHeadMap(QString headTxt, QPixmap pixmapHead);
    void initTitleBar(int idx);
    void initUI();

    QWidget *createMainView();
    QWidget *mainView  = Q_NULLPTR;

    QWidget *createWyqzView();
    QWidget *wyqzView  = Q_NULLPTR;

    QWidget *createBzbrView();
    QWidget *bzbrView  = Q_NULLPTR;

    QWidget *createCopyView();
    QWidget *copyView  = Q_NULLPTR;

    QWidget *createSuccessCopyView();
    QWidget *successCopyView  = Q_NULLPTR;

    QWidget *createZzjlljView();
    QWidget *zzjlljView  = Q_NULLPTR;

    QWidget *createLjsbView();
    QWidget *ljsbView  = Q_NULLPTR;

    QWidget *createLjcgView();
    QWidget *ljcgView  = Q_NULLPTR;

    QWidget *wrapLayout(QLayout *layout);

    int m_lj = 0;

private:
    QStackedWidget *stackMainWindows = Q_NULLPTR;
    DWidget *m_myW = Q_NULLPTR;

    DLabel *m_headlb1 = Q_NULLPTR;
    DLabel *m_headlb2 = Q_NULLPTR;
    DLabel *m_pcMlb1 = Q_NULLPTR;
    DLabel *m_pcMlb2 = Q_NULLPTR;
    DToolButton *m_pcMbtn1 = Q_NULLPTR;
    DToolButton *m_pcMbtn2 = Q_NULLPTR;

    DSpinner *m_pSpinner = Q_NULLPTR;
    QTimer *myTimer;
    QTimer *timerUpdate;
};

#endif // ACTIVATORWINDOW_H
