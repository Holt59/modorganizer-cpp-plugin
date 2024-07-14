#include "mo2_cpp_plugin.h"

#include <QMessageBox>

MO2CppPlugin::MO2CppPlugin() {}

bool MO2CppPlugin::init(MOBase::IOrganizer* moInfo)
{
  organizer_ = moInfo;
  return true;
}

QString MO2CppPlugin::name() const
{
  return "MO2 C++ Plugin";
}

QString MO2CppPlugin::localizedName() const
{
  return tr("MO2 C++ Plugin");
}

QString MO2CppPlugin::author() const
{
  return "Holt59";
}

QString MO2CppPlugin::description() const
{
  return tr("Demo C++ Plugin for MO2");
}

MOBase::VersionInfo MO2CppPlugin::version() const
{
  return MOBase::VersionInfo(1, 0, 0);
}

QList<MOBase::PluginSetting> MO2CppPlugin::settings() const
{
  return {};
}

QString MO2CppPlugin::displayName() const
{
  return tr("MO2 C++ Plugin");
}

QString MO2CppPlugin::tooltip() const
{
  return tr("Click Me!");
}

QIcon MO2CppPlugin::icon() const
{
  return QIcon();
}

void MO2CppPlugin::display() const
{
  QMessageBox::information(
      nullptr, "MO2 C++ Plugin",
      QString("Hello, I am %1, version %2, working within ModOrganizer2 %3.")
          .arg(localizedName())
          .arg(version().canonicalString())
          .arg(organizer_->appVersion().canonicalString()));
}
