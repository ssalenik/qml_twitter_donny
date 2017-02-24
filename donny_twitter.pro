TEMPLATE = app

QT += qml quick
SOURCES += main.cpp \
    tweet.cpp

target.path = /opt/donny_twitter
qml.files = donny_twitter.qml content
qml.path = /opt/donny_twitter
INSTALLS += target qml

HEADERS += \
    tweet.h

DISTFILES += \
    donny.json
