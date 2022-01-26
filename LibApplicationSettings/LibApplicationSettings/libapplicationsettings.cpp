//-----------------------------------------------------------------------------
//
//  Library LibApplicationSettings
//
//  Class to retrieve, change and store application configuration settings
//
//-----------------------------------------------------------------------------
//
//  Required include files
#include "libapplicationsettings.h"
#include <QCoreApplication>
#include <QSettings>
#include <QString>

//-----------------------------------------------------------------------------
//  Development include file
//#include <QDebug>

//-----------------------------------------------------------------------------
//
//  Constructors
//
//-----------------------------------------------------------------------------
//
//  Default contructor
//
//-----------------------------------------------------------------------------
LibApplicationSettings::LibApplicationSettings()
{
}

//-----------------------------------------------------------------------------
//
//  LibApplicationSettings
//
//  Set the application environment
//
//  Input:
//  - strOrganization: Organization name
//  - strDomain:       Domain name
//  - strApplication:  Application name
//
//-----------------------------------------------------------------------------

LibApplicationSettings::LibApplicationSettings(const QString &strOrganization,
                                               const QString &strDomain,
                                               const QString &strApplication)
{
    //-------------------------------------------------------------------------
    //
    //  Set application environment definitions
    SetAppEnvironment(strOrganization, strDomain, strApplication);
}

//-----------------------------------------------------------------------------
//
//  Public methodes
//
//-----------------------------------------------------------------------------
//
//  GetAppSettings
//
//  Retieve the value of a application configuration setting
//
//  Input:
//  - strSection:     section name in the configuration
//  - strSettingName: setting name in the configuration
//
//  Output:
//  - GetAppSettings:
//      - value found when defined
//      - empty string when not found
//
//-----------------------------------------------------------------------------
QString LibApplicationSettings::GetAppSetting(const QString &strSection,
                                              const QString &strSettingName)
{
//    qDebug() << "LibApplicationSettings GetAppSetting called with:";
//    qDebug() << "strSection: " << strSection;
//    qDebug() << "strSettingName: " << strSettingName;

    QSettings programDefault;

    //-------------------------------------------------------------------------
    //
    //  Build path
    if (strSection.size() != 0)
        strFullKeyPath = strSection + "//" + strSettingName;
    else
        strFullKeyPath = strSettingName;

    //-------------------------------------------------------------------------
    //
    //  Retrieve value
    QVariant temp = programDefault.value(strFullKeyPath);
    if (temp.isValid())
    {
        QString strSettingValue = temp.toString();
        return strSettingValue;
    }

    return "";

}

//-----------------------------------------------------------------------------
//
//  SetAppSettings
//
//  Retieve the value of a application configuration setting
//
//  Input:
//  - strSection:      section name in the configuration
//  - strSettingName:  setting name in the configuration
//  - strSettingValue: value of the setting int the configuration
//
//-----------------------------------------------------------------------------
void LibApplicationSettings::SetAppSetting(const QString &strSection,
                                           const QString &strSettingName,
                                           const QString &strSettingValue)
{
//    qDebug() << "LibApplicationSettings SetAppSetting called with:";
//    qDebug() << "strSection: " << strSection;
//    qDebug() << "strSettingName: " << strSettingName;
//    qDebug() << "strSettingValue: " << strSettingValue;

    QSettings programDefault;

    //-------------------------------------------------------------------------
    //
    //  Build path
    if (strSection.size() > 0)
        strFullKeyPath = strSection + "//" + strSettingName;
    else
        strFullKeyPath = strSettingName;

    //-------------------------------------------------------------------------
    //
    //  Set value
    programDefault.setValue(strFullKeyPath,strSettingValue);

}

//-----------------------------------------------------------------------------
//
//  SetAppEnvironment
//
//  Set the application environment
//
//  Input:
//  - strOrganization: Organization name
//  - strDomain:       Domain name
//  - strApplication:  Application name
//
//-----------------------------------------------------------------------------
void LibApplicationSettings::SetAppEnvironment(const QString &strOrganization,
                                               const QString &strDomain,
                                               const QString &strApplication)
{
    //-------------------------------------------------------------------------
    //
    //  Set application environment definitions
    if (strOrganization.size() > 0)
        QCoreApplication::setOrganizationName(strOrganization);
    if (strDomain.size() > 0)
        QCoreApplication::setOrganizationDomain(strDomain);
    if (strApplication.size() > 0)
        QCoreApplication::setApplicationName(strApplication);

}
