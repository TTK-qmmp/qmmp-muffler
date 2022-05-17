include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/muffler

HEADERS += mufflerplugin.h \
           effectmufflerfactory.h

SOURCES += mufflerplugin.cpp \
           effectmufflerfactory.cpp

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
