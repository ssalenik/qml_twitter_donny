import QtQuick 2.0

Rectangle {
    id: page
    width: 320; height: 480
    color: "lightgray"

    Text {
        id: helloText
        text: "Hello Donald!"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }

    ListView {
        anchors.fill: parent

        model: tweetModel
        delegate: Text {
            text: twitter_text + date
        }
    }
}
