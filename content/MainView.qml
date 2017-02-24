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
                height: tweet_column.height
                color: "#90FFFFFF"
                radius: 5
                border.color: "#900000FF"
                border.width: 2
                Column {
                    id: tweet_column
                    Text { id: date_text; text: date; }
                    Text { id: tweet_text; text: '<b>' + twitter_text + '</b> '; wrapMode: Text.WordWrap; width: wrapper.width}
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: console.log("foo")
                }

                states: State {
                    name: "bigger"; when: mouseArea.containsMouse == true
                    PropertyChanges { target: wrapper; height: tweet_column.height; }
                    PropertyChanges { target: date_text; font.pointSize: 20; }
                    PropertyChanges { target: tweet_text; font.pointSize: 20; }
                }

                transitions: Transition {
                    from: ""; to: "bigger"; reversible: true
                    ParallelAnimation {
                        NumberAnimation { properties: "height, font.pointSize"; duration: 150; easing.type: Easing.InOutQuad }
                    }
                }


            }
        }

        ListView {
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.top: helloText.bottom
            anchors.margins: 50

            spacing: 10

            model: tweetModel
            delegate: tweetDelegate
        }
    }
}
