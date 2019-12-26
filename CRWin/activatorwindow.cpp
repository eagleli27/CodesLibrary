#include "activatorwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <DLabel>
#include <DSuggestButton>
#include <DTextEdit>
#include <DLineEdit>
#include <QTimer>
#include <QTime>
#include <QClipboard>
#include <QApplication>
#include <DPalette>
#include <DTitlebar>
#include <QDebug>

ActivatorWindow::ActivatorWindow(QWidget *parent) : DMainWindow(parent)
{
    m_pcMbtn1 = new DToolButton(this);
    m_pcMbtn2 = new DToolButton(this);
    QPixmap mapWyqz = QPixmap(":/images/main.png");
    QPixmap mapBzbr = QPixmap(":/images/engagement-ring.png");
    toolButton(m_pcMbtn1, "我要求助", mapWyqz, Qt::ToolButtonTextBesideIcon, 6, 140, 10);
    toolButton(m_pcMbtn2, "帮助别人", mapBzbr, Qt::ToolButtonTextBesideIcon, 10, 140, 10);

    myTimer = new QTimer(this);
    timerUpdate = new QTimer(this);
    initUI();
}

QWidget *ActivatorWindow::wrapLayout(QLayout *layout)
{
    auto wrapWidget = new QWidget;
    wrapWidget->setLayout(layout);
    return wrapWidget;
}

void ActivatorWindow::toolButton(DToolButton *dToolBtn, QString btnTxt, QPixmap pixmap, Qt::ToolButtonStyle style, int reduce, int tW, int tH)
{
    QSize sz = pixmap.size() / reduce;
    dToolBtn->setText(btnTxt);
    dToolBtn->setIcon(pixmap);
    dToolBtn->setIconSize(sz);
    dToolBtn->setToolButtonStyle(style);
    dToolBtn->setFixedSize(sz.width() + tW, sz.height() + tH);
}

void ActivatorWindow::initHeadMap(QString headTxt, QPixmap pixmapHead)
{
    QHBoxLayout *headLayout = new QHBoxLayout(m_myW);
    m_headlb1 = new DLabel;
    m_headlb1->setAttribute(Qt::WA_TranslucentBackground);
    m_headlb1->setAlignment(Qt::AlignCenter);
    QPixmap fitpixmap = pixmapHead.scaled(m_headlb1->width() / 20, m_headlb1->height() / 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    m_headlb1->setPixmap(fitpixmap);

    m_headlb2 = new DLabel;
    m_headlb2->setText(headTxt);
    QFont serifFont("Times", 12, QFont::Bold);
    m_headlb2->setFont(serifFont);
    m_headlb2->setAlignment(Qt::AlignCenter);
    m_headlb2->setAttribute(Qt::WA_TranslucentBackground);

    if ("远程协助" == headTxt) {
        headLayout->addSpacing(120);
        headLayout->addWidget(m_headlb2);
        headLayout->addSpacing(-8);
    } else {
        headLayout->addSpacing(120);
        headLayout->addWidget(m_headlb1);
        headLayout->addSpacing(-8);
        headLayout->addWidget(m_headlb2);
        headLayout->addSpacing(-8);
    }

}

void ActivatorWindow::initTitleBar(int idx)
{
    QString biao;
    DTitlebar *titlebar = this->titlebar();
    QPixmap pix;

    if (titlebar) {
        titlebar->setFixedHeight(50);

        if (idx == 0) {
            biao = "远程协助";
        } else if (idx == 1) {
            biao = "我要求助";
            pix = QPixmap(":/images/main.png");
        } else if (idx == 2) {
            biao = "帮助别人";
            pix = QPixmap(":/images/engagement-ring.png");
        } else if (idx == 3) {
            biao = "我要求助";
            pix = QPixmap(":/images/main.png");
        } else if (idx == 4) {
            biao = "我要求助";
            pix = QPixmap(":/images/main.png");
        } else if (idx == 5) {
            biao = "帮助别人";
            pix = QPixmap(":/images/engagement-ring.png");
        } else if (idx == 6) {
            biao = "帮助别人";
            pix = QPixmap(":/images/engagement-ring.png");
        } else {
            biao = "我要求助";
            pix = QPixmap(":/images/main.png");
        }

        m_myW = new DWidget;
        initHeadMap(biao, pix);
        titlebar->setCustomWidget(m_myW);
    }
}

void ActivatorWindow::initUI()
{
    stackMainWindows = new QStackedWidget;

    mainView = createMainView();
    stackMainWindows->addWidget(mainView);

    wyqzView = createWyqzView();
    stackMainWindows->addWidget(wyqzView);

    bzbrView = createBzbrView();
    stackMainWindows->addWidget(bzbrView);

    copyView = createCopyView();
    stackMainWindows->addWidget(copyView);

    successCopyView = createSuccessCopyView();
    stackMainWindows->addWidget(successCopyView);

    zzjlljView = createZzjlljView();
    stackMainWindows->addWidget(zzjlljView);

    ljsbView = createLjsbView();
    stackMainWindows->addWidget(ljsbView);

    ljcgView  = createLjcgView();
    stackMainWindows->addWidget(ljcgView);

    stackMainWindows->setCurrentWidget(mainView);
    setCentralWidget(stackMainWindows);
}

QWidget *ActivatorWindow::createMainView()
{
    initTitleBar(0);
    auto centralLayout = new QVBoxLayout;
    m_pcMlb1 = new DLabel;
    m_pcMlb1->setAttribute(Qt::WA_TranslucentBackground);
    m_pcMlb1->setAlignment(Qt::AlignCenter);
    QPixmap pixmapHead(":/images/rice-cooker.png");
    QPixmap fitpixmap = pixmapHead.scaled(m_pcMlb1->width() / 10, m_pcMlb1->height() / 10, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    m_pcMlb1->setPixmap(fitpixmap);


    m_pcMlb2 = new DLabel;
    m_pcMlb2->setText("这是由deepin团队开发的远程协助应用，如果您在使\n用的过程中遇到了困难，或者有人求助于你，请点击\n下方的我要求助或帮助别人。");
    QFont serifFont("Times", 8, QFont::Normal);
    m_pcMlb2->setFont(serifFont);
    m_pcMlb2->setAlignment(Qt::AlignCenter);
    m_pcMlb2->setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout *vl1 = new QVBoxLayout;
    vl1->addSpacing(10);
    vl1->addWidget(m_pcMlb1);
    vl1->addWidget(m_pcMlb2);
    vl1->addWidget(m_pcMbtn1, 0, Qt::AlignCenter);
    vl1->addSpacing(-20);
    vl1->addWidget(m_pcMbtn2, 0, Qt::AlignCenter);
    vl1->addSpacing(10);
    centralLayout->addLayout(vl1);

    connect(m_pcMbtn1, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(1);
        stackMainWindows->setCurrentWidget(wyqzView);
        myTimer->start(2000);
        connect(myTimer, &QTimer::timeout, [ = ]() {
            stackMainWindows->setCurrentWidget(copyView);
            myTimer->stop();
        });
    });

    connect(m_pcMbtn2, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(2);
        stackMainWindows->setCurrentWidget(bzbrView);
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createWyqzView()
{
    auto centralLayout = new QVBoxLayout;

    m_pSpinner = new DSpinner(this);
    m_pSpinner->setFixedSize(32, 32);
    m_pSpinner->start();

    DLabel *lb = new DLabel;
    lb->setText("正在生成请求验证码，请稍后...");
    QFont serifFont("Times", 12, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("取  消");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(m_pSpinner, 0, Qt::AlignCenter);
    vl->addSpacing(-30);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(0);
        stackMainWindows->setCurrentWidget(mainView);
        myTimer->stop();
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createBzbrView()
{
    auto centralLayout = new QVBoxLayout;

    DLineEdit *tE = new DLineEdit;
    tE->setFixedSize(320, 60);
    QFont srifFont("Times", 30, QFont::Normal);
    srifFont.setLetterSpacing(QFont::PercentageSpacing, 160);
    tE->setFont(srifFont);
//    tE->setAlignment(Qt::AlignCenter);
//    tE->setMaxLength(6);

    DLabel *lb = new DLabel;
    lb->setText("请在上方输入你想帮助的人提供给你的验证码，完成后点击连接\n开始协助对方");
    QFont serifFont("Times", 9, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("取  消");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(tE, 0, Qt::AlignCenter);
    vl->addSpacing(-10);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        QString strBtn = btn->text();
        if (strBtn == "取  消") {
            initTitleBar(0);
            stackMainWindows->setCurrentWidget(mainView);
        } else {
            stackMainWindows->setCurrentWidget(zzjlljView);
            myTimer->start(5000);
            connect(myTimer, &QTimer::timeout, [ = ]() {
                if (m_lj == 0) {
                    initTitleBar(6);
                    stackMainWindows->setCurrentWidget(ljsbView);
                } else {
                    initTitleBar(7);
                    stackMainWindows->setCurrentWidget(ljcgView);
                }

                myTimer->stop();
            });
        }
    });

    connect(tE, &DLineEdit::textChanged, [ = ]() {
        QString ss = tE->text();
        int nl = ss.length();
        if (nl == 0) {
            btn->setText("取  消");
        } else {
            btn->setText("连  接");
        }
        if (nl > 6) {
            tE->setText(ss.mid(0, ss.length()-1));
        }
        bool bOk = false;
        ss.toInt(&bOk);
        if (!bOk) {
            tE->setText(ss.mid(0, ss.length() - 1));
        }
        btn->setText("连  接");
    });


    QClipboard *board = QApplication::clipboard();

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        QString str = board->text();
        QString ss = tE->text();

        if (str == ss) {
            m_lj = 1;
        } else {
            m_lj = 0;
        }
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createCopyView()
{
    auto centralLayout = new QVBoxLayout;

    DTextEdit *tE = new DTextEdit;
    tE->setFixedSize(320, 80);

    DLabel *lb = new DLabel;
    lb->setText("要开始共享您的桌面，请将上面的验证码提供给协助您的人员，\n他们输入验证码后，您的共享会话立即开始");
    QFont serifFont("Times", 9, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("复  制");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(tE);
    vl->addSpacing(-20);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    QString sSjs;
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    for (int i = 0; i < 6; i++) {
        int intNumber = qrand() % 10;
        sSjs += QString::number(intNumber, 10);
    }

    tE->setText(sSjs);
    QFont srifFont("Times", 30, QFont::Normal);
    srifFont.setLetterSpacing(QFont::PercentageSpacing, 160);
    tE->setFont(srifFont);
    tE->setAlignment(Qt::AlignCenter);
    tE->setEnabled(false);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        QClipboard *clipboard = QApplication::clipboard(); //获取系统剪贴板指针
        QString originalText = clipboard->text();//获取剪贴板上文本信息
        clipboard->setText(sSjs);//设置剪贴板内容
        stackMainWindows->setCurrentWidget(successCopyView);
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createSuccessCopyView()
{
    auto centralLayout = new QVBoxLayout;

    DTextEdit *tE = new DTextEdit;
    tE->setFixedSize(320, 60);

    DLabel *lb = new DLabel;
    lb->setText("正在等待连接，请稍后...\n连接成功后，此界面会自动隐藏到任务栏");
    QFont serifFont("Times", 9, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("返  回");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(32);
    vl->addWidget(tE);
    vl->addSpacing(-20);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    tE->setText("    成 功 复 制 到 粘 贴 板");
    QFont srifFont("Times", 17, QFont::Normal);
    tE->setFont(srifFont);
    tE->setAlignment(Qt::AlignCenter);
    tE->setEnabled(false);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(0);
        stackMainWindows->setCurrentWidget(mainView);
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createZzjlljView()
{
    auto centralLayout = new QVBoxLayout;

    m_pSpinner = new DSpinner(this);
    m_pSpinner->setFixedSize(32, 32);
    m_pSpinner->start();

    DLabel *lb = new DLabel;
    lb->setText("正在建立连接，请稍后...");
    QFont serifFont("Times", 12, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("取  消");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(m_pSpinner, 0, Qt::AlignCenter);
    vl->addSpacing(-30);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(2);
        stackMainWindows->setCurrentWidget(bzbrView);
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createLjsbView()
{
    auto centralLayout = new QVBoxLayout;

    DPalette pe;
    pe.setColor(DPalette::WindowText, QColor("#FC9F41")); //#FC9F41  252,159,65
    DLabel *lb0 = new DLabel;
    lb0->setPalette(pe);
    lb0->setText("连 接 失 败");
    QFont sbFont("Times", 16, QFont::Normal);
    lb0->setFont(sbFont);
    lb0->setAlignment(Qt::AlignCenter);
    lb0->setAttribute(Qt::WA_TranslucentBackground);

    DLabel *lb = new DLabel;
    lb->setText("网络连接状态不是很稳定，点击重试按钮再次尝试连接");
    QFont serifFont("Times", 9, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("重  试");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(lb0, 0, Qt::AlignCenter);
    vl->addSpacing(-30);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        stackMainWindows->setCurrentWidget(bzbrView);
    });

    return  wrapLayout(centralLayout);
}

QWidget *ActivatorWindow::createLjcgView()
{
    auto centralLayout = new QVBoxLayout;

    DLabel *lb0 = new DLabel;
    lb0->setText("您 正 在 进 行 远 程 协 助");
    QFont sbFont("Times", 16, QFont::Bold);
    lb0->setFont(sbFont);
    lb0->setAlignment(Qt::AlignCenter);
    lb0->setAttribute(Qt::WA_TranslucentBackground);

    DLabel *lb = new DLabel;
    lb->setText("当前已经有一个连接会话，如果您想建立新的连接，请先断开");
    QFont serifFont("Times", 9, QFont::Normal);
    lb->setFont(serifFont);
    lb->setAlignment(Qt::AlignCenter);
    lb->setAttribute(Qt::WA_TranslucentBackground);

    DSuggestButton *btn = new DSuggestButton;
    btn->setText("断  开");
    btn->setFixedSize(180, 40);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addSpacing(22);
    vl->addWidget(lb0, 0, Qt::AlignCenter);
    vl->addSpacing(-30);
    vl->addWidget(lb);
    vl->addWidget(btn, 0, Qt::AlignCenter);
    vl->addSpacing(15);

    centralLayout->addLayout(vl);

    connect(btn, &DSuggestButton::clicked, [ = ]() {
        initTitleBar(0);
        stackMainWindows->setCurrentWidget(mainView);
    });

    return  wrapLayout(centralLayout);
}
