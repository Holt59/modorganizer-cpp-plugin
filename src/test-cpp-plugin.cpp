#include <QMessageBox>

#include "test-cpp-plugin.h"
#include "ui/ui_dialog.h"

using namespace MOBase;

HelloWorld::HelloWorld()
{
    // constructor. Please note that this is called before MO is started up completely
    // so you can not do anything that would interface with the main application here.
}

bool HelloWorld::init(IOrganizer* organizer)
{
    // initialize the plugin. This happens after the main application is largely
    // initialized, except for the virtual directory structure. That is loaded in
    // parallel and may take a moment to be complete.

    // usually you will want to save the "organizer" reference to a member variable
    // because this is your gateway to most functions of MO

    // return true if the plugin started correctly. If you return false this will be
    // considered a "problem", but the main application does not do anything about it
    // except for printing a warning.

    // if you want to give more detailed information to the user, print your own warning
    // or - much more convenient for the user - implement the IPluginDiagnose interface.
    return true;
}

QString HelloWorld::name() const
{
    // the "internal" name of your plugin. This is the name under which it will show up
    // in the settings dialog do NOT make this localizable
    return "Hello World";
}

QString HelloWorld::author() const
{
    // your name
    return "Tannin";
}

QString HelloWorld::description() const
{
    // a description of your plugin. This should be short and descriptive
    return tr("Gives a friendly greeting");
}

VersionInfo HelloWorld::version() const
{
    // version of the plugin. Please ensure to update this with every release
    return VersionInfo(1, 2, 3, VersionInfo::RELEASE_FINAL);
}

QList<PluginSetting> HelloWorld::settings() const
{
    // return a list of user-configurable settings for this plugins to be exposed
    // through the settings dialog of MO. you can access the values for these settings
    // through IOrganizer::pluginSetting
    return QList<PluginSetting>();
}

QString HelloWorld::displayName() const
{
    // the name of this tool as displayed in the toolbar
    return tr("Hello World");
}

QString HelloWorld::tooltip() const
{
    // tooltip for the toolbar icon
    return tr("Gives a friendly greeting");
}

QIcon HelloWorld::icon() const
{
    // icon in the toolbar. You should manage this icon (and all other graphics/assets
    // you need) in a resource file that gets included in the dll so you don't have to
    // ship multiple files. Please check the other plugins to see how this works.
    return QIcon(":/MO2/test-cpp-plugin/icon");
}

void HelloWorld::display() const
{
    // display gets called when the user activates your plugin.
    // This is basically the main entry point of your tool plugin.
    // You can always use parentWidget() to refer to the main window.
    QDialog dialog(parentWidget());
    Ui::Dialog ui;
    ui.setupUi(&dialog);
    dialog.exec();
}
