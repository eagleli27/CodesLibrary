#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include "activatorwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("dtk application");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a dtk template application.");

    ActivatorWindow  *activatorWindow = new ActivatorWindow;
    activatorWindow->setFixedSize(360,320);
    activatorWindow->show();

    Dtk::Widget::moveToCenter(activatorWindow);
    return a.exec();
}
