import QtQuick 2.0
import "content"

Rectangle {
    id: page
    width: 320; height: 480
    color: "lightgray"

    Rectangle {
        anchors.fill: parent

        Image {
            id: backgroundImage
            anchors.fill: parent
            source: "content/Donald_Trump_official_portrait.jpg"
        }
    }

    Text {
        id: helloText
        text: "Hello Donald!"
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }

    ListView {
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.top: helloText.bottom

        model: tweetModel
        delegate: Text {
            text: twitter_text + date
        }
    }
}
