#include "effectmufflerfactory.h"
#include "mufflerplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectMufflerFactory::properties() const
#else
EffectProperties EffectMufflerFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Voice Removal Plugin");
    properties.shortName = "muffler";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectMufflerFactory::create()
{
    return new MufflerPlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectMufflerFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectMufflerFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectMufflerFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Voice Removal Effect Plugin"),
                        tr("Qmmp Voice Removal Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectMufflerFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(muffler, EffectMufflerFactory)
#endif
