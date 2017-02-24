import QtQuick 2.0

Item {
    id: root

    // Set this to blur the mainView when showing something on top of it
    property real blurAmount: 0

    anchors.fill: parent

    Item {
        id: mainViewArea

        anchors.fill: parent

        Rectangle {
            anchors.fill: parent

            Image {
                id: backgroundImage
                anchors.fill: parent
                source: "images/Donald_Trump_official_portrait.jpg"
            }
        }

        Text {
            id: helloText
            text: "Hello Donald!"
            y: 30
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 24; font.bold: true
        }

        Component {
            id: tweetDelegate
            Rectangle {
                id: wrapper
                width: parent.width
                height: 40
                color: "#80FFFFFF"
                Column {
                    Text { text: date }
                    Text { text: '<b>' + twitter_text + '</b> ' }
                }
            }
        }

        ListView {
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.top: helloText.bottom

            model: tweetModel
            delegate: tweetDelegate
        }
    }
}
