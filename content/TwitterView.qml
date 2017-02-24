import QtQuick 2.0

Item {
    id: root

    property bool isShown: true

    anchors.fill: parent

    QtObject {
        id: priv
        property bool poleOut: false
        // How curly the curtain is when opened
        property int endCurly: 80
        // 0 = pole in, 1 = pole out
        property real polePosition: 0
        property bool showingStarted: false
    }

    onIsShownChanged: {
        if (root.isShown) {
            mainView.scheduleUpdate();
        }
    }

    Binding {
        target: mainView
        property: "blurAmount"
        value: 40 * priv.polePosition
        when: root.isShown
    }
    MouseArea {
        anchors.fill: parent
        enabled: root.isShown
        onClicked: {
            root.hide();
        }
    }

    BorderImage {
        anchors.right: parent.right
        anchors.top: parent.top
        border.left: 22
        border.right: 64
        border.top: 0
        border.bottom: 0
        width: 86 + priv.polePosition * (viewItem.width-88)
        z: 20
        source: "images/button-twitter.png"
        opacity: 0.5 + priv.polePosition
        MouseArea {
            anchors.fill: parent
            anchors.margins: -20
            onClicked: {
                // TODO
            }
        }
    }
}
