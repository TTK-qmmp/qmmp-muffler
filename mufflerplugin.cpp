#include "mufflerplugin.h"

MufflerPlugin::MufflerPlugin()
    : Effect()
{

}

void MufflerPlugin::applyEffect(Buffer *b)
{
    if(channels() != 2)
    {
        return;
    }

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    const QSettings settings;
#else
    const QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    // range limits to (0.0 - 1.0);
    const double ratio = settings.value("Muffler/ratio", DEFAULT_RATIO).toInt() * 1.0 / DEFAULT_RATIO;

    float *data = b->data;
    for(size_t i = 0; i < b->samples; i += 2)
    {
        data[i] -= data[i + 1] * ratio;
        data[i + 1] = data[i];
    }
}
