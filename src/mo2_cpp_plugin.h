#pragma once

#include <uibase/iplugintool.h>

class MO2CppPlugin : public MOBase::IPluginTool
{
  Q_OBJECT
  Q_INTERFACES(MOBase::IPlugin MOBase::IPluginTool)
  Q_PLUGIN_METADATA(IID "org.ModOrganizer2.MO2CppPlugin")

public:
  MO2CppPlugin();

  bool init(MOBase::IOrganizer* moInfo) override;
  QString name() const override;
  QString localizedName() const override;
  QString author() const override;
  QString description() const override;
  MOBase::VersionInfo version() const override;
  QList<MOBase::PluginSetting> settings() const override;

  QString displayName() const override;
  QString tooltip() const override;
  QIcon icon() const override;

public slots:
  void display() const override;

private:
  const MOBase::IOrganizer* organizer_;
};
