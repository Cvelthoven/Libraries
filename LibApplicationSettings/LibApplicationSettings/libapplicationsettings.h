#ifndef LIBAPPLICATIONSETTINGS_H
#define LIBAPPLICATIONSETTINGS_H

#include "LibApplicationSettings_global.h"

#include <QString>

class LIBAPPLICATIONSETTINGS_EXPORT LibApplicationSettings
{
public:
    LibApplicationSettings();
    LibApplicationSettings(const QString &strOrganization,
                           const QString &strDomain,
                           const QString &strApplication);
    QString GetAppSetting(const QString &strSection,
                          const QString &strSettingName);
    void SetAppSetting(const QString &strSection,
                       const QString &strSettingName,
                       const QString &strSettingValue);
    void SetAppEnvironment(const QString &strOrganization,
                           const QString &strDomain,
                           const QString &strApplication);

private:
    QString strFullKeyPath;
};

#endif // LIBAPPLICATIONSETTINGS_H
