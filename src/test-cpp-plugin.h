#ifndef TEST_CPP_PLUGIN_H
#define TEST_CPP_PLUGIN_H

#include <iplugintool.h>

class HelloWorld : public MOBase::IPluginTool {
    // need to call Q_OBJECT macro. This is required for the Qt moc preprocessor
    // and will cause ugly compiler errors if missing
    Q_OBJECT

    // List all interfaces being implemented. Again: hard to diagnose if missing
    Q_INTERFACES(MOBase::IPlugin MOBase::IPluginTool)

    // compiled Qt plugins require an id and json file for meta information
    Q_PLUGIN_METADATA(IID "org.mo2.HelloWorld")

public:
    HelloWorld();

    // IPlugin interface

    bool init(MOBase::IOrganizer* moInfo) override;
    QString name() const override;
    QString author() const override;
    QString description() const override;
    MOBase::VersionInfo version() const override;
    QList<MOBase::PluginSetting> settings() const override;

    // IPluginTool interface

    QString displayName() const override;
    QString tooltip() const override;
    QIcon icon() const override;

public slots:
    void display() const override;
};

#endif
