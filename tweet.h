#pragma once

#include <QObject>
#include <QJsonObject>

class QString;

class Tweet : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString twitter_text READ getText)
    Q_PROPERTY(QString date READ getDate)
    Q_PROPERTY(int favoriteCount READ getFavoriteCount)
    Q_PROPERTY(int retweetCount READ getRetweetCount)

public:
    explicit Tweet(QObject* parent = 0, QJsonObject obj = QJsonObject());

    QString getText();

    QString getDate();

    int getFavoriteCount();

    int getRetweetCount();

private:

    QString _text;
    QString _date;
    int _favCount;
    int _retweetCount;
    QJsonObject _rawTweet;

signals:

public slots:
};
