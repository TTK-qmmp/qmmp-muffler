#include "effectmufflerfactory.h"
#include "mufflerplugin.h"

#include <QMessageBox>

const EffectProperties EffectMufflerFactory::properties() const
{
    EffectProperties properties;
    properties.name = tr("Voice Removal Plugin");
    properties.shortName = "muffler";
    properties.hasAbout = true;
    return properties;
}

Effect *EffectMufflerFactory::create()
{
    return new MufflerPlugin();
}

void EffectMufflerFactory::showSettings(QWidget *parent)
{
   Q_UNUSED(parent);
}

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
