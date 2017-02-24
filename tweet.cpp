#include "tweet.h"
#include <QJsonObject>

Tweet::Tweet(QObject *parent, QJsonObject obj)  : QObject(parent) {
    _rawTweet = obj;
    _text = obj.value("text").toString();
    _date = obj.value("created_at").toString();
    _retweetCount = obj.value("retweet_count").toInt();
    _favCount = obj.value("favorite_count").toInt();
}

QString Tweet::getText() {
    return _text;
}

QString Tweet::getDate() {
    return _date;
}

int Tweet::getFavoriteCount() {
    return _favCount;
}

int Tweet::getRetweetCount() {
    return _retweetCount;
}
