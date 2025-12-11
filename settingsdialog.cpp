#include "settingsdialog.h"
#include "mufflerplugin.h"

#include <QAbstractButton>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    m_ui.setupUi(this);
#ifdef Q_OS_UNIX
    for(QAbstractButton *button : m_ui.buttonBox->buttons())
    {
        button->setFocusPolicy(Qt::NoFocus);
    }
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    const QSettings settings;
#else
    const QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    m_ui.ratioSlider->setValue(settings.value("Muffler/ratio", DEFAULT_RATIO).toInt());
}

void SettingsDialog::accept()
{
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    QSettings settings;
#else
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
#endif
    settings.setValue("Muffler/ratio", m_ui.ratioSlider->value());
    QDialog::accept();
}

void SettingsDialog::on_ratioSlider_valueChanged(int value)
{
    m_ui.ratioLabel->setText(QString::number(value * 1.0 / DEFAULT_RATIO, 'f', 2));
}
